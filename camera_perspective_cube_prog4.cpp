Draw a color cube and allow the user to move the camera suitably to experiment with perspective viewing. <b>Positioning of Camera</b>




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
