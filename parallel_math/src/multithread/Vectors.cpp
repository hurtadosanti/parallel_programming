//
// Created by Santiago Hurtado on 18.10.19.
//

#include "multithread/Vectors.h"
namespace multithread{
    void Vectors::sum(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b) {
        this->result.clear();
        if(a.size()==0||b.size()==0||a.size()!=b.size()){
            return;
        }
        auto size = a.size();
        this->result.resize(size);
        boost::asio::thread_pool pool(std::thread::hardware_concurrency());
        for (unsigned int i = 0; i < size; i++) {
            boost::asio::post(pool, [this,&a,&b,i]() {
                this->result[i]=a[i]+b[i];
            });
        }
        pool.join();
    }
    void Vectors::sum_size(size_t size){
        this->result.clear();
        this->result.resize(size);
        boost::asio::thread_pool pool(std::thread::hardware_concurrency());
        for (unsigned int i = 0; i < size; i++) {
            boost::asio::post(pool, [this,i]() {
                this->result[i]=i+i*i;
            });
        }
        pool.join();
    }
}