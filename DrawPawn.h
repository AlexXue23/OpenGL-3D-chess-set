#ifndef DRAWPAWN_H_INCLUDED
#define DRAWPAWN_H_INCLUDED
#include <GL/glut.h>
//Includes the OpenGL code to draw a 3D pawn
//The letters in the comments correspond to different parts of a pawn
//They align with points on one of my drawings on paper of a pawn
//Letter 'A' is at the very top of the pawn
//Just draws piece; Other functions check to see if square is taken or not

int DrawPawn(int x, int y)
{
	float scale = 3.72 * 4.0;
	GLUquadricObj* object;
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_FILL);
	gluQuadricNormals(object, GL_SMOOTH);
	gluQuadricTexture(object, GL_TRUE);
	//head
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, 3.18 / scale, (y + .5) / 4.0);
	gluSphere(object, .54 / scale, 10, 10);
	glPopMatrix();
	//B-C
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, (2.46f) / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .64 / scale, .25 / scale, .21 / scale, 10, 10);
	glPopMatrix();
	//C-D
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, 2.19f / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .48 / scale, .64 / scale, .27 / scale, 10, 10);
	glPopMatrix();
	//E-F
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, .98 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .80f / scale, .3 / scale, 1.21 / scale, 10, 10);
	glPopMatrix();
	//F-G - Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, .98 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .8 / scale, .83 / scale, 10, 10);
	glPopMatrix();
	//G-H
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, .41 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.2 / scale, .83f / scale, .57 / scale, 10, 10);
	glPopMatrix();
	//H-I
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, .32 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.25 / scale, 1.2 / scale, .09 / scale, 10, 10);
	glPopMatrix();
	//I-J
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, .22 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.2 / scale, 1.25 / scale, .1 / scale, 10, 10);
	glPopMatrix();
	//J-K
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, .18 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.25 / scale, 1.2 / scale, .04 / scale, 10, 10);
	glPopMatrix();
	//K-L
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, 0 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.25f / scale, 1.25f / scale, .18 / scale, 10, 10);
	glPopMatrix();
	//Base
	glPushMatrix();
	glTranslatef((x + .5) / 4.0f, 0.0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, 1.25 / scale, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(object);
	return 0;
}

#endif // DRAWPAWN_H_INCLUDED
