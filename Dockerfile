FROM ubuntu:latest

WORKDIR /skylog

RUN apt-get update && \
    apt-get install -y \
    g++ \
    cmake \
    make

COPY . /skylog

RUN cmake . && \
    make

CMD ["./sylogger"]