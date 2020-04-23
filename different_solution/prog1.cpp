#include<stdio.h>
#include<math.h>
#include<iostream>
#include<GL/glut.h>

int xstart, ystart, xend, yend;
void init()
{
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void LineBres(int xstart, int ystart, int xend, int yend)
{
	int dx = abs(xend - xstart);
	int dy = abs(yend - ystart);
	int twody = 2 * dy, twodyminusdx = 2 * (dy - dx);
	int p = 2 * dy - dx;
	int x, y;
	if (xstart > xend)
	{
		x = xend;
		y = yend;
		xend = xstart;
	}
	else
	{
		x = xstart;
		y = ystart;

	}
	draw_pixel(x, y);
	while (x < xend)
	{
		x++;
		if (p < 0)
			p += twody;
		else
		{
			y++;
			p += twodyminusdx;
		}
		draw_pixel(x, y);
	}
}
