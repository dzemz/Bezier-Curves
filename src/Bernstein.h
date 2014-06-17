#include<GL/glut.h>


extern int screen_points[][2];
extern int point_counter;

class Bernstein
{
	private: 

	float factorial(int);		 
	float ncr(int,int);
	double power(double , double);

	public: 
	
	void paintBernsteinCurve(int [][2],int);

};


