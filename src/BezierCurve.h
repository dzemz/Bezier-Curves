#include<GL/glut.h>
#include<stdio.h>

extern int screen_points[][2];
extern int point_counter;

class BezierCurve
{
	public:
	static void keyPressed(unsigned char , int , int ); 
	static void display(void);
	static void mouseHandler(int ,int ,int ,int );
	static void myinit();
	static void resize(int , int );
	static void menuHandler(int );

};

