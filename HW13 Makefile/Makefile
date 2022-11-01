OPT	:= #-O2
DEBUG	:= -g
CXX	:= g++ $(DEBUG) $(OPT)
LIBS	:= -lwebp -lfreetype

# textformatter: textformatter.cc
#	$(CXX) $< -o $@ -lwebp

# these are the objects that make up the program
OBJ	:= font.o font_face.o glyph.o color.o main.o
testformatter: $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LIBS)

font.o: font.cc font.hh
	$(CXX) -c $<  # just compile and build the .o file

font_face.o: font_face.cc font_face.hh
	$(CXX) -c $<  # just compile and build the .o file

glyph.o:

color.o:

main.o:
	$(CXX) -c $<