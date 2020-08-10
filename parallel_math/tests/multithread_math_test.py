
import sys
import os
sys.path.append(os.getenv('PARALLEL_MATH_MODULE_PATH'))

import multithread_math


def test_sum_primes():
    n = multithread_math.NaturalNumbers()
    r = n.calculate_sum_primes(10)
    assert r == 17
    assert 4 == n.size()
    count = 0
    for i in n.results():
        count = 1 + count
    assert count == 4


def test_sum_vectors():
    v = multithread_math.Vectors()
    v.sum(10)
    assert v.size() == 10


if __name__ == "__main__":
    print(multithread_math.__file__)
    test_sum_primes()
    test_sum_vectors()
    assert True
