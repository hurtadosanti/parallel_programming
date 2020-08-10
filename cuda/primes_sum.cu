#include <vector>
#include <stdio.h>

__device__
bool is_prime(unsigned int number) {
    if (number == 2) {
        return true;
    } else if (number < 2 || number % 2 == 0) {
        return false;
    } else {
        // A faster option is to use math sqr root
        for (int i = 2; i < number / 2; ++i) {
            if (number % i == 0) {
                return false;
            }
        }
    }
    return true;
}

__global__ 
void calculate_primes(unsigned int* result, int size){
    auto count = blockIdx.x * blockDim.x + threadIdx.x;
    if(count<size){
        if(is_prime(count)){
            result[count]=count;
        }else{
            result[count]=0;
        }
    }
}
int main(){
    std::vector<unsigned int> result;
    double sum=0;
    int size = 1024*128;
    unsigned int *d_result;
    auto h_result = new unsigned int[size];
    cudaMalloc((void**)&d_result,size* sizeof(unsigned int));
    calculate_primes<<<(size+1023)/1024,1024>>>(d_result,size);
    cudaMemcpy(h_result,d_result,size* sizeof(unsigned int),cudaMemcpyDeviceToHost);
    for(auto i=0;i<size;i++){
        auto value = h_result[i];
        if(value>0){
            result.push_back(value);
            sum+=value;
        }
    }
    cudaFree(d_result);
    delete [] h_result;
    printf("%f for %d\n",sum,size);
    return 0;
}