//
// Created by shurtado on 28.01.21.
//

#include <benchmark/benchmark.h>
#include "include/parallel_math.h"

void BM_empty(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(state.iterations());
    }
}
// Register the function as a benchmark
BENCHMARK(BM_empty);
BENCHMARK(BM_empty)->ThreadPerCpu();

// Run the benchmark
BENCHMARK_MAIN();