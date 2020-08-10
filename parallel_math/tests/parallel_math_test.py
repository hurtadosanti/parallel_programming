
import sys
import os
sys.path.append(os.getenv('PARALLEL_MATH_MODULE_PATH'))

import parallel_math


def sum_primes():
    n = parallel_math.NaturalNumbers()
    r = n.calculate_sum_primes(10)
    assert r == 17
    assert 4 == n.size()
    count = 0
    for i in n.results():
        count = 1 + count
    assert count == 4


def sum_vectors():
    v = parallel_math.Vectors()
    v.sum(10)
    assert v.size() == 10
    pass


if __name__ == "__main__":
    print(parallel_math.__file__)
    sum_primes()
    sum_vectors()
    assert True
