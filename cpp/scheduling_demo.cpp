//
// Created by shurtado on 1/17/2021.
//

#include <thread>
#include <chrono>
#include <iostream>
bool looping = true;

void counter(const char* name){
    unsigned int counter = 0;
    while (looping){
        counter++;
    }
    //std::cout<<name<<"-"<<counter<<std::endl;
    printf("%s-%u\n",name,counter);
}
int main(){
    std::thread p1(counter,"p1");
    std::thread p2(counter,"p2");
    std::cout<<"counting:"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    looping = false;
    p1.join();
    p2.join();
}