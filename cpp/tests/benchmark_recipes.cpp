//
// Created by shurtado on 11.02.21.
//
#include <benchmark/benchmark.h>
#include <execution>
#include <vector>
#include <random>
#include <algorithm>

using std::sort;
using std::vector;
using std::random_device;

void BM_serial_ordering(benchmark::State& state) {
    random_device rd;
    auto n = state.range(0);
    std::vector<double> doubles(n*10000);
    for (auto& d : doubles) {
        d = static_cast<double>(rd());
    }
    for (auto _ : state) {
        vector<double> sorted(doubles);
        sort(sorted.begin(), sorted.end());
    }
}
void BM_parallel_ordering(benchmark::State& state) {
    random_device rd;
    auto n = state.range(0);
    vector<double> doubles(n*10000);
    for (auto& d : doubles) {
        d = static_cast<double>(rd());
    }
    for (auto _ : state) {
        vector<double> sorted(doubles);
        sort(std::execution::par_unseq, sorted.begin(), sorted.end());
    }
}

BENCHMARK(BM_serial_ordering)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK(BM_parallel_ordering)->RangeMultiplier(2)->Range(64, 256);
BENCHMARK_MAIN();