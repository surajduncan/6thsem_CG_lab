
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat vertices[ ]={  -1.0,-1.0,-1.0,
						1.0,-1.0,-1.0,
						1.0, 1.0,-1.0,
					   -1.0, 1.0,-1.0,
                       -1.0,-1.0, 1.0,
                        1.0,-1.0, 1.0,
                        1.0, 1.0, 1.0,
                       -1.0, 1.0, 1.0 };

GLfloat normals[ ] ={  -1.0,-1.0,-1.0,
						1.0,-1.0,-1.0,
						1.0, 1.0,-1.0,
					   -1.0, 1.0,-1.0,
					   -1.0,-1.0, 1.0,
						1.0,-1.0, 1.0,
						1.0, 1.0, 1.0,
					   -1.0, 1.0, 1.0 };

GLfloat colors[ ]={ 0.0, 0.0, 0.0,
					1.0, 0.0, 0.0,
					1.0, 1.0, 0.0,
					0.0, 1.0, 0.0,
					0.0, 0.0, 1.0,
					1.0, 0.0, 1.0,
					1.0, 1.0, 1.0,
					0.0, 1.0, 1.0};

GLubyte cubeIndices[]={ 0,3,2,1,
						2,3,7,6,
						0,4,7,3,
						1,2,6,5,
						4,5,6,7,
						0,1,5,4};

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
static GLdouble viewer[] = {0.0,0.0,5.0};
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2],0.0,0.0,0.0,0.0,1.0,0.0);
	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
	glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeIndices);
	glFlush();
	glutSwapBuffers();
}
