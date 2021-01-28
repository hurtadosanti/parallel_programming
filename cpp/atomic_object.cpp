//
// Created by SHurtado on 1/27/2021.
//
#include <thread>
#include <atomic>
#include <iostream>

std::atomic<unsigned int> count(0);

void counter(){
    for(unsigned int i=0;i<1000000;i++){
        count++;
    }
}

int main(){
    std::thread t1(counter);
    std::thread t2(counter);
    t1.join();
    t2.join();
    std::cout<<"counter:"<<count.load()<<std::endl;
}
