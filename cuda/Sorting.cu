//
// Created by shurtado on 11.02.21.
//

#include "include/Sorting.h"

std::vector<int> Sorting::cuda_sort(std::vector<int> &unsorted) {
    // copy to device
    thrust::device_vector<int> D(unsorted.begin(),unsorted.end());
    // Sort
    thrust::sort(D.begin(),D.end());
    // copy back to host
    std::vector<int> result(D.size());
    thrust::copy(D.begin(),D.end(),result.begin());
    return result;
}
