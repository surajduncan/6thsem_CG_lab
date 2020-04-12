#include <GL/glut.h>
#include <stdio.h>
int x1, y1, x2, y2;

void myInit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
