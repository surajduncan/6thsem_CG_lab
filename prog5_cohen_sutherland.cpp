#include<stdio.h>
#include<GL/glut.h>
#define outcode int

double xmin=50,ymin=50,xmax=100,ymax=100;
double xvmin=200,yvmin=200,xvmax=300,yvmax=300;
double x0,y0,x1,y1;
const int RIGHT=8;
const int LEFT=2;
const int TOP=4;
const int BOTTOM=1;
outcode ComputeOutCode(double x, double y);
void CohenSutherland(double x0, double y0, double x1, double y1)
{
	outcode outcode0, outcode1, outcodeOut;
	bool accept=false, done=false;
	outcode0=ComputeOutCode(x0,y0);
	outcode1=ComputeOutCode(x1,y1);
	do
	{
		if(!(outcode0 | outcode1))
		{
			accept=true;
			done=true;
		}
		else if(outcode0 & outcode1)
			done=true;
		else
		{
			double x, y;
			outcodeOut=outcode0?outcode0:outcode1;
			if(outcodeOut & TOP)
			{
				x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
				y=ymax;
			}
			else if(outcodeOut & BOTTOM)
			{
				x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
				y=ymin;
			}
			else if(outcodeOut & RIGHT)
			{
				y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
				x=xmax;
			}
			else
			{
				y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
				x=xmin;
			}
			if(outcodeOut==outcode0)
			{
				x0=x;
				y0=y;
				outcode0=ComputeOutCode(x0,y0);
			}
			else
			{
				x1=x;
				y1=y;
				outcode1=ComputeOutCode(x1,y1);
			}
		}
	}while(!done);
