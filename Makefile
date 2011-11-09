CXX=g++
CPPFLAGS=
CXXFLAGS=
LDLIBS=

%.exe:%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDLIBS) -o $@


#program.exe:CPPFLAGS+=-g
#program.exe:LDLIBS+=-lpthread
#program.exe:


#test_program: program.exe
#	program.exe -testarg1 a