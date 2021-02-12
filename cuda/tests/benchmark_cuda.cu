//
// Created by shurtado on 11.02.21.
//

#include <benchmark/benchmark.h>
#include <random>
#include <vector>
#include "../include/Sorting.h"

void BM_parallel_ordering(benchmark::State& state) {
    auto s = Sorting();
    std::random_device rd;
    auto n = state.range(0);
    std::vector<int> a(n*10000);
    for (auto& d : a) {
        d = static_cast<int>(rd());
    }
    for (auto _ : state) {
        std::vector<int> sorted(a);
        s.cuda_sort(a);
    }
}
BENCHMARK(BM_parallel_ordering)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK_MAIN();