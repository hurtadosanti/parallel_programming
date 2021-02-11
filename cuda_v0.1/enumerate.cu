#include <stdio.h>

/**
 * Simple cuda program to show how to uniquely identify all the treads 
 */
__global__ void enumerate() {
    int count = blockIdx.x * blockDim.x + threadIdx.x;
    printf("(%d * %d + %d )=%d\n", blockIdx.x, blockDim.x, threadIdx.x, count);
}

int main(void) {
    enumerate << < 4, 2 >> > ();
    cudaDeviceSynchronize();
    return 0;
}
