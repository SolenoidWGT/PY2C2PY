import subprocess
import sys

if __name__ == "__main__":
    num = int(sys.argv[1])
    words = str(sys.argv[2])
    if num == 0:
        print("PY1: launch CC!")
        # 执行shell语句并定义输出格式
        p = subprocess.Popen("./cmain.exe {} {}".format(1, words),shell=True, stdout=subprocess.PIPE)
        # 判断进程是否结束, Popen.poll()用于检查子进程是否已经执行结束，没结束返回None，结束后返回状态码
        while p.poll() is None:  
            # 判断是否执行成功, Popen.wait()等待子进程结束，并返回状态码；
            if p.wait() != 0:
                print("PY1: call C failed!")
            else:
                re = p.stdout.readlines()
                result = []
                for i in range(len(re)):  # 由于原始结果需要转换编码，所以循环转为utf8编码并且去除\r\n
                    res = re[i].decode('utf-8').strip('\r\n')
                    print(res)
                    result.append(res)
                print("PY1: get return \"{}\"".format(result[len(result) - 1]))    # 只取最后一行的输出作为结果
    else:
        print("PY2: called by C, get input: {}, \"{}\"".format(num, words), flush=True, file=sys.stdout)
        print("PY2: return \"python-2\"", flush=True, file=sys.stdout)
