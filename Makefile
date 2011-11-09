CXX=g++
CPPFLAGS=
CXXFLAGS=
LDLIBS=

%.exe:%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDLIBS) -o $@


stl_vector.exe:CPPFLAGS+=-g
stl_vector.exe: