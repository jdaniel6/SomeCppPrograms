OPT	:= #-O2
DEBUG	:= -g
CXX	:= g++ $(DEBUG) $(OPT)
LIBS := -lwebp -lfreetype


INC	:= -I'C:\msys64\mingw64\include\freetype2\' -I'C:\msys64\mingw64\include\webp\'
SRC := $(wildcard *.cc)
OBJS := $(SRC:.cc=.o)

# textformatter: textformatter.cc
#	$(CXX) $< -o $@ -lwebp

# these are the objects that make up the program
all	: main

main: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LIBS)

%.o: %.cc %.hh
	$(CXX) -c $< -o $@ $(INC)

clean:
	$(RM) -f *.o main