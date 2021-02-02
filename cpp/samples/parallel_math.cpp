//
// Created by SHurtado on 2/1/2021.
//

#include <include/parallel_math.h>

bool Samples::ParallelMath::is_prime(int number) {
    if (number == 2) {
        return true;
    } else if (number < 2 || number % 2 == 0) {
        return false;
    } else {
        for (int i = 2; i < number/2; i++) {
            if (number % i == 0) {
                return false;
            }
        }
    }
    return true;
}

double Samples::ParallelMath::calculate_sum_primes(const size_t size) {
    auto result = 0.0;
    size_t split = 6;
    int partitions = size/split;
    int remainder = size%split;
    int k = (size%split == 0)? size : split-size%split;
    for(size_t i=0;i<size;++i){
        if(is_prime(i)){
            result+=i;
        }
    }
    return result;
}

