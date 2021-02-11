#include <iostream>
#include <random>
#include "Sorting.h"

int main() {
    auto s = Sorting();

    std::random_device rd;
    std::vector<int> a(10000);
    for (auto& d : a) {
        d = static_cast<int>(rd());
    }


    auto D = s.cuda_sort(a);

    float free_m,total_m,used_m;

    size_t free_t,total_t;

    cudaMemGetInfo(&free_t,&total_t);

    free_m =(uint)free_t/1048576.0 ;

    total_m=(uint)total_t/1048576.0;

    used_m=total_m-free_m;

    printf ( "  mem free %d .... %f MB mem total %d....%f MB mem used %f MB\n",free_t,free_m,total_t,total_m,used_m);

    // print contents of D
    for(int i = 0; i < D.size(); i++)
        std::cout << "D[" << i << "] = " << D[i] << std::endl;

    // H and D are automatically deleted when the function returns
    return 0;
}
