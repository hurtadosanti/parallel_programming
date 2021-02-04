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

// Register the function as a benchmark
BENCHMARK(BM_multi_thread_sum_primes)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK(BM_serial_sum_primes)->RangeMultiplier(2)->Range(64, 256);
// Run the benchmark
BENCHMARK_MAIN();