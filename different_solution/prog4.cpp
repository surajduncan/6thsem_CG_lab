
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
