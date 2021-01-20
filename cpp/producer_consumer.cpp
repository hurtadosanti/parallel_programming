//
// Created by SHurtado on 1/20/2021.
//
#include <thread>
#include <queue>

class Server{
public:
    void prepare(int i){
        processes.push(i);
    }
    int take(){
        int process = processes.front();
        processes.pop();
        return process;
    }
private:
    std::queue<int> processes;
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
            printf("Consumer processed %d elements",processed);
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
