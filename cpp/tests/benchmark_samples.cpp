//
// Created by shurtado on 28.01.21.
//

#include <benchmark/benchmark.h>
#include "include/parallel_math.h"

void BM_multi_thread_sum_primes_to_one_thousand(benchmark::State& state) {
    for (auto _ : state) {
        auto pm = Samples::ParallelMath();
        pm.calculate_sum_primes(1000);
    }
}
void BM_multi_sum_primes_to_one_thousand(benchmark::State& state) {
    for (auto _ : state) {
        auto pm = Samples::ParallelMath();
        pm.calculate_sum_primes_sl(1000);
    }
}
// Register the function as a benchmark
BENCHMARK(BM_multi_thread_sum_primes_to_one_thousand);
BENCHMARK(BM_multi_sum_primes_to_one_thousand);
// Run the benchmark
BENCHMARK_MAIN();