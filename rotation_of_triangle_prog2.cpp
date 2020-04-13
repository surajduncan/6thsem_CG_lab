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
void matrix3x3PreMultiply (Matrix3x3 m1, Matrix3x3 m2)
{
	GLint row, col;
	Matrix3x3 matTemp;
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3 ; col++)
			matTemp [row][col] = m1 [row][0] * m2 [0][col] + m1 [row][1] *	m2 [1][col] + m1 [row][2] * m2 [2][col];	
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			m2 [row][col] = matTemp [row][col];
}

void translate2D (GLfloat tx, GLfloat ty)
{
	Matrix3x3 matTransl;
	matrix3x3SetIdentity (matTransl);
	matTransl [0][2] = tx;
	matTransl [1][2] = ty;
	matrix3x3PreMultiply (matTransl, matComposite);
}
