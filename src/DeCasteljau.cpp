#include "DeCasteljau.h"
#include "Utility.h"	
#include<unistd.h>

void DeCasteljau:: paintDeCasteljauCurve(int screen_points[30][2], int point_counter)
// Draws bezier curve using decateljau's iterative method
	{

		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		
		glColor3f(1,1,1);

		Utility u;
		char algoType[25] = "DeCastelijau's algorithm";
		u.paintString(100,100,25,algoType);  // prints algoType string on the screen. at specified x,y co-ordinates.
		
		
		glColor3f(0.0,0.0,1.0);
	
		int counter = 0;
	
		for(int i = 0;i < point_counter-1 ; i++)
		{	
			glBegin(GL_POINTS);
			    glVertex2i(screen_points[i][0], glutGet( GLUT_WINDOW_HEIGHT ) - screen_points[i][1]);
			    glVertex2i(screen_points[i+1][0], glutGet( GLUT_WINDOW_HEIGHT ) - screen_points[i+1][1]);				
			glEnd();
		}

		for(float u=0; u<=1.0; u += 0.01)
		{	


			for(int i=0; i< point_counter ; i++)
			{
				pointx[i] = screen_points[i][0];
				pointy[i] = screen_points[i][1];
			}
			for(int k=1;k< point_counter ;k++)
			{
				for(int i=0;i< point_counter - k;i++)
				{
					pointx[i] = (1-u) * pointx[i] + u * pointx[i+1];
					pointy[i] = (1-u) * pointy[i] + u * pointy[i+1]; 	
					 	
				}
			}
	
		deAlgo[counter][0] = pointx[0];
		deAlgo[counter][1] = pointy[0];
		counter++;
		}

		deAlgo[counter][0] = screen_points[point_counter-1][0];
		deAlgo[counter][1] = screen_points[point_counter-1][1];
	
		for(int i = 0;i < 100 ; i++)
		{
			float temp = float(i+1)/100.0;	
			glColor3f(temp*2,1.0-temp,temp/2); // for color interpolation effects (visual delight)
		
			glBegin(GL_LINE_LOOP);
				glVertex2i(deAlgo[i][0], glutGet( GLUT_WINDOW_HEIGHT ) - deAlgo[i][1]);
				glVertex2i(deAlgo[i+1][0], glutGet( GLUT_WINDOW_HEIGHT ) - deAlgo[i+1][1]);				
			glEnd();
			
			glFlush();
			usleep(10000); // for curve-drawing effect. 
		}

	
		glFlush();
};


