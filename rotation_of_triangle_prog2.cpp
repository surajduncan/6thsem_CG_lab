#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

GLsizei winWidth = 600, winHeight = 600;
GLfloat xwcMin = 0.0, xwcMax = 225.0;
GLfloat ywcMin = 0.0, ywcMax = 225.0;

class wcPt2D
{
	public: GLfloat x, y;
};

typedef GLfloat Matrix3x3 [3][3];
Matrix3x3 matComposite;
const GLdouble pi = 3.14159;
void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void matrix3x3SetIdentity (Matrix3x3 matIdent3x3)
{
	GLint row, col;
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			matIdent3x3 [row][col] = (row == col);
}
