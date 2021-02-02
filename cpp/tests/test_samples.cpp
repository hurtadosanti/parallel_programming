//
// Created by shurtado on 1/30/2021.
//
#include <gtest/gtest.h>
#include "include/parallel_math.h"

TEST(MultithreadNaturalNumbers, IsPrime) {

    auto pm = Samples::ParallelMath();

    ASSERT_TRUE(pm.is_prime(2));
    ASSERT_TRUE(pm.is_prime(3));
    ASSERT_TRUE(pm.is_prime(71));
    ASSERT_TRUE(pm.is_prime(7919));
}

TEST(MultithreadNaturalNumbers, SumOfPrime) {

    auto pm = Samples::ParallelMath();
    ASSERT_EQ(1060,pm.calculate_sum_primes(100));

}
TEST(MultithreadNaturalNumbers, SumOfLargePrime) {

    auto pm = Samples::ParallelMath();
    ASSERT_EQ(454396537,pm.calculate_sum_primes(100000));
}

TEST(MultithreadNaturalNumbers, IsNotPrime) {

    auto pm = Samples::ParallelMath();

    ASSERT_FALSE(pm.is_prime(4));
    ASSERT_FALSE(pm.is_prime(70));
    ASSERT_FALSE(pm.is_prime(7920));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}