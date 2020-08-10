//
// Created by Santiago Hurtado on 18.10.19.
//
#include "parallel/Vectors.h"
#include <stdio.h>

__global__ void kernel(unsigned int* a,unsigned int* b,unsigned int* result, int size) {
    auto count = blockIdx.x * blockDim.x + threadIdx.x;
    if(count<size){
        result[count]=a[count]+b[count];
    }
}

namespace parallel{
    void Vectors::sum_size(size_t size) {
        this->result.clear();
        auto mem_size = sizeof(unsigned int)*size;
        // Host memory management
        auto h_a = new unsigned int[size];
        auto h_b = new unsigned int[size];
        auto result = new unsigned int[size];
        for(auto i =0;i<size;++i){
            h_a[i]=i;
            h_b[i]=i*i;
        }
        // Device memory management
        unsigned int *d_a;
        unsigned int *d_b;
        unsigned int *d_result;

        cudaMalloc(&d_a,mem_size);
        cudaMalloc(&d_b,mem_size);
        cudaMalloc(&d_result,mem_size);

        cudaMemcpy(d_a, h_a, mem_size, cudaMemcpyHostToDevice);
        cudaMemcpy(d_b, h_b, mem_size, cudaMemcpyHostToDevice);

        kernel<<<(size+1023)/1024,1024>>>(d_a,d_b,d_result,size);
        cudaMemcpy(result,d_result,mem_size,cudaMemcpyDeviceToHost);

        cudaDeviceSynchronize();
        for(auto i=0;i<size;++i){
            this->result.push_back(result[i]);
        }
        cudaFree(d_a);
        cudaFree(d_b);
        cudaFree(d_result);

        delete [] h_a;
        delete [] h_b;
        delete [] result;
    }

    void Vectors::sum(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b) {
        this->result.clear();
        if(a.empty()||b.empty()||a.size()!=b.size()){
            return;
        }
        auto size = a.size();
        auto mem_size = sizeof(unsigned int)*size;

        // Host memory management
        auto a_a = std::make_unique<unsigned int[]>(size);
        auto a_b = std::make_unique<unsigned int[]>(size);
        auto result = std::make_unique<unsigned int[]>(size);
        std::copy(a.begin(), a.end(), a_a.get());
        std::copy(b.begin(), b.end(), a_b.get());

        // Device memory management
        unsigned int *d_a;
        unsigned int *d_b;
        unsigned int *d_result;

        cudaMalloc(&d_a,mem_size);
        cudaMalloc(&d_b,mem_size);
        cudaMalloc(&d_result,mem_size);

        cudaMemcpy(d_a,a_a.get(),mem_size,cudaMemcpyHostToDevice);
        cudaMemcpy(d_b,a_b.get(),mem_size,cudaMemcpyHostToDevice);

        kernel<<<(size+1023)/1024,1024>>>(d_a,d_b,d_result,size);

        cudaMemcpy(result.get(),d_result,mem_size,cudaMemcpyDeviceToHost);

        for(auto i=0;i<size;++i){
            this->result.push_back(result[i]);
        }

        cudaDeviceSynchronize();
        cudaFree(d_a);
        cudaFree(d_b);
        cudaFree(d_result);
    }
}
