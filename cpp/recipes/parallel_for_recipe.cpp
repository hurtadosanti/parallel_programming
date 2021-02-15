//
// Created by shurtado on 2/14/2021.
//
#include <algorithm>
#include <execution>
#include <iostream>
#include <atomic>

unsigned int parallel_sum(std::vector<unsigned int> &values){

    std::atomic<unsigned int> result =0;
    std::for_each(
            std::execution::par,
            values.begin(),
            values.end(),
            [&result](auto&& item)
            {
                result+=item;
            });
    return result.load();
}
int main(){
    auto size = 1000000000;
    std::vector<unsigned int> values;
    for(int i=0;i<size;++i){
        values.push_back(i);
    }
    std::cout<<"Start"<<std::endl;
    auto res = parallel_sum(values);
    std::cout<<res<<std::endl;
    return 0;
}
