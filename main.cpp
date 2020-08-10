#include <iostream>
#include <thread>
#include <chrono>
void print_thread(const int id){
  std::this_thread::sleep_for(std::chrono::milliseconds (id*10));
  std::cout << std::this_thread::get_id()<<":"<<id<<std::endl;
}
int main() {
  std::thread t1(print_thread,1);
  std::thread t2(print_thread,2);
  std::thread t3(print_thread,3);
  std::thread t4(print_thread,4);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  return 0;
}
