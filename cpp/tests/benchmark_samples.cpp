//
// Created by shurtado on 28.01.21.
//

#include <benchmark/benchmark.h>
#include "include/parallel_math.h"
#include "include/serial_math.h"

void BM_multi_thread_sum_primes(benchmark::State& state) {
    auto n = state.range(0);
    auto pm = Samples::ParallelMath();
    for (auto _ : state) {
        benchmark::DoNotOptimize(pm.calculate_sum_primes(n*1000));
    }
}
void BM_serial_sum_primes(benchmark::State& state) {
    auto n = state.range(0);
    auto pm = Samples::SerialMath();
    for (auto _ : state) {
        benchmark::DoNotOptimize(pm.calculate_sum_primes(n*1000));
    }
}
void BM_serial_matrix_multiplication(benchmark::State& state){
    const size_t size=state.range(0);
    long ** A = nullptr;
    long ** B = nullptr;
    long ** result = nullptr;
    Samples::SerialMath::init_matrix(size, A, B, result);
    for (auto _ : state) {
        Samples::SerialMath::matrix_multiply(A, size, size, B, size, size, result);
    }
    for (size_t i=0; i<size; i++) {
        free(result[i]);
        free(A[i]);
        free(B[i]);
    }
}
void BM_parallel_matrix_multiplication(benchmark::State& state){
    const size_t size=state.range(0);
    long ** A = nullptr;
    long ** B = nullptr;
    long ** result = nullptr;
    Samples::ParallelMath::init_matrix(size, A, B, result);
    for (auto _ : state) {
        Samples::ParallelMath::matrix_multiply(A, size, size, B, size, size, result);
    }
    for (size_t i=0; i<size; i++) {
        free(result[i]);
        free(A[i]);
        free(B[i]);
    }
}

// Register the function as a benchmark
BENCHMARK(BM_multi_thread_sum_primes)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK(BM_serial_sum_primes)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK(BM_serial_matrix_multiplication)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK(BM_parallel_matrix_multiplication)->RangeMultiplier(2)->Range(64, 256);
// Run the benchmark
BENCHMARK_MAIN();