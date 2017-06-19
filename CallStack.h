//
// Author: Jun Zhang
// mailto: zhangjunqcc@gmail.com
//

#ifndef    __CALLSTACK_H__
#define    __CALLSTACK_H__

#include <string>
#include <vector>

namespace debug {

using namespace std;

class CallStack {
public:
    CallStack(void);
    ~CallStack(void);

    static const char* Unknown_Function;
    static const char* Unknown_Module;
    
    class CallInfo {
    public:
        CallInfo(void) { /* Nothing to do */ }
        CallInfo(long long unsigned int toffset, const string& tfunction, const string& tmodule)
            : offset(toffset), function(tfunction), module(tmodule) { /* Nothing to do */ }
        ~CallInfo(void) { /* Nothing to do */ }
        long long unsigned int offset;
        string function;
        string module;
    };

    static void GetCalls(vector<CallStack::CallInfo>& calls); // Get the call information.
    static string Demangle(const char* name);                 // Demangle the C++ function name.

};

}

#endif //  __CALLSTACK_H__
