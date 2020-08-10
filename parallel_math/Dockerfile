FROM nvidia/cuda

ENV LD_LIBRARY_PATH="/usr/local/lib"
ENV CPLUS_INCLUDE_PATH=/usr/include/python3.6m

RUN apt update && apt upgrade -y
RUN apt install -y build-essential cmake python3 python3-dev python3-numpy

COPY . /opt/parallel_math
RUN tar xvfz /opt/parallel_math/boost_1_71_0.tar.gz -C /opt/ \
    && cd /opt/boost_1_71_0 \
    && ./bootstrap.sh --with-libraries=python,thread --with-python-version=3.6 --prefix=/usr/local \
    && echo "using python : 3.6 : /usr/bin/python3.6 : /usr/include/python3.6m : /usr/lib ;" \
    >>/opt/boost_1_71_0/project-config.jam
RUN cd /opt/boost_1_71_0 && ./b2 && ./b2 install
# libgtest depends on python2, wich would not let compile boost
RUN apt install -y libgtest-dev
WORKDIR /usr/src/googletest/googletest/build
RUN cmake .. && make && make install && apt remove -y python2*
# we need to remove python to dont iterfiere with the boost build, a fix can be done on the cmakefile
WORKDIR /opt/parallel_math/build
RUN cmake .. && make
