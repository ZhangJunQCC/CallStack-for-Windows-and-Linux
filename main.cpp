//
// Author: Jun Zhang
// mailto: zhangjunqcc@gmail.com
//
// To enable Callstack correctly return a function name, the codes
// have to be compiled with the following options:
//
// On Linux and Mac OS X:
//    g++ -g -rdynamic
//
// On Windows, mingw:
//    g++ -g 
//
// On Windows, Microsoft Visual C++:
//    cl.exe /DEBUG /Zi
//
// For link options, see the example Makefiles.
//

#include "CallStack.h"
#include <cstdio>

using namespace debug;

template<typename T>
void f4(T a)
{
    vector<CallStack::CallInfo> cs;
    CallStack::GetCalls(cs);
    for(int i = 0; i < cs.size(); ++i)
    {
        printf("[%3d] %15p: %s in %s\n", cs.size()-i, cs[i].offset, cs[i].function.c_str(), cs[i].module.c_str());    
    }
}


class Foo {
public:
    void f3(void) { double x = 1.; f4(x); }
};

void f2(void) { Foo f; f.f3(); }
void f1(void) { f2(); }

int main(int argc, char** argv)
{
    f1();
    return 0;
}
