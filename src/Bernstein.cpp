#include<unistd.h>
#include<stdio.h>
#include "Bernstein.h"
#include "Utility.h"

float Bernstein::factorial(int n)  // computes factorial 
{
	int c; float result = 1.0;
		 
	for( c = 1 ; c <= n ; c++ )
		result = result*c;
		 
	return result;
}
	
float Bernstein::ncr(int n,int r) // computes nCr 
{
	   float result;
	   result = factorial(n)/(factorial(r)*factorial(n-r));
	   return result;
}

double Bernstein::power(double num, double n) // computes power(num^n)
{
	double result=1.0;
	
	if (n == 0)
		return 1.0;
		
	if(n == 1)
		return num;

	for ( int i = 1; i<=n ; i++ )
		result *= num;

	return result;
}

void Bernstein:: paintBernsteinCurve(int screen_points[][2], int point_counter) 
// Draws bezier curve using bernstein polynomial method
	{
		double tempX=0.0, tempY=0.0;
		int bezierPoints[105][2],counter=0,  n = point_counter-1,i;
		

		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(1,1,1);

		Utility u;
		char algoType[31] = "Berstein Polynomial algorithm";
		u.paintString(100,100,31,algoType);  // prints algoType string on the screen.
	
		glColor3f(1.0,0.0,0.0);
		
		glBegin(GL_POINTS);
		for(int i = 0;i < point_counter-1 ; i++)  // displays points on screen.
		{	
			glVertex2i(screen_points[i][0], glutGet( GLUT_WINDOW_HEIGHT ) - screen_points[i][1]);
			glVertex2i(screen_points[i+1][0], glutGet( GLUT_WINDOW_HEIGHT ) - screen_points[i+1][1]);  					
		}
 		glEnd();

		for(float t=0; t <= 1.0 ; t = t + 0.01)
		{
			tempX=0.0, tempY=0.0;
			for(i=0;i<point_counter;i++)
			{
				tempX += ( screen_points[i][0] * ncr(n,i) * power(t, i) * power((1.0-t), n-i) ) ;
				tempY += ( screen_points[i][1] * ncr(n,i) * power(t, i) * power((1.0-t), n-i) ) ;          	
			}				
			bezierPoints[counter][0]=tempX;
			bezierPoints[counter][1]=tempY;
			counter++;
		}

		bezierPoints[counter][0]= screen_points[point_counter-1][0] ;
		bezierPoints[counter][1]= screen_points[point_counter-1][1] ;
		
		
		for(i = 0;i < 100 ; i++)
		{	
			float temp = float(i+1)/100.0;
			
			glColor3f(temp,1-temp,0.5); // for color interpolation effects (visual delight)
			
			glBegin(GL_LINE_LOOP);
			    glVertex2i(bezierPoints[i][0], glutGet( GLUT_WINDOW_HEIGHT ) - bezierPoints[i][1]);
				glVertex2i(bezierPoints[i+1][0], glutGet( GLUT_WINDOW_HEIGHT ) - bezierPoints[i+1][1]);	
			glEnd();			
			
			glFlush();
			usleep(10000);   // for curve-drawing effect. 
			
		}	
		
		glFlush();		
	};	


