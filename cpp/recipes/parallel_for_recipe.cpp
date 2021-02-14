//
// Created by shurtado on 2/14/2021.
//
#include <algorithm>

unsigned int parallel_sum(const unsigned int num){
    std::vector<std::string> foo;
    std::for_each(
            std::execution::par_unseq,
            foo.begin(),
            foo.end(),
            [](auto&& item)
            {
            //do stuff with item
            });
}
