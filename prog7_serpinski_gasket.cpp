





#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

typedef float point[3];
point v[]={ {0.0, 0.0, 1.0},
			{0.0, 0.942809, -0.33333}, 
			{-0.816497, -0.471405, -0.333333},
			{0.816497, -0.471405, -0.333333}};
static GLfloat theta[] = {0.0,0.0,0.0};
int n;
void triangle( point a, point b, point c)
{
	glBegin(GL_POLYGON);
	glNormal3fv(a);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide_triangle(point a, point b, point c, int m)
{
	point v1, v2, v3;
	int j;
	if(m>0)
	{
		for(j=0; j<3; j++)
			v1[j]=(a[j]+b[j])/2;
		for(j=0; j<3; j++)
			v2[j]=(a[j]+c[j])/2;
		for(j=0; j<3; j++)
			v3[j]=(b[j]+c[j])/2;
		divide_triangle(a, v1, v2, m-1);
		divide_triangle(c, v2, v3, m-1);
		divide_triangle(b, v3, v1, m-1);
	}
	else(triangle(a,b,c));
}
void tetrahedron( int m)
{
	glColor3f(1.0,0.0,0.0);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(0.0,1.0,0.0);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(0.0,0.0,1.0);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(0.0,0.0,0.0);
	divide_triangle(v[0], v[2], v[3], m);
}
