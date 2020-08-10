//
// Created by Santiago Hurtado on 19.10.19.
//
#include <gtest/gtest.h>
#include "parallel/Vectors.h"

TEST(ParallelSumVector, SumVector) {
    auto vectors = parallel::Vectors();
    std::vector<unsigned int> a ={1,2};
    std::vector<unsigned int> b ={2,4};
    vectors.sum(a,b);
    ASSERT_EQ(a.size(),b.size());
    ASSERT_EQ(a.size(),vectors.size());
    for(auto i=0;i<vectors.size();++i){
        ASSERT_EQ(a[i]+b[i],vectors.get(i));
    }
}
TEST(ParallelSumVector, LargeSumVector) {
    auto vectors = parallel::Vectors();
    std::vector<unsigned int> a;
    std::vector<unsigned int> b;
    for(auto i=0;i<1024*1024;++i){
        a.push_back(i);
        b.push_back(i*i);
    }
    vectors.sum(a,b);
    ASSERT_EQ(a.size(),b.size());
    ASSERT_EQ(a.size(),vectors.size());
    for(auto i=0;i<vectors.size();++i){
        ASSERT_EQ(a[i]+b[i],vectors.get(i));
    }
}
TEST(ParallelSumVector, SumVectorSize) {
    auto vectors = parallel::Vectors();
    vectors.sum_size(10);
    for(auto i=0;i<vectors.size();++i){
        ASSERT_EQ(i+i*i,vectors.get(i));
    }
}
TEST(ParallelSumVector, LargeSumVectorSize) {
    auto vectors = parallel::Vectors();
    vectors.sum_size(1024);
    for(auto i=0;i<vectors.size();++i){
        ASSERT_EQ(i+i*i,vectors.get(i));
    }
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}