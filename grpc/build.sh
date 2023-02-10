#!/bin/bash

export LD_LIBRARY_PATH=//mnt/lustre/wangguoteng.p/local//cmake/build:/mnt/cache/wangguoteng.p/demo/grpc/protobuf/lib
export LIBRARY_PATH=//mnt/lustre/wangguoteng.p/local//cmake/build:/mnt/cache/wangguoteng.p/demo/grpc/protobuf/lib
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/root/bin:/usr/local/fping/sbin:/usr/local/fping/sbin:/mnt/cache/share/platform/env/miniconda3.7/bin:/mnt/cache/wangguoteng.p/code-server-4.6.0-linux-amd64/bin:/mnt/cache/share/git-2.0.5/bin/
# -L/mnt/cache/wangguoteng.p/demo/grpc/protobuf/lib 
/mnt/cache/share/gcc/gcc-7.5.0/bin/g++ -std=c++17 *.cc -o c_rpc \
    -L/mnt/lustre/wangguoteng.p/local/grpc/cmake/build \
    -L/mnt/lustre/wangguoteng.p/local/grpc/lib64/ \
    -Wl,-rpath,/mnt/lustre/wangguoteng.p/local/grpc/lib64/  \
    -lpthread -lprotobuf -lgrpc++ -labsl_synchronization \
    -I/mnt/lustre/wangguoteng.p/grpc/grpc/third_party/abseil-cpp/ \
    -I/mnt/lustre/wangguoteng.p/local/grpc/third_party/ \
    -I/mnt/lustre/wangguoteng.p/local/grpc/include  \
    -I/mnt/lustre/wangguoteng.p/local/grpc/third_party/protobuf/src/ \
    -I.

cd - && \
/mnt/lustre/wangguoteng.p/local/grpc/bin/protoc --cpp_out=../c ./test.proto && \
/mnt/lustre/wangguoteng.p/local/grpc/bin/protoc --grpc_out=../c --plugin=protoc-gen-grpc=/mnt/lustre/wangguoteng.p/grpc/grpc/cmake/build/grpc_cpp_plugin ./test.proto && \
cd -