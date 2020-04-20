Develop a menu driven program to animate a flag using Bezier Curve algorithm




#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void bezierCoefficients(int n,int *c)
{
	int k,i;
	for(k=0;k<=n;k++)
	{
		c[k]=1;
		for(i=n;i>=k+1;i--)
			c[k]*=i;
		for(i=n-k;i>=2;i--)
			c[k]/=i;
	}
}
