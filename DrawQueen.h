#ifndef DRAWQUEEN_H_INCLUDED
#define DRAWQUEEN_H_INCLUDED
#include <GL/glut.h>
//Includes the OpenGL code to draw a 3D queen
//The letters in the comments correspond to different parts of a queen
//They align with points on one of my drawings on paper of a queen
//Letter 'A' is at the very top of the queen

int DrawQueen(int x, int y)
{
	float scale = 3.72 * 4.0;
	GLUquadricObj* object;
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_FILL);
	gluQuadricNormals(object, GL_SMOOTH);
	gluQuadricTexture(object, GL_TRUE);
	//A-AA
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.82 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .17 / scale, 0, .18 / scale, 10, 10);
	glPopMatrix();
	//AA-B
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.54 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .23 / scale, .17 / scale, .28 / scale, 10, 10);
	glPopMatrix();
	//B-C
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.40 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .72 / scale, .23 / scale, .14 / scale, 10, 10);
	glPopMatrix();
	//C-D
	//change the direction of the normals because we'll actually be seeing the inside of the cylinder.
	gluQuadricOrientation(object, GLU_INSIDE);
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.40 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .86 / scale, .72 / scale, .14 / scale, 10, 10);
	glPopMatrix();
	gluQuadricOrientation(object, GLU_OUTSIDE);
	//D-E(disk)
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.54 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .86 / scale, 1.06 / scale, 10, 10);
	glPopMatrix();
	//E-F
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.05 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .72 / scale, 1.06 / scale, .49 / scale, 10, 10);
	glPopMatrix();
	//F-G
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.22 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .72 / scale, .83 / scale, .83 / scale, 15, 15);
	glPopMatrix();
	//G-H
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.12 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .87 / scale, .72 / scale, .1 / scale, 10, 10);
	glPopMatrix();
	//H-I
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.02 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .72 / scale, .87 / scale, .1 / scale, 10, 10);
	glPopMatrix();
	//I-J
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.69 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .9 / scale, .72 / scale, .33 / scale, 10, 10);
	glPopMatrix();
	//J-K
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.16 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.39 / scale, .9 / scale, .53 / scale, 10, 10);
	glPopMatrix();
	//K-L
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.08 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.28 / scale, 1.39 / scale, .08 / scale, 10, 10);
	glPopMatrix();
	//L-M
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.97 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .69 / scale, 1.28 / scale, .11 / scale, 10, 10);
	glPopMatrix();
	//M-N
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.81 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.04 / scale, .69 / scale, 2.16 / scale, 20, 10);
	glPopMatrix();
	//N-O (Disk)
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.81 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 1.04 / scale, 1.18 / scale, 10, 10);
	glPopMatrix();
	//O-P
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.21 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.18 / scale, 1.18 / scale, .6 / scale, 10, 10);
	glPopMatrix();
	//P-Q
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .6 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.59 / scale, 1.18 / scale, .61 / scale, 10, 10);
	glPopMatrix();
	//Q-R
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .37 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.46 / scale, 1.59 / scale, .23 / scale, 10, 10);
	glPopMatrix();
	//R-S
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .31 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.59 / scale, 1.46 / scale, .06 / scale, 10, 10);
	glPopMatrix();
	//S-T
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0.0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.59 / scale, 1.59 / scale, .31 / scale, 10, 10);
	glPopMatrix();
	//Base
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0.0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, 1.59 / scale, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(object);
	return 0;

}


#endif // DRAWQUEEN_H_INCLUDED
