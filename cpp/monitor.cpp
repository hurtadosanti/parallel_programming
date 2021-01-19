//
// Created by SHurtado on 1/19/2021.
//
#include <thread>
#include <mutex>

int remaining = 10;
std::mutex lid;

void consumer(int id){
    int return_lid = 0;
    while(remaining>0){
        std::unique_lock<std::mutex> lid_lock(lid);
        if((id == remaining%2)&&(remaining>0)){
            remaining --;
        }else{
            return_lid++;
        }
    }
    printf("Consumer %d blocked %u times \n",id,return_lid);
}

int main(){
    std::thread consumers[2];
    for(int i =0;i<2;i++){
        consumers[i] = std::thread(consumer,i);
    }
    for(auto &c:consumers){
        c.join();
    }
}