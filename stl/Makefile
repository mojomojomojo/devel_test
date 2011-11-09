CXX=g++
CPPFLAGS=
CXXFLAGS=
LDLIBS=

%.exe:%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDLIBS) -o $@


BINARIES=stl_vector.exe stl_vector.o*

stl_vector.exe:CPPFLAGS+=-g
stl_vector.exe:


clean:
	del /q $(BINARIES)

