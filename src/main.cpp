#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include "Bernstein.h"
#include "DeCasteljau.h"
#include "BezierCurve.h"
#define GLfloat float
#define GLint int

int screen_points[30][2];
int point_counter;


using namespace std;

int main(int argc,char ** argv)
{

		glutInit(&argc,argv);	
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
		glutInitWindowSize(640,480);
		glutCreateWindow(" CS606: COMPUTER GRAPHICS; Assignment 1:Bezier curve ");
		glutMouseFunc(BezierCurve::mouseHandler);
		glutDisplayFunc(BezierCurve::display);
		glutReshapeFunc(BezierCurve::resize);
		glutKeyboardFunc(BezierCurve::keyPressed);
		BezierCurve::myinit;

		glutCreateMenu(BezierCurve::menuHandler);
		glutAddMenuEntry(" Bernstein Polynomial algorithm ",1);
		glutAddMenuEntry(" DeCasteljau algorithm ",2);			
		glutAddMenuEntry(" Clear screen ",4);
		glutAddMenuEntry(" Quit ",5);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
		
		glutMainLoop();
			
}

