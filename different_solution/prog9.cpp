
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<GL/glut.h>
int le[500], re[500], flag=0 ,m;

void init()
{
	gluOrtho2D(0, 500, 0, 500);
}
void edge(int x0, int y0, int x1, int y1)
{
	if (y1<y0)
	{
		int tmp;
		tmp = y1;
		y1 = y0;
		y0 = tmp;
		tmp = x1;
		x1 = x0;
		x0 = tmp;
	}
	int x = x0;
	m = (y1 - y0) / (x1 - x0);
	for (int i = y0; i<y1; i++)
	{
		if (x<le[i])
			le[i] = x;
		if (x>re[i])
			re[i] = x;
		x += (1 / m);
	}
}

