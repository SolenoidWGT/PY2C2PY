#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "test.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using grpc::ClientContext;
using grpc::Channel;

using helloworld::C_rpc;
using helloworld::C_IN;
using helloworld::C_OUT;

// export LD_LIBRARY_PATH=//mnt/lustre/wangguoteng.p/local//cmake/build:/mnt/cache/wangguoteng.p/demo/grpc/protobuf/lib
// export LIBRARY_PATH=//mnt/lustre/wangguoteng.p/local//cmake/build:/mnt/cache/wangguoteng.p/demo/grpc/protobuf/lib
// export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/root/bin:/usr/local/fping/sbin:/usr/local/fping/sbin:/mnt/cache/share/platform/env/miniconda3.7/bin:/mnt/cache/wangguoteng.p/code-server-4.6.0-linux-amd64/bin:/mnt/cache/share/git-2.0.5/bin/
//     -L/mnt/cache/wangguoteng.p/demo/grpc/protobuf/lib 
// /mnt/cache/share/gcc/gcc-7.5.0/bin/g++ -std=c++17 *.cc -o c_rpc \
    -L/mnt/lustre/wangguoteng.p/local/grpc/cmake/build \
    -L/mnt/lustre/wangguoteng.p/local/grpc/lib64/ \
    -Wl,-rpath,/mnt/lustre/wangguoteng.p/local/grpc/lib64/  \
    -lpthread -lprotobuf -lgrpc++ -labsl_synchronization \
    -I/mnt/lustre/wangguoteng.p/grpc/grpc/third_party/abseil-cpp/ \
    -I/mnt/lustre/wangguoteng.p/local/grpc/third_party/ \
    -I/mnt/lustre/wangguoteng.p/local/grpc/include  \
    -I/mnt/lustre/wangguoteng.p/local/grpc/third_party/protobuf/src/ \
    -I.

// Logic and data behind the server's behavior.
class C_rpcServiceImpl final : public C_rpc::Service {
  Status c_do_something(ServerContext* context, const C_IN* request, C_OUT* reply) override {
    std::string prefix("C server Hello ");
    reply->set_cb(prefix + request->ca());
    return Status::OK;
  }
};

class C_Server{
public:
    C_Server(std::string addr):server_address_(addr){
        ServerBuilder builder;
        // Listen on the given address without any authentication mechanism.
        // 监听给定的地址
        builder.AddListeningPort(server_address_, grpc::InsecureServerCredentials());
        // Register "service" as the instance through which we'll communicate with
        // clients. In this case it corresponds to an *synchronous* service.
        builder.RegisterService(&service);
        // Finally assemble the server.
        server_ = std::move(builder.BuildAndStart());
        std::cout << "Server listening on " << server_address_ << std::endl;
    }

    void shutdown(){
        server_->Shutdown();
    }

    void wait(){
        server_->Wait();
    }

private:
    std::unique_ptr<Server> server_;
    C_rpcServiceImpl service;
    std::string server_address_;
};

// static method : Greeter::NewStub
class C_Client{
public:
    C_Client(std::shared_ptr<Channel> channel)
        :stub_(C_rpc::NewStub(channel)){
    }

    std::string c_do_something(std::string name){
        ClientContext context;
        C_OUT reply;
        C_IN request;
        request.set_ca(name);

        Status status = stub_->c_do_something(&context ,request, &reply);

        if(status.ok()){
            return reply.cb();
        }else{
            return "failure";
        }
    }

private:
    std::unique_ptr<C_rpc::Stub> stub_;
};


int main(int argc, char** argv) {
    C_Server server("0.0.0.0:50051");
    // auto channel = grpc::CreateChannel("0.0.0.0:50051",grpc::InsecureChannelCredentials());
    // C_Client client(channel);
    // block until get result from RPC server
    // std::string result = client.c_do_something("wanjun");
    // printf("get result [%s]\n",result.c_str());
    // std::cout << "get result" << result << std::endl;
    // server.shutdown();
    server.wait();
    return 0;
}

