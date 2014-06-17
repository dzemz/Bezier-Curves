paintcurve: main.o Bernstein.o DeCasteljau.o Utility.o BezierCurve.o 
	g++ -lglut -lGL -lGLU -o "$@" main.o BezierCurve.o Bernstein.o DeCasteljau.o Utility.o 
	
main.o: main.cpp BezierCurve.cpp Bernstein.cpp DeCasteljau.cpp 
	g++ -lglut -lGL -lGLU -c main.cpp BezierCurve.cpp Bernstein.cpp DeCasteljau.cpp 
BezierCurve.o: main.cpp BezierCurve.cpp Bernstein.cpp DeCasteljau.cpp Utility.cpp
	g++ -c main.cpp BezierCurve.cpp Utility.cpp Bernstein.cpp DeCasteljau.cpp
DeCateljau.o: DeCasteljau.cpp Utility.cpp
	g++ -lglut -lGL -lGLU -c DeCasteljau.cpp Utility.cpp 
Bernstein.o: Bernstein.cpp Utility.cpp
	g++ -lglut -lGL -lGLU -c Bernstein.cpp Utility.cpp
Utility.o: Utility.cpp
	g++ -lglut -lGL -lGLU -c Utility.cpp	
clean:
	rm *.o


