//
// Created by Santiago Hurtado on 18.10.19.
//
#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>

namespace multithread{
    class Vectors{
    private:
        std::vector<unsigned int> result;
    public:
        size_t size(){ return result.size();};
        std::vector<unsigned int>::iterator begin(){ return result.begin();};
        std::vector<unsigned int>::iterator end(){ return result.end();};
        unsigned int get(size_t pos){ return result[pos];};
        void sum(const std::vector<unsigned int> &a,const std::vector<unsigned int> &b);
        void sum_size(size_t size);
    };
}