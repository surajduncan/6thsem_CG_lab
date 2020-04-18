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
void displaySolid(void)
{
	GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS, mat_shininess);

	GLfloat lightintensity[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat lightposition[]={2.0f,6.0f,3.0f,0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winht=1.0;
	glOrtho(-winht*64/48, winht*64/48, -winht, winht,0.1, 100.0);
