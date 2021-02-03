#!/usr/bin/env bash
sudo apt install -yq cmake make gcc g++ valgrind linux-tools-virtual linux-tools-generic linux-tools-$(uname -r)
git clone https://github.com/google/benchmark.git
git clone https://github.com/google/googletest.git benchmark/googletest
cd benchmark
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
sudo cmake --build "build" --config Release --target install
cd googletest
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
sudo cmake --build "build" --confstart.ig Release --target install