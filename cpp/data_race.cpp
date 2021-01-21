//
// Created by shurtado on 1/21/2021.
//

#include <thread>

unsigned int counter = 0;
void count(){
    // Greater than 10000 will cause a data race
    for(unsigned int i=0;i<100000;++i){
        counter++;
    }
}
int main(){
    std::thread c1(count);
    std::thread c2(count);
    c1.join();
    c2.join();
    printf("Thread Count %u\n",counter);
}