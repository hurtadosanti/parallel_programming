//
// Created by Santiago Hurtado on 18.10.19.
//
#include <vector>
#include <iostream>
namespace parallel{
    class NaturalNumbers{
    private:
        std::vector<unsigned int> result;
    public:
        double calculate_sum_primes(size_t size);
        size_t size(){ return result.size();};
        std::vector<unsigned int>::iterator begin(){ return result.begin();};
        std::vector<unsigned int>::iterator end(){ return result.end();};
        unsigned int get(size_t position){ return result[position];};
    };
}
