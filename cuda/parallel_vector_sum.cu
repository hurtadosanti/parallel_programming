#include <stdio.h>

static const int BLOCKS = 1024;
static const int THREADS = 1024;

__global__ void vector_sum(unsigned int *a,unsigned int *b,unsigned int *result){
	unsigned int tid = blockIdx.x*blockDim.x+threadIdx.x;
	if(tid<BLOCKS*THREADS){
		result[tid]=a[tid]+b[tid];
	}

}

int main(int argc, char **argv)
{
	int N = BLOCKS*THREADS;

	unsigned int *a = (unsigned int*)malloc(sizeof(unsigned int)*N);
	unsigned int *b = (unsigned int*)malloc(sizeof(unsigned int)*N);
	unsigned int *result = (unsigned int*)malloc(sizeof(unsigned int)*N);

	unsigned int *d_a, *d_b, *d_result;

	cudaMalloc( (void**)&d_a, N * sizeof(unsigned int));
	cudaMalloc( (void**)&d_b, N * sizeof(unsigned int));
	cudaMalloc( (void**)&d_result, N * sizeof(unsigned int));

	for (int i=0; i<N; i++){
		a[i] = i;
		b[i] = i*i;
	}

	cudaMemcpy( d_a, a, N * sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy( d_b, b, N * sizeof(int),cudaMemcpyHostToDevice);

	vector_sum<<<BLOCKS,THREADS>>>(d_a,d_b,d_result);
	cudaMemcpy(result, d_result, N * sizeof(unsigned int),cudaMemcpyDeviceToHost);
	printf("Device done\n");
	double total = 0;
	for (int i=0; i<N; i++) {
		total+=result[i];
	}
	printf( "%f\n",total);
	cudaFree( d_a );
	cudaFree( d_b );
	cudaFree( d_result );
	return 0;
}
