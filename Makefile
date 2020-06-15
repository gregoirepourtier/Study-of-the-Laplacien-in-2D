CXX = g++
CXXFLAGS = -std=c++11
SRCS = decompoCholesky.cpp decompoLU.cpp erreurResidu.cpp iteratif.cpp resol.cpp testDirectMethods.cpp testIteratMethods.cpp testResol.cpp tools.cpp
EXENAME = testResol

OBJS =  $(SRCS:%.cpp=%.o)
DEPS =  $(SRCS:%.cpp=%.d)

all: $(EXENAME)

$(EXENAME) : $(OBJS)
	$(CXX) $^ -o $@

-include $(DEPS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	rm -rf *.o *.d *~ *$(EXENAME)
