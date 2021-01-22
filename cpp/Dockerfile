FROM ubuntu:20.04
RUN apt-get -qq update && apt -yqq upgrade
RUN apt-get install -yqq gcc-10 g++-10 cmake
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10
