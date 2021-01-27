//
// Created by shurtado on 1/27/2021.
//
#include <thread>
#include <iostream>
#include <mutex>

unsigned int count_1 =0;

unsigned int count_2 =0;

std::recursive_mutex lock;

void add_count_1(){
    lock.lock();
    count_1++;
    lock.unlock();
}
void add_count_2(){
    lock.lock();
    count_2++;
    add_count_1();
    lock.unlock();
}

void user(){
    for(unsigned int i=0;i<10000;i++){
        add_count_1();
        add_count_2();
    }
}

int main(){
    std::thread t_1(user);
    std::thread t_2(user);
    t_1.join();
    t_2.join();
    std::cout<<"Count 1:"<<count_1<<std::endl;
    std::cout<<"Count 2:"<<count_2<<std::endl;
}
