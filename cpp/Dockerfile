FROM ubuntu:20.04 AS build
ENV TZ=Europe/Berlin
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get -qq update && apt-get -yqq upgrade \
    && apt-get install -yqq cmake make gcc g++ git bash
# Libraries required
WORKDIR /opt
COPY setup_libs.sh /opt/
RUN /opt/setup_libs.sh
# Build the code
WORKDIR /src
COPY . /src/
RUN cmake -E make_directory "build" \
    && cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build" \
    && cmake --build "build" --config Release --target install

RUN cd build && make test

FROM ubuntu:20.04
WORKDIR /usr/local/parallel_programming
COPY --from=build /usr/local/parallel_programming .


