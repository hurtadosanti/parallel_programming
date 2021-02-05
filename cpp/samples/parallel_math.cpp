//
// Created by SHurtado on 2/1/2021.
//

#include <include/parallel_math.h>
#include <mutex>
namespace Samples {
    unsigned int response = 0;
    std::mutex lock;

    void primes_sum(const size_t size, const size_t batch, size_t num_workers, int i) {
        for (int p = 0; p < batch; ++p) {
            auto counter = i + p * num_workers;
            if (counter < size && Samples::ParallelMath::is_prime(counter)) {
                lock.lock();
                response = response + counter;
                lock.unlock();
            }
        }
    }

    bool ParallelMath::is_prime(int number) {
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

    unsigned int ParallelMath::calculate_sum_primes(const size_t size) {
        response = 0;
        size_t num_workers = std::thread::hardware_concurrency();
        int reminder = (size % num_workers == 0) ? 0 : 1;
        size_t loop = (size / num_workers + reminder);
        std::thread workers[num_workers];
        for (auto i = 0; i < num_workers; ++i) {
            workers[i] = std::thread(primes_sum, size, loop, num_workers, i);
        }
        for (auto &w:workers) {
            w.join();
        }
        return response;
    }


    void parallel_worker(long **, size_t, size_t, long **, size_t, size_t,long **, size_t, size_t);


    void ParallelMath::matrix_multiply(long **A, size_t num_rows_a, size_t num_cols_a, long **B, size_t num_rows_b,
                                  size_t num_cols_b, long **C) {
        size_t num_workers = std::thread::hardware_concurrency();
        size_t chunk_size = ceil((float)num_rows_a/num_workers);

        std::thread workers[num_workers];
        for (size_t i=0; i<num_workers; i++) {
            size_t start_row_c = std::min(i * chunk_size, num_rows_a);
            size_t end_row_c = std::min((i + 1) * chunk_size, num_rows_a);
            workers[i] = std::thread(parallel_worker, A, num_rows_a, num_cols_a,
                                     B, num_rows_b, num_cols_b,
                                     C, start_row_c, end_row_c);
        }
        for (auto &w : workers) {
            w.join();
        }
    }


    void parallel_worker(long ** A, size_t num_rows_a, size_t num_cols_a,
                         long ** B, size_t num_rows_b, size_t num_cols_b,
                         long ** C, size_t start_row_c, size_t end_row_c) {
        for (size_t i=start_row_c; i<end_row_c; i++) { // subset of rows in A
            for (size_t j=0; j<num_cols_b; j++) {
                C[i][j] = 0; // initialize result cell to zero
                for (size_t k=0; k<num_cols_a; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

}


