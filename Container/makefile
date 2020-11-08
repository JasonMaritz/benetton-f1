#http://www.gnu.org/software/make/manual/make.html

CXX = g++
#CXXFLAGS = -g -Wall -std=c++11							#For debugging
CXXFLAGS = -Wall -std=c++11
PROG  = main
#OBJS = main.o
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))


all: $(PROG)

run: $(PROG)
	./$(PROG)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(PROG): $(OBJS)
	$(CXX) -o $(PROG) $^ 
	rm -f $^						
#The above line removes .o files which are needed for debugging symbols (comment it out for debugging) -> #rm -f $^

cleanall:
	rm -f *.o $(PROG)

clean:
	rm -f *.o