//
// Created by Santiago Hurtado on 18.10.19.
//
#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>

namespace multithread{
    class NaturalNumbers{
    private:
        std::vector<unsigned int> result;
    public:
        double calculate_sum_primes(size_t size);
        size_t size(){ return result.size();};
        std::vector<unsigned int>::iterator begin(){ return result.begin();};
        std::vector<unsigned int>::iterator end(){ return result.end();};
        static bool is_prime(unsigned int number);
        unsigned int get(size_t size){ return result.size();};
    };
}
