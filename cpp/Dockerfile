FROM ubuntu:20.04 as build
ENV TZ=Europe/Berlin
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get -qq update && apt-get -yqq upgrade
RUN apt-get install -yqq gcc g++ cmake git
WORKDIR /opt
RUN git clone https://github.com/google/benchmark.git \
    && git clone https://github.com/google/googletest.git benchmark/googletest \
    && cd benchmark && cmake -E make_directory "build" &&  \
    && cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build" \
    && cmake --build "build" --config Release \
    && cmake --build "build" --config Release --target install

# Files to copy
#    /usr/local/lib/libbenchmark.a
#    -- Installing: /usr/local/lib/libbenchmark_main.a
#    -- Installing: /usr/local/include/benchmark
#    -- Installing: /usr/local/include/benchmark/benchmark.h
#    -- Installing: /usr/local/lib/cmake/benchmark/benchmarkConfig.cmake
#    -- Installing: /usr/local/lib/cmake/benchmark/benchmarkConfigVersion.cmake
#    -- Installing: /usr/local/lib/pkgconfig/benchmark.pc
#    -- Installing: /usr/local/lib/cmake/benchmark/benchmarkTargets.cmake
#    -- Installing: /usr/local/lib/cmake/benchmark/benchmarkTargets-release.cmake


#FROM ubuntu:20.04
#RUN apt-get -qq update && apt -yqq upgrade
#RUN apt-get install -yqq gcc g++ cmake
#WORKDIR /opt/buid
#COPY CMakeLists.txt /opt/
#COPY *.cpp /opt/
#RUN cmake .. && make