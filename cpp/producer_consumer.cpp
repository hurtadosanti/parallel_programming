//
// Created by SHurtado on 1/20/2021.
//
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

class Server{
public:
    void prepare(int i){
        std::unique_lock<std::mutex> lidl_lock(lidl);
        processes.push(i);
        lidl_lock.unlock();
        process_ready.notify_one();
    }
    int take(){
        std::unique_lock<std::mutex> lidl_lock(lidl);
        while (processes.empty()){
            process_ready.wait(lidl_lock);
        }
        int process = processes.front();
        processes.pop();
        return process;
    }
private:
    std::queue<int> processes;
    std::mutex lidl;
    std::condition_variable process_ready;
};

Server server = Server();

void producer(){
    for(int i=0;i<1000000;++i){
        server.prepare(i);
    }
    // Last element
    server.prepare(-1);
    printf("Producer Done!\n");
}
void consumer(){
    int processed=0;
    while (true){
        int process = server.take();
        if(process==-1){
            printf("Consumer processed %d elements\n",processed);
            // give a last element for other consumers
            server.prepare(-1);
            return;
        }else{
            processed++;
        }
    }
}
int main(){
    std::thread producer1(producer);
    std::thread consumer1(consumer);
    std::thread consumer2(consumer);
    producer1.join();
    consumer1.join();
    consumer2.join();
}
