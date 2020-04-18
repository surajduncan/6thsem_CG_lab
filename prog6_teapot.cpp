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
void tableleg(double thick, double len)
{
	glPushMatrix();
	glTranslated(0,len/2,0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void table(double topwid, double topthick, double legthick, double leglen)
{
	glPushMatrix();
	glTranslated(0,leglen,0);
	glScaled(topwid, topthick, topwid);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist=0.95*topwid/2.0-legthick/2.0;
	glPushMatrix();
	glTranslated(dist, 0, dist);
	tableleg(legthick, leglen);
	glTranslated(0.0,0.0,-2*dist);
	tableleg(legthick, leglen);
	glTranslated(-2*dist, 0, 2*dist);
	tableleg(legthick, leglen);
	glTranslated(0,0,-2*dist);
	tableleg(legthick,leglen);
	glPopMatrix();
}
