#include<GL/glut.h>
#include<stdio.h>
#include "Utility.h"


void Utility::paintString(int x,int y,int size, char *str)
// paints string str; at x,y ; length of string = size
	{
		glRasterPos2i(10,20);
		for(int i=0;i<size;i++)
		{
			char s = str[i];
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s);
		}
				
		glFlush();	
	}
	

