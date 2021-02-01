#!/usr/bin/env bash
git clone https://github.com/google/benchmark.git
git clone https://github.com/google/googletest.git benchmark/googletest
cd benchmark
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
sudo cmake --build "build" --config Release --target install
cd googletest
cmake -E make_directory "build"
cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"
sudo cmake --build "build" --config Release --target install