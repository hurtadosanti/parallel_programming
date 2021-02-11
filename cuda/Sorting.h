//
// Created by shurtado on 11.02.21.
//

#ifndef CUDA_SORTING_H
#define CUDA_SORTING_H
#include <vector>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/copy.h>
#include <list>
#include <cuda.h>
class Sorting {
public:
    std::vector<int> cuda_sort(std::vector<int> unsorted);
};


#endif //CUDA_SORTING_H
