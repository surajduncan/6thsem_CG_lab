#include<stdio.h>
#include<GL/glut.h>
int x,y;
int where_to_rotate=0;
float translate_x=0.0,translate_y=0.0,rotate_angle=0.0;
void draw_pixel(float x1,float y1)
{
	glPointSize(5.0);
	glBegin(GL_POINTS);
		glVertex2f(x1,y1);
	glEnd();
}
void triangle(int x,int y)
{
	glColor3f(0.0,1.0,0.0); // set interior color of triangle to green
	glBegin(GL_POLYGON);
		glVertex2f(x,y);
		glVertex2f(x+400,y+400);
		glVertex2f(x+300,y+0);
	glEnd();
	glFlush();
}
