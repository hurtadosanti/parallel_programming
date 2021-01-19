//
// Created by SHurtado on 1/19/2021.
//
#include <thread>
#include <mutex>
#include <condition_variable>

int remaining = 10;
int threads_count = 5;
std::mutex lid;
std::condition_variable consumed;

void consumer(int id){
    int return_lid = 0;
    while(remaining>0){
        std::unique_lock<std::mutex> lid_lock(lid);
        while((id != remaining%threads_count)&&(remaining>0)){
            return_lid++;
            consumed.wait(lid_lock);
        }
        if(remaining>0){
            remaining --;
            lid_lock.unlock();
            // gets block for more than 2
            //consumed.notify_one();
            consumed.notify_all();
        }
    }
    printf("Consumer %d blocked %u times \n",id,return_lid);
}

int main(){

    std::thread consumers[threads_count];
    for(int i =0;i<threads_count;i++){
        consumers[i] = std::thread(consumer,i);
    }
    for(auto &c:consumers){
        c.join();
    }
}