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
