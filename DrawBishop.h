#ifndef DRAWBISHOP_H_INCLUDED
#define DRAWBISHOP_H_INCLUDED
#include <GL/glut.h>
//Includes the OpenGL code to draw a 3D bishop
//The letters in the comments correspond to different parts of a bishop
//They align with points on one of my drawings on paper of a bishop
//Letter 'A' is at the very top of the bishop

int DrawBishop(int x, int y)
{
	float scale = 3.72 * 4.0;
	GLUquadricObj* object;
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_FILL);
	gluQuadricNormals(object, GL_SMOOTH);
	gluQuadricTexture(object, GL_TRUE);
	//head
	//A-B
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.6 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .35 / scale, 0, .16 / scale, 10, 10);
	glPopMatrix();
	//B-C
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.38 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .30 / scale, .35 / scale, .22 / scale, 10, 10);
	glPopMatrix();
	//C-D
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.11 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .52 / scale, .30 / scale, .27 / scale, 10, 10);
	glPopMatrix();
	//D-E
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.72 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .72 / scale, .52 / scale, .39 / scale, 10, 15);
	glPopMatrix();
	//E-F
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.37 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .80 / scale, .72 / scale, .35 / scale, 10, 15);
	glPopMatrix();
	//F-G
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.11 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .82 / scale, .80 / scale, .26 / scale, 10, 10);
	glPopMatrix();
	//G-H
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.11 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .69 / scale, .82 / scale, 10, 10);
	glPopMatrix();
	//H-I
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.06 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .69 / scale, .69 / scale, .05 / scale, 10, 10);
	glPopMatrix();
	//I-J
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.95 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .82 / scale, .69 / scale, .11 / scale, 10, 10);
	glPopMatrix();
	//J-J2
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.71 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .6 / scale, .82 / scale, .24 / scale, 10, 10);
	glPopMatrix();
	//J2-K
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.52 / scale, (y + .5) / 4.00);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .6 / scale, .6 / scale, .19 / scale, 10, 10);
	glPopMatrix();
	//K-L
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.46 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .82 / scale, .6 / scale, .06 / scale, 10, 10);
	glPopMatrix();
	//L-M
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.29 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .65 / scale, .82 / scale, .17 / scale, 10, 10);
	glPopMatrix();
	//M-N
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.07 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.05 / scale, .65 / scale, .22 / scale, 15, 10);
	glPopMatrix();
	//N-O
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 2.88 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .93 / scale, 1.05 / scale, .19 / scale, 10, 10);
	glPopMatrix();
	//O-P
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 2.3 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .54 / scale, .93 / scale, .05 / scale, 10, 10);
	glPopMatrix();
	//P-Q
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.35 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .79 / scale, .54 / scale, 1.48 / scale, 15, 30);
	glPopMatrix();
	//Q-R
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.35 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .79 / scale, .96 / scale, 10, 10);
	glPopMatrix();
	//R-S
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .91 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.01 / scale, .96 / scale, .44 / scale, 10, 20);
	glPopMatrix();
	//S-T
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .49 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.42 / scale, 1.01 / scale, .42 / scale, 10, 20);
	glPopMatrix();
	//T-U
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .39 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.31 / scale, 1.42 / scale, .1 / scale, 10, 10);
	glPopMatrix();
	//U-V
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .19 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.42 / scale, 1.31 / scale, .2 / scale, 10, 15);
	glPopMatrix();
	//V-W
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.42 / scale, 1.42 / scale, .19 / scale, 10, 15);
	glPopMatrix();
	//bottom disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, 1.42 / scale, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(object);
	return 0;
}


#endif // DRAWBISHOP_H_INCLUDED
