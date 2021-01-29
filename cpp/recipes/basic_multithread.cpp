#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

void print_thread(const int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id * 10));
    std::cout << "thread ID" << std::this_thread::get_id() << ":" << id << std::endl;
    std::cout << "Process ID" << getpid() << ":" << id << std::endl;
}

int main() {
    std::cout << "Thread Id " << std::this_thread::get_id() << std::endl;
    std::cout << "Process Id" << ":" << getpid() << std::endl;
    std::thread t1(print_thread, 1);
    std::thread t2(print_thread, 2);
    std::thread t3(print_thread, 3);
    std::thread t4(print_thread, 4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
