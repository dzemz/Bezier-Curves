#include "BezierCurve.h"
#include "DeCasteljau.h"
#include "Bernstein.h"
#include "Utility.h"

extern int screen_points[][2];
extern int point_counter;

void BezierCurve::display(void) {
// This funtion with registered with glutDisplayFunc();	
// Clears screen and displays points taken from user.
	
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glPointSize(7.0);

		for(int i = 0;i < point_counter ; i++)
		{	
			glBegin(GL_POINTS);
				glVertex2i(screen_points[i][0], glutGet( GLUT_WINDOW_HEIGHT ) - screen_points[i][1]);
			glEnd();
		}
		
		glColor3f(1.0,0,1.0);
		glFlush();

	}
	
void BezierCurve::keyPressed(unsigned char key, int x, int y) {  
// This funtion with registered with glutKeyboardFunc();	
  
		if(key == 119) // translate up ; key = 'w'
		{ 				
			glTranslatef(1.0, 10.0, 0.0);	
			glutPostRedisplay();
	
		}  
		if(key == 97)  // translate right; key = 'd'
		{
			glTranslatef(-10.0, 1.0, 0.0);
			glutPostRedisplay();	
			
								
		}
		if(key == 115)  // traslate down; key = 's'
		{
			glTranslatef(1, -10, 0.0);
			glutPostRedisplay();	
				
		}
		if(key == 100)  // translate left; key = 'd'
		{
			glTranslatef(10.0, 1.0, 0.0);
			
			glutPostRedisplay();	
		
								
		}
		if(key == 114)  // rotate anti-clock wise about z-axis; key: 'r'
		{
			glRotatef(0.38, 0.0, 0.0,1.0);
			
			glutPostRedisplay();						
		}
		if(key == 116)  // rotation clock wise; key : 't'
		{
			glRotatef(-0.38, 0.0, 0.0,1.0);
			
			glutPostRedisplay();						
		}
		if(key == 105)  // zoom in: key 'i' 
		{
			glScalef(1.1,1.1,1.0);
			
			glutPostRedisplay();						
		}
		if(key == 111)  // zoom out: key 'o'
		{
			glScalef(0.9,0.9,1.0);
		
			glutPostRedisplay();						
		}
		
		
		
    
    
    }  
	

void BezierCurve::mouseHandler(int btn,int state,int x,int y){
// This funtion with registered with glutMouseFunc();	
		
		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){ 
		// fetchs point on the screen given by user.		
		
			glBegin(GL_POINTS);
				glVertex2i(x, glutGet( GLUT_WINDOW_HEIGHT ) - y);				
			glEnd();

			glFlush();
		
			screen_points[point_counter][0] = x;
			screen_points[point_counter][1] = y;
			point_counter++;
		
	  	}
		
	}

	void BezierCurve::myinit(void)
	{
		glClearColor(1.0,1.0,0.5,0.0);
		glColor3f(1.0f,1.0f,1.0f);
		glPointSize(10.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0,640,0,480);
	}

	void BezierCurve::resize(int width, int height){
	    glViewport(0, 0, width, height);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
	    glOrtho(0, width, 0, height, -1, 1);
	    glMatrixMode(GL_MODELVIEW);
	}

	void BezierCurve::menuHandler(int id)
// This funtion with registered with glutCreateMenu();
	{
		
		switch(id)
		{
			case 1:  // for drawing bezier curve using bernstein polynomail method.
			
			Bernstein bernsteinObj; 
			bernsteinObj.paintBernsteinCurve(screen_points, point_counter);
			
				break;
			case 2: // for drawing bezier curve using DeCasteljau iterative method.
			
			DeCasteljau deObj;
			deObj.paintDeCasteljauCurve(screen_points, point_counter);  
			
				break;
			case 3: 
			
			// intentionally left blank
			 break;

			case 4: // clear scene; resets points  
			
			point_counter = 0;   // 
			glutPostRedisplay();
			
			 break;
			
			case 5: exit(0); break;
		}
	
	}


