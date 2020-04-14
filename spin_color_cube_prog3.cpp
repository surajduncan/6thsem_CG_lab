#include<stdlib.h>
#include<GL/glut.h>

GLfloat vertices[]={-1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0,
					1.0,-1.0,-1.0,1.0,-1.0,-1.0,-1.0,1.0,
					1.0,-1.0,1.0,1.0,1.0,1.0,-1.0,1.0,1.0};

GLfloat colors[] = {0.0,0.0,0.0,1.0,0.0,0.0,1.0,1.0,0.0,
					0.0,1.0,0.0,0.0,0.0,1.0,1.0,0.0,
					1.0,1.0,1.0,1.0,0.0,1.0,1.0};

GLubyte cubeIndices[]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4, 5,6,7,0,1,5,4};
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glRotatef(theta[0],1.0,0.0,0.0);
  glRotatef(theta[1],0.0,1.0,0.0);
  glRotatef(theta[2],0.0,0.0,1.0);
  glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE, cubeIndices);
  glFlush();
  glutSwapBuffers();
}
void spinCube()
{
	theta[axis]+=2.0;
	if(theta[axis]>360.0) theta[axis]-=360.0;
		glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		axis=0;
	if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
		axis=1;
	if(btn==GLUT_RIGHT_BUTTON&& state==GLUT_DOWN)
		axis=2;
}
