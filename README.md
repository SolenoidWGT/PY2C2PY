# PY2C2PY

## 紧耦合交互

1. **Extending**：python通过import的方式调用C/C++可执行程序，这需要python和c之间使用一些胶水程序来约定彼此的数据交换格式，比如cpython。

2. **Embedding**：C/C++调用python解释器，执行python脚本，这种方式往往更复杂，需要Boost.Python等库，开发成本比较大。


## 松耦合交互
1. 使用popen+stdout/file的方式进行交互，见sdtio目录。
   
2. 使用protobuf+gRPC的方式进行交互，见grpc目录。