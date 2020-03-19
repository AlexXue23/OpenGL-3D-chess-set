#ifndef DRAWROOK_H_INCLUDED
#define DRAWROOK_H_INCLUDED
#include <GL/glut.h>
//Includes the OpenGL code to draw a 3D rook
//The letters in the comments correspond to different parts of a rook
//They align with points on one of my drawings on paper of a rook
//Letter 'A' is at the very top of the rook

int DrawRook(int x, int y)
{
	float scale = 3.72 * 4.0;
	GLUquadricObj* object;
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_FILL);
	gluQuadricNormals(object, GL_SMOOTH);
	gluQuadricTexture(object, GL_TRUE);
	//Disk at top
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.06 / scale, (y + .5) / 4.0);
	glRotatef(90, -1.0, 0.0, 0.0);
	gluDisk(object, 0, .92 / scale, 10, 10);
	glPopMatrix();
	//A-B
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.72 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .85 / scale, .96 / scale, .53 / scale, 10, 10);
	glPopMatrix();
	//B-C
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.61 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .88 / scale, .85 / scale, .09 / scale, 10, 10);
	glPopMatrix();
	//C-D
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.23 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .62 / scale, .88 / scale, .38 / scale, 10, 10);
	glPopMatrix();
	//D-E (Disk)
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 3.23 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .56 / scale, .62 / scale, 10, 10);
	glPopMatrix();
	//E-F
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.37 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .81 / scale, .56 / scale, 1.86 / scale, 15, 15);
	glPopMatrix();
	//F-G (disk)
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.37 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .81 / scale, .85 / scale, 10, 10);
	glPopMatrix();
	//G-H
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .91 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .85 / scale, .85 / scale, .46 / scale, 10, 10);
	glPopMatrix();
	//H-I
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .60 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.09 / scale, .85 / scale, .31 / scale, 10, 10);
	glPopMatrix();
	//I-J
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .33 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .98 / scale, 1.09 / scale, .27 / scale, 10, 10);
	glPopMatrix();
	//J-K
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .28 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.09 / scale, .98 / scale, .05 / scale, 10, 10);
	glPopMatrix();
	//K-L
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0.0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.09 / scale, 1.09 / scale, .28 / scale, 10, 10);
	glPopMatrix();
	//Bottom Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0.0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, 1.09 / scale, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(object);
	return 0;
}


#endif // DRAWROOK_H_INCLUDED
