#include<GL/glut.h>
void wall(double thickness)
{
	glPushMatrix();
	glTranslated(0.5,0.5*thickness, 0.5);
	glScaled(1.0,thickness, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();
}
void tableleg(double thick, double len)
{
	glPushMatrix();
	glTranslated(0,len/2,0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

