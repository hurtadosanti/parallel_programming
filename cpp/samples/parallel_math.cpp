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
        for (int i = 2; i < number / 2; i++) {
            if (number % i == 0) {
                return false;
            }
        }
    }
    return true;
}

