CXX     = g++
CXXFLAG = -g -rdynamic -fno-exceptions
test.x: CallStack.cpp main.cpp
	$(CXX) $^ -o $@ $(CXXFLAG)
