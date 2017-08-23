[![Build Status](https://travis-ci.org/ZhangJunQCC/CallStack-for-Windows-and-Linux.svg?branch=master)](https://travis-ci.org/ZhangJunQCC/CallStack-for-Windows-and-Linux)

# CallStack-for-Windows-and-Linux

On Linux, one can check the call stack by using `backtrace <execinfo.h>`, which is unavailable on Windows. This light-weighed class is a wrapper of the corresponding functions for both Linux and Windows platforms, having the following features:
* You can obtain the call stack by simply calling `CallStack::GetCalls(cs)`.
* Available on Linux and Windows. Compatible with g++ (Linux), mingw, Microsoft Visual C++ (Windows).
* Thread safe.

Note that to obtain correct function names, certain compilation options are required:
* On Linux: `g++ -g -rdynamic`
* On Windows, mingw: `g++ -g`
* On Windows, Microsoft Visual C++: `cl /DEBUG /Zi`


I have provided a test file `main.cpp` to demonstrate the usage of `CallStack`. Example output on Windows is:
```
[  9] 0000000140001759: debug::CallStack::GetCalls in D:\test.exe
[  8] 000000014000523B: f4<double> in D:\test.exe
[  7] 0000000140005202: Foo::f3 in D:\test.exe
[  6] 000000014000517E: f2 in D:\test.exe
[  5] 0000000140005199: f1 in D:\test.exe
[  4] 00000001400051C2: main in D:\test.exe
[  3] 0000000140007B27: __tmainCRTStartup in D:\test.exe
[  2] 0000000076E959CD: BaseThreadInitThunk in C:\Windows\system32\kernel32.dll
[  1] 0000000076FCA561: RtlUserThreadStart in C:\Windows\SYSTEM32\ntdll.dll
```
and on Linux, is:
```
[  8]        0x402e69: debug::CallStack::GetCalls(std::vector<debug::CallStack::CallInfo, std::allocator<debug::CallStack::CallInfo> >&) in ./test.x
[  7]        0x403d2a: void f4<double>(double) in ./test.x
[  6]        0x403cfe: Foo::f3() in ./test.x
[  5]        0x403ca9: f2() in ./test.x
[  4]        0x403cb4: f1() in ./test.x
[  3]        0x403cca: [unknown function] in ./test.x
[  2]  0x2aaaab510b35: [unknown function] in /usr/lib64/libc.so.6
[  1]        0x402cd9: [unknown function] in ./test.x
```
