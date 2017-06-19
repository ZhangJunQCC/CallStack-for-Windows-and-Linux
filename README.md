# CallStack-for-Windows-and-Linux
On Linux, one can check the call stack by using "backtrace <execinfo.h>", which is unavailable on Windows. This class is a wrapper of the corresponding functions for both Linux and Windows platforms, having the following features:

* You can obtain the call stack by simply calling CallStack::GetCalls(cs).
* Available on Linux and Windows. Compatible with g++ (Linux), mingw, Visual C++ (Windows).
* Thread safe.
