



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
void colorcube()		//function used to color each face of the cube seperately
{
	glColor3f(0, 0, 1);		//color of front square
	polygon(0, 1, 2, 3);	// drawing the front square
	glColor3f(0, 1, 1);		// color of the left square
	polygon(4, 5, 6, 7);	// drawing the left square
	glColor3f(0, 1, 0);		// color of the right square
	polygon(0, 1, 5, 4);	// drawing the right square
	glColor3f(1, 0, 0);		// color of the top square
	polygon(2, 6, 7, 3);	// drawing the top square
	glColor3f(1, 1, 0);		// color of the bottom square
	polygon(0, 4, 7, 3);	// drawing the bottom square
	glColor3f(1, 0, 1);		// color of the back square
	polygon(1, 5, 6, 2);	// drawing the back square
}
void spincube()
{
	t[ax] += 1;	// rotating the cube by 1 degree at a time on the given axis "ax" ( ax = 0 is x axis , ax =1 is y axis , ax =2 is z axis)
	if (t[ax] == 360)
		t[ax] -= 360;	// when the rotation along any axis reaches 360 reset the axis to 0
	glutPostRedisplay();	// calling the display again..
}

