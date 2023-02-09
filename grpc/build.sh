
cd - && \
/mnt/lustre/wangguoteng.p/local/grpc/bin/protoc --cpp_out=../c ./test.proto && \
/mnt/lustre/wangguoteng.p/local/grpc/bin/protoc --grpc_out=../c --plugin=protoc-gen-grpc=/mnt/lustre/wangguoteng.p/grpc/grpc/cmake/build/grpc_cpp_plugin ./test.proto && \
cd -