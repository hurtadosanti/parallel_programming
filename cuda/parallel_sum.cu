#include <stdio.h>
#include <time.h>

__device__ bool is_prime(unsigned int &num) {
    if (num == 2) {
        return true;
    }
    if (num < 2 || num % 2 == 0) {
        return false;
    } else {
        for (int i = 2; i < num / 2; i++) {
            if (num % i == 0) {
                return false;
            }
        }
    }
    return true;
}


__global__ void calculate_primes(unsigned int *result) {
    unsigned int count = blockIdx.x * blockDim.x + threadIdx.x;
    bool prime = is_prime(count);
    if (prime) {
        result[count] = count;
    } else {
        result[count] = 0;
    }
}

/**
 * Calculate the sum of primes
 */
int main(void) {
    clock_t start,end;
    double sum = 0;
    int blocks = 10;
    int threads = 10;
    unsigned int *result;
    unsigned int *primes = (unsigned int *) malloc(sizeof(unsigned int) * blocks * threads);

    cudaMalloc((void **) &result, blocks * threads * sizeof(int));
    start=clock();
    calculate_primes << < blocks, threads >> > (result);
    cudaMemcpy(primes, result, blocks * threads * sizeof(unsigned int), cudaMemcpyDeviceToHost);
    cudaDeviceSynchronize();
    end=clock();
    printf("device done\n");

    for (int i = 0; i < blocks * threads; i++) {
        sum += primes[i];
    }
    printf("Total: %f in %d seconds \n", sum,(double) (end-start)/CLOCKS_PER_SEC);

    cudaFree(result);
    free(primes);
    return 0;
}
