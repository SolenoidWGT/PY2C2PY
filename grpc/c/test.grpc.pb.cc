// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto

#include "test.pb.h"
#include "test.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace helloworld {

static const char* C_rpc_method_names[] = {
  "/helloworld.C_rpc/c_do_something",
};

std::unique_ptr< C_rpc::Stub> C_rpc::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< C_rpc::Stub> stub(new C_rpc::Stub(channel, options));
  return stub;
}

C_rpc::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_c_do_something_(C_rpc_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status C_rpc::Stub::c_do_something(::grpc::ClientContext* context, const ::helloworld::C_IN& request, ::helloworld::C_OUT* response) {
  return ::grpc::internal::BlockingUnaryCall< ::helloworld::C_IN, ::helloworld::C_OUT, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_c_do_something_, context, request, response);
}

void C_rpc::Stub::async::c_do_something(::grpc::ClientContext* context, const ::helloworld::C_IN* request, ::helloworld::C_OUT* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::helloworld::C_IN, ::helloworld::C_OUT, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_c_do_something_, context, request, response, std::move(f));
}

void C_rpc::Stub::async::c_do_something(::grpc::ClientContext* context, const ::helloworld::C_IN* request, ::helloworld::C_OUT* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_c_do_something_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::helloworld::C_OUT>* C_rpc::Stub::PrepareAsyncc_do_somethingRaw(::grpc::ClientContext* context, const ::helloworld::C_IN& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::helloworld::C_OUT, ::helloworld::C_IN, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_c_do_something_, context, request);
}

::grpc::ClientAsyncResponseReader< ::helloworld::C_OUT>* C_rpc::Stub::Asyncc_do_somethingRaw(::grpc::ClientContext* context, const ::helloworld::C_IN& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncc_do_somethingRaw(context, request, cq);
  result->StartCall();
  return result;
}

C_rpc::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      C_rpc_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< C_rpc::Service, ::helloworld::C_IN, ::helloworld::C_OUT, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](C_rpc::Service* service,
             ::grpc::ServerContext* ctx,
             const ::helloworld::C_IN* req,
             ::helloworld::C_OUT* resp) {
               return service->c_do_something(ctx, req, resp);
             }, this)));
}

C_rpc::Service::~Service() {
}

::grpc::Status C_rpc::Service::c_do_something(::grpc::ServerContext* context, const ::helloworld::C_IN* request, ::helloworld::C_OUT* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* Py_rpc_method_names[] = {
  "/helloworld.Py_rpc/py_do_something",
};

std::unique_ptr< Py_rpc::Stub> Py_rpc::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Py_rpc::Stub> stub(new Py_rpc::Stub(channel, options));
  return stub;
}

Py_rpc::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_py_do_something_(Py_rpc_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Py_rpc::Stub::py_do_something(::grpc::ClientContext* context, const ::helloworld::PY_IN& request, ::helloworld::PY_OUT* response) {
  return ::grpc::internal::BlockingUnaryCall< ::helloworld::PY_IN, ::helloworld::PY_OUT, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_py_do_something_, context, request, response);
}

void Py_rpc::Stub::async::py_do_something(::grpc::ClientContext* context, const ::helloworld::PY_IN* request, ::helloworld::PY_OUT* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::helloworld::PY_IN, ::helloworld::PY_OUT, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_py_do_something_, context, request, response, std::move(f));
}

void Py_rpc::Stub::async::py_do_something(::grpc::ClientContext* context, const ::helloworld::PY_IN* request, ::helloworld::PY_OUT* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_py_do_something_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::helloworld::PY_OUT>* Py_rpc::Stub::PrepareAsyncpy_do_somethingRaw(::grpc::ClientContext* context, const ::helloworld::PY_IN& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::helloworld::PY_OUT, ::helloworld::PY_IN, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_py_do_something_, context, request);
}

::grpc::ClientAsyncResponseReader< ::helloworld::PY_OUT>* Py_rpc::Stub::Asyncpy_do_somethingRaw(::grpc::ClientContext* context, const ::helloworld::PY_IN& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncpy_do_somethingRaw(context, request, cq);
  result->StartCall();
  return result;
}

Py_rpc::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Py_rpc_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Py_rpc::Service, ::helloworld::PY_IN, ::helloworld::PY_OUT, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Py_rpc::Service* service,
             ::grpc::ServerContext* ctx,
             const ::helloworld::PY_IN* req,
             ::helloworld::PY_OUT* resp) {
               return service->py_do_something(ctx, req, resp);
             }, this)));
}

Py_rpc::Service::~Service() {
}

::grpc::Status Py_rpc::Service::py_do_something(::grpc::ServerContext* context, const ::helloworld::PY_IN* request, ::helloworld::PY_OUT* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace helloworld

