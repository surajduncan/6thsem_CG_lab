



#include<stdio.h>
#include<math.h>
#include<iostream>
#include<GL/glut.h>

float v[][3] = { { -1,-1,-1 } ,{ -1,1,-1 } ,{ 1,1,-1 } ,{ 1,-1,-1 } ,{ -1,-1,1 } ,{ -1,1,1 } ,{ 1,1,1 } ,{ 1,-1,1 } }; // 8 vertices of the cube with origin as its centroid
int t[] = { 0,0,0 };  // degree of rotation along {x,y,z}
int ax = 2; // axis of rotation

void init()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-4, 4, -4, 4, -10, 10);
	glMatrixMode(GL_MODELVIEW);  // location where your object gets modelled
}

void polygon(int a, int b, int c, int d)  // function used to draw one face of a cube at a time
{
	glBegin(GL_POLYGON);	// draw the square using polygon
	glVertex3fv(v[a]);		// 4 coordinates of the square face are give..
	glVertex3fv(v[b]);		// each v[i] contains 3 values (x,y,z) which denotes a point in 3D plane
	glVertex3fv(v[c]);
	glVertex3fv(v[d]);
	glEnd();
}
