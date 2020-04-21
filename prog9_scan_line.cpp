Develop a menu driven program to fill the polygon using scan line algorithm






#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
float x1,x2,x3,x4,y1,y2,y3,y4;

void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-y1)<0)
	{
		temp=y1;y1=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
		x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;
	}
}

void draw_pixel(int x,int y)
{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
