CXX     = g++
CXXFLAG = -g -rdynamic -fno-exceptions
test.exe: CallStack.cpp main.cpp
	$(CXX) $^ -o $@ $(CXXFLAG)
