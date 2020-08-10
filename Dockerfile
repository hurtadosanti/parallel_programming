FROM ubuntu:18.04
ENV LD_LIBRARY_PATH="/usr/local/lib"
ENV CPLUS_INCLUDE_PATH=/usr/include/python3.6m
RUN apt-get update -y && apt-get upgrade -y && apt-get install build-essential cmake python3 python3-dev python3-numpy -y
COPY boost_1_70_0.tar.gz /opt/
WORKDIR /opt
RUN tar xvfz /opt/boost_1_70_0.tar.gz
WORKDIR /opt/boost_1_70_0
RUN ./bootstrap.sh --with-libraries=python --with-python-version=3.6 --prefix=/usr/local
RUN echo "using python : 3.6 : /usr/bin/python3.6 : /usr/include/python3.6 : /usr/lib ;">>/opt/boost_1_70_0/project-config.jam
RUN ./b2
RUN ./bjam install
