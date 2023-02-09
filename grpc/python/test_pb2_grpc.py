# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
"""Client and server classes corresponding to protobuf-defined services."""
import grpc

import test_pb2 as test__pb2


class C_rpcStub(object):
    """Missing associated documentation comment in .proto file."""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.c_do_something = channel.unary_unary(
                '/helloworld.C_rpc/c_do_something',
                request_serializer=test__pb2.C_IN.SerializeToString,
                response_deserializer=test__pb2.C_OUT.FromString,
                )


class C_rpcServicer(object):
    """Missing associated documentation comment in .proto file."""

    def c_do_something(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_C_rpcServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'c_do_something': grpc.unary_unary_rpc_method_handler(
                    servicer.c_do_something,
                    request_deserializer=test__pb2.C_IN.FromString,
                    response_serializer=test__pb2.C_OUT.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'helloworld.C_rpc', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class C_rpc(object):
    """Missing associated documentation comment in .proto file."""

    @staticmethod
    def c_do_something(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/helloworld.C_rpc/c_do_something',
            test__pb2.C_IN.SerializeToString,
            test__pb2.C_OUT.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)


class Py_rpcStub(object):
    """Missing associated documentation comment in .proto file."""

    def __init__(self, channel):
        """Constructor.

        Args:
            channel: A grpc.Channel.
        """
        self.py_do_something = channel.unary_unary(
                '/helloworld.Py_rpc/py_do_something',
                request_serializer=test__pb2.PY_IN.SerializeToString,
                response_deserializer=test__pb2.PY_OUT.FromString,
                )


class Py_rpcServicer(object):
    """Missing associated documentation comment in .proto file."""

    def py_do_something(self, request, context):
        """Missing associated documentation comment in .proto file."""
        context.set_code(grpc.StatusCode.UNIMPLEMENTED)
        context.set_details('Method not implemented!')
        raise NotImplementedError('Method not implemented!')


def add_Py_rpcServicer_to_server(servicer, server):
    rpc_method_handlers = {
            'py_do_something': grpc.unary_unary_rpc_method_handler(
                    servicer.py_do_something,
                    request_deserializer=test__pb2.PY_IN.FromString,
                    response_serializer=test__pb2.PY_OUT.SerializeToString,
            ),
    }
    generic_handler = grpc.method_handlers_generic_handler(
            'helloworld.Py_rpc', rpc_method_handlers)
    server.add_generic_rpc_handlers((generic_handler,))


 # This class is part of an EXPERIMENTAL API.
class Py_rpc(object):
    """Missing associated documentation comment in .proto file."""

    @staticmethod
    def py_do_something(request,
            target,
            options=(),
            channel_credentials=None,
            call_credentials=None,
            insecure=False,
            compression=None,
            wait_for_ready=None,
            timeout=None,
            metadata=None):
        return grpc.experimental.unary_unary(request, target, '/helloworld.Py_rpc/py_do_something',
            test__pb2.PY_IN.SerializeToString,
            test__pb2.PY_OUT.FromString,
            options, channel_credentials,
            insecure, call_credentials, compression, wait_for_ready, timeout, metadata)
