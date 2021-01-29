#include <iostream>
#include <boost/asio.hpp>
#include <boost/lockfree/queue.hpp>
#include <thread>
#include <string>
#include <cmath>
#include <time.h>

int main(int argc, char **args) {
    clock_t start,end;
    int size = 1024*1024;
    double sum = 0;
    if (argc == 2) {
        size = std::stoi(args[1]);
    }

    unsigned int *a = (unsigned int*)malloc(sizeof(unsigned int)*size);
    unsigned int *b = (unsigned int*)malloc(sizeof(unsigned int)*size);
    unsigned int *result = (unsigned int*)malloc(sizeof(unsigned int)*size);

    for (int i=0; i<size; i++){
        a[i] = i;
        b[i] = i*i;
        result[i]=0;
    }

    boost::asio::thread_pool pool(std::thread::hardware_concurrency());

    start=clock();
    for (unsigned int i = 0; i < size; i++) {
        boost::asio::post(pool, [&result,&a,&b, i]() {
            result[i]=a[i]+b[i];
        });
    }
    end=clock();
    pool.join();
    double total = 0;
    for (int i=0; i<size; i++) {
        total+=result[i];
    }
    std::cout << total << std::endl;
    std::cout << (double) (end-start)/CLOCKS_PER_SEC << std::endl;
    free(a);
    free(b);
    free(result);
    return 0;
}
