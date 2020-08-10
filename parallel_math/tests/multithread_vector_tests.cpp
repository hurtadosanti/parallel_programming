//
// Created by Santiago Hurtado on 19.10.19.
//
#include <gtest/gtest.h>
#include "multithread/Vectors.h"

TEST(MultithreadSumVector, SumVector) {
    auto vectors = multithread::Vectors();
    std::vector<unsigned int> a ={1,2,3,4};
    std::vector<unsigned int> b ={2,4,5,6};
    vectors.sum(a,b);
    ASSERT_EQ(a.size(),b.size());
    ASSERT_EQ(a.size(),vectors.size());
    for(auto i=0;i<a.size();++i){
        ASSERT_EQ(a[i]+b[i],vectors.get(i));
    }
}
TEST(MultithreadSumVector, LargeSumVector) {
    auto vectors = multithread::Vectors();
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
TEST(MultithreadSumVector, SumVectorSize) {
    auto vectors = multithread::Vectors();
    vectors.sum_size(10);
    for(auto i=0;i<vectors.size();++i){
        ASSERT_EQ(i+i*i,vectors.get(i));
    }
}
TEST(MultithreadSumVector, LargeSumVectorSize) {
    auto vectors = multithread::Vectors();
    vectors.sum_size(1024);
    for(auto i=0;i<vectors.size();++i){
        ASSERT_EQ(i+i*i,vectors.get(i));
    }
}

TEST(MultithreadSumVector, DifferentSizesVectors) {
    auto vectors = multithread::Vectors();
    std::vector<unsigned int> a ={1,2,3,4};
    std::vector<unsigned int> b ={2,4};
    vectors.sum(a,b);
    ASSERT_EQ(0,vectors.size());
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}