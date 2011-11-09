CXX=g++
CPPFLAGS=
CXXFLAGS=
LDLIBS=

# GNU's make.exe doesn't seem to have correct automatic rules.
# If nothing else, create ones you need.
%.exe:%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDLIBS) -o $@


#program.exe:CPPFLAGS+=-g
#program.exe:LDLIBS=-lpthread
#program.exe:


#test_program: program.exe
#	program.exe -testarg1 a