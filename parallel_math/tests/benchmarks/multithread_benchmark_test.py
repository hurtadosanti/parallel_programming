import sys
import os
sys.path.append(os.getenv('PARALLEL_MATH_MODULE_PATH'))

import multithread_math


def test_multithread_sum_vectors(benchmark, size):
    v = multithread_math.Vectors()
    v.sum(10)
    assert v.size() == 10
    benchmark(v.sum, size)


def test_multithread_sum_primes(benchmark, size):
    n = multithread_math.NaturalNumbers()
    r = n.calculate_sum_primes(10)
    assert r == 17
    assert 4 == n.size()
    count = 0
    for i in n.results():
        count = 1 + count
    assert count == 4
    benchmark(n.calculate_sum_primes, size)