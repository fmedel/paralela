FROM ubuntu:16.04
RUN apt-get update && \
 apt-get install build-essential software-properties-common -y && \
 add-apt-repository ppa:ubuntu-toolchain-r/test -y && \
 apt-get update && \
 apt-get install gcc-snapshot -y && \
 apt-get update && \
 apt-get install gcc-6 g++-6 -y && \
 update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6 && \
 apt-get install gcc-4.8 g++-4.8 -y && \
 update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.8;

RUN apt-get install nano -y;
RUN apt-get install libpqxx-dev -y;
RUN apt-get install htop;
RUN apt install libomp-dev -y;

COPY paralela.tar.gz /
RUN mkdir prueba;
RUN cd prueba && tar -xzvf ../paralela.tar.gz;
RUN cd prueba && tar -xzvf datos.tar.gz;
RUN rm paralela.tar.gz;
RUN cd prueba && rm datos.tar.gz;

