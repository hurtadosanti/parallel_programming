//
// Created by SHurtado on 2/1/2021.
//

#include <include/parallel_math.h>
#include <mutex>

std::atomic<unsigned int> response=0.0;
std::mutex lock;

void primes_sum(const size_t size,const size_t batch, size_t num_workers, int i) {
    for(int p;p<batch;++p){
        auto counter = i + p * num_workers;
        if (counter < size && Samples::ParallelMath::is_prime(counter)) {
            lock.lock();
            response=response+counter;
            lock.unlock();
        }
    }
}

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

unsigned int Samples::ParallelMath::calculate_sum_primes(const size_t size) {
    response=0.0;
    size_t num_workers = std::thread::hardware_concurrency();
    int reminder = (size % num_workers == 0) ? 0 : 1;
    size_t loop = (size / num_workers + reminder);
    std::thread workers[num_workers];
    for (auto i = 0; i < num_workers; ++i) {
         workers[i] = std::thread(primes_sum,size,loop,num_workers, i);
    }
    for(auto &w:workers){
        w.join();
    }
    return response.load();
}


