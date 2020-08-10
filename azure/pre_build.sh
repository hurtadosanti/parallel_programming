#!/bin/bash
# Script to setup opencv with cuda support
sudo apt-get -qq update && sudo apt-get -yqq upgrade && sudo apt-get -yqq install git vim curl cmake build-essential libtbb2 libtbb-dev
sudo mkdir /opt/libs
sudo chown shurtado.shurtado /opt/libs
cd /opt/libs
git clone https://github.com/opencv/opencv.git 
git clone https://github.com/opencv/opencv_contrib.git
mkdir opencv_build
cd opencv_build
#https://stackoverflow.com/questions/6622454/cuda-incompatible-with-my-gcc-version
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local \
     -D BUILD_PROTOBUF=OFF -D UPDATE_PROTO_FILES=ON -D BUILD_PNG=OFF \
     -D BUILD_JPEG=OFF -D INSTALL_C_EXAMPLES=OFF -D WITH_CUDA=ON \
     -D BUILD_EXAMPLES=OFF \
     -D BUILD_PERF_TESTS=OFF -D BUILD_opencv_java=OFF -D BUILD_opencv_python2=OFF \
     -D BUILD_opencv_python3=OFF -D INSTALL_PYTHON_EXAMPLES=OFF -D WITH_TBB=ON \
     -D OPENCV_EXTRA_MODULES_PATH="../opencv_contrib/modules" \
     -D WITH_FFMPEG=OFF ../opencv 1>/dev/null

make -j 4
make install

echo Install Google Benchmark
cd /opt/libs
echo $PWD
git clone https://github.com/google/benchmark.git 1>/dev/null

git clone https://github.com/google/googletest.git benchmark/googletest 1>/dev/null

cd benchmark/googletest
mkdir build 
echo $PWD
cd build && cmake -DCMAKE_BUILD_TYPE=Release .. 1>/dev/null
make -j 4 1>/dev/null
#make test
sudo make install

cd ../../
mkdir build
echo $PWD
cd build && cmake -DCMAKE_BUILD_TYPE=Release ../ 1>/dev/null
make -j 4 1>/dev/null
#make test
sudo make install
