from concurrent import futures
import time
import grpc
import multiprocessing

import test_pb2_grpc
import test_pb2


class C_rpc(test_pb2_grpc.C_rpcServicer):
    def c_do_something(self, request, context):
        print(request.ca)
        return test_pb2.C_OUT(cb="python server respone")


def server():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=2))
    test_pb2_grpc.add_C_rpcServicer_to_server(C_rpc(), server)
    server.add_insecure_port('0.0.0.0:50051')
    server.start()
    print("server is opening ,waiting for message...")
    try:
        while True:
            time.sleep(10)
    except KeyboardInterrupt:
        server.stop(0)


def client():
    channel = grpc.insecure_channel('0.0.0.0:50051')
    stub = test_pb2_grpc.C_rpcStub(channel)
    response = stub.c_do_something(test_pb2.C_IN(ca='This is message from client!'))
    print("client received: " + response.cb)


if __name__ == '__main__':
    # need turn off proxy
    # p = multiprocessing.Process(target=server)
    # p.start()
    # time.sleep(1)  # wait some time to let server start
    client()
    # p.join()