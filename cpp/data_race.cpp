//
// Created by shurtado on 1/21/2021.
//

#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

unsigned int counter = 0;
std::atomic<unsigned int> atomic_counter;
std::mutex lock;

void lock_count(){
    // Greater than 10000 will cause a data race
    lock.lock();
    for(unsigned int i=0;i<100;++i) {
        printf("Thread waiting %d\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::microseconds(200));
        counter++;
    }
    lock.unlock();
}

void count(){
    // Greater than 10000 will cause a data race
    for(unsigned int i=0;i<100;++i) {
        printf("Thread waiting %d\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::microseconds(200));
        lock.lock();
        counter++;
        lock.unlock();
    }
}
void atomic_count(){
    for(unsigned int i=0;i<1000;++i) {
        //printf("Thread waiting %d\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::microseconds(200));
        atomic_counter++;
    }
}

int main(){
    //std::thread c1(count);
    //std::thread c2(count);
    std::thread c1(atomic_count);
    std::thread c2(atomic_count);
    c1.join();
    c2.join();
    printf("Thread Count %u\n",atomic_counter.load());
}