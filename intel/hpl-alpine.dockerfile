FROM alpine
RUN apk add --no-cache wget bash

WORKDIR /opt/intel

RUN wget https://software.intel.com/content/dam/develop/external/us/en/documents/l_mklb_p_2020.2.001.tgz \
    && tar xvfz l_mklb_p_2020.2.001.tgz -C /opt/intel \ 
    && ln -s /opt/intel/l_mklb_p_2020.2.001/benchmarks_2020/linux/mkl/benchmarks/linpack \
    && rm -rf l_mklb_p_2020.2.001.tgz \
    && wget http://www.hpcg-benchmark.org/downloads/hpcg-3.1.tar.gz \
    && wget https://raw.githubusercontent.com/ULHPC/tutorials/devel/parallel/mpi/HPL/src/hpl-2.2/Make.intel64

WORKDIR /opt/intel/linpack
COPY lininput-small /opt/intel/linpack/lininput_xeon64

CMD ./runme_xeon64

