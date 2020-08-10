__global__ void index_print_kernel() {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int warp_idx = threadIdx.x / warpSize; 
    int lane_idx = threadIdx.x & (warpSize 1); 
    if ((lane_idx & (warpSize/2-1)) == 0){
         //thread, block, warp, lane 
        printf(" %5d\t%5d\t %2d\t%2d\n", idx, blockIdx.x, warp_idx, lane_idx); 
    }
} 
int main() { 
    int gridDim = 4, blockDim = 128;
    puts("thread, block, warp, lane");
    index_print_kernel<<< gridDim, blockDim >>>(); 
    cudaDeviceSynchronize(); 
    return 0;
} 

//nvcc m64 o cuda_thread_block cuda_thread_block.cu (Kindle Location 1629). 


