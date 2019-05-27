# particular targets
.PHONY: clean, mrproper

# GenericType
src = GenericType.cpp
obj = $(patsubst %.cpp, %.o, $(src))

# param
CXXFLAGS = -g -no-pie -Os -Wall -I.
CXX = g++

# application
app = out
srcApp = main.cpp

# targets
all: $(app)

# dependencies
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

# executable
$(app): $(obj) $(srcApp)
	$(CXX) $(CXXFLAGS) -o $@ $^

# clean objects
clean:
	rm -f *.o

# clean all project
mrproper: clean
	rm $(app)
