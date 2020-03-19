#ifndef DRAWKING_H_INCLUDED
#define DRAWKING_H_INCLUDED
#include <GL/glut.h>
#include "DrawCal.h"
//Includes the OpenGL code to draw a 3D king
//The letters in the comments correspond to different parts of a king
//They align with points on one of my drawings on paper of a king
//Letter 'A' is at the very top of the king

int DrawKing(int x, int y)
{

	float scale = 3.72 * 4.0;

	float Atoppeak[] = { 0, 8.02, .2 };   float ABtoppeak[] = { 0, 8.02, -.2 };
	float Btopside[] = { .31, 7.81, .2 }; float BBtopside[] = { .31, 7.81, -.2 };
	float BLtopside[] = { -.31, 7.81, .2 }; float BLBtopside[] = { -.31, 7.81, -.2 };
	float Ctopinside[] = { .24, 7.70, .2 };   float CBtopinside[] = { .24, 7.70, -.2 };
	float CLtopinside[] = { -.24, 7.70, .2 }; float CLBtopinside[] = { -.24, 7.70, -.2 };
	float Duppermid[] = { .63, 7.70, .2 };    float DBuppermid[] = { .63, 7.70, -.2 };
	float DLuppermid[] = { -.63, 7.70, .2 };   float DLBuppermid[] = { -.63, 7.70, -.2 };
	float Elowermid[] = { .63, 7.15, .2 };    float EBlowermid[] = { .63, 7.15, -.2 };
	float ELlowermid[] = { -.63, 7.15, .2 };     float ELBlowermid[] = { -.63, 7.15, -.2 };
	float Fmidinside[] = { .30, 7.15, .2 }; float FBmidinside[] = { .30, 7.15, -.2 };
	float FLmidinside[] = { -.30, 7.15, -.2 }; float FLBmidinside[] = { -.30, 7.15, -.2 };
	float Glowerside[] = { .51, 6.89, .2 };   float GBlowerside[] = { .51, 6.89, -.2 };
	float GLlowerside[] = { -.51, 6.89, .2 };
	float HBlowerinside[] = { .47, 6.85, -.2 };
	float HLlowerinside[] = { -.47, 6.85, .2 }; float HLBlowerinside[] = { -.47, 6.85, -.2 };
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glBegin(GL_POLYGON);
	//Front Diamond
	float temp1[3];
	float temp2[3];
	float temp3[3];
	subtract3f(Atoppeak, Btopside, temp1);
	subtract3f(Btopside, Ctopinside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(0, 8.02 / scale); glVertex3f(0, 8.02 / scale, .2 / scale);
	glTexCoord2f(.31 / scale, 7.81 / scale); glVertex3f(.31 / scale, 7.81 / scale, .2 / scale);
	glTexCoord2f(.24 / scale, 7.70 / scale); glVertex3f(.24 / scale, 7.70 / scale, .2 / scale);
	glTexCoord2f(-.24 / scale, 7.70 / scale); glVertex3f(-.24 / scale, 7.70 / scale, .2 / scale);
	glTexCoord2f(-.31 / scale, 7.81 / scale); glVertex3f(-.31 / scale, 7.81 / scale, .2 / scale);
	glEnd();
	glBegin(GL_QUADS);
	//Middle Rectangle
	glTexCoord2f(.63 / scale, 7.70 / scale); glVertex3f(.63 / scale, 7.70 / scale, .2 / scale);
	glTexCoord2f(.63 / scale, 7.15 / scale); glVertex3f(.63 / scale, 7.15 / scale, .2 / scale);
	glTexCoord2f(-.63 / scale, 7.15 / scale); glVertex3f(-.63 / scale, 7.15 / scale, .2 / scale);
	glTexCoord2f(-.63 / scale, 7.70 / scale); glVertex3f(-.63 / scale, 7.70 / scale, .2 / scale);

	//Bottom Triangle
	glTexCoord2f(.30 / scale, 7.15 / scale); glVertex3f(.30 / scale, 7.15 / scale, .2 / scale);
	glTexCoord2f(-.3 / scale, 7.15 / scale); glVertex3f(-.30 / scale, 7.15 / scale, .2 / scale);
	glTexCoord2f(-.51 / scale, 6.89 / scale); glVertex3f(-.51 / scale, 6.89 / scale, .2 / scale);
	glTexCoord2f(.51 / scale, 6.89 / scale); glVertex3f(.51 / scale, 6.89 / scale, .2 / scale);

	//Bottom Half of Bottom Triangle
	glTexCoord2f(.51 / scale, 6.89 / scale); glVertex3f(.51 / scale, 6.89 / scale, .2 / scale);
	glTexCoord2f(-.51 / scale, 6.89 / scale); glVertex3f(-.51 / scale, 6.89 / scale, .2 / scale);
	glTexCoord2f(-.47 / scale, 6.85 / scale); glVertex3f(-.47 / scale, 6.85 / scale, .2 / scale);
	glTexCoord2f(.47 / scale, 6.85 / scale); glVertex3f(.47 / scale, 6.85 / scale, .2 / scale);

	glEnd();
	subtract3f(ABtoppeak, BBtopside, temp1);
	subtract3f(BBtopside, CBtopinside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	//Back Diamond
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 8.02 / scale); glVertex3f(0, 8.02 / scale, -.2 / scale);
	glTexCoord2f(.31 / scale, 7.81 / scale); glVertex3f(.31 / scale, 7.81 / scale, -.2 / scale);
	glTexCoord2f(.24 / scale, 7.70 / scale); glVertex3f(.24 / scale, 7.70 / scale, -.2 / scale);
	glTexCoord2f(-.24 / scale, 7.70 / scale); glVertex3f(-.24 / scale, 7.70 / scale, -.2 / scale);
	glTexCoord2f(-.31 / scale, 7.81 / scale); glVertex3f(-.31 / scale, 7.81 / scale, -.2 / scale);
	glEnd();
	//Back of Middle Rectangle
	glBegin(GL_QUADS);
	glTexCoord2f(.63 / scale, 7.70 / scale); glVertex3f(.63 / scale, 7.70 / scale, -.2 / scale);
	glTexCoord2f(.63 / scale, 7.15 / scale); glVertex3f(.63 / scale, 7.15 / scale, -.2 / scale);
	glTexCoord2f(-.63 / scale, 7.15 / scale); glVertex3f(-.63 / scale, 7.15 / scale, -.2 / scale);
	glTexCoord2f(-.63 / scale, 7.70 / scale); glVertex3f(-.63 / scale, 7.70 / scale, -.2 / scale);

	//Back of Bottom Triangle
	glTexCoord2f(.30 / scale, 7.15 / scale); glVertex3f(.30 / scale, 7.15 / scale, -.2 / scale);
	glTexCoord2f(-.30 / scale, 7.15 / scale); glVertex3f(-.30 / scale, 7.15 / scale, -.2 / scale);
	glTexCoord2f(-.51 / scale, 6.89 / scale); glVertex3f(-.51 / scale, 6.89 / scale, -.2 / scale);
	glTexCoord2f(.51 / scale, 6.89 / scale); glVertex3f(.51 / scale, 6.89 / scale, -.2 / scale);
	//Back Bottom Half of Bottom Triangle
	glTexCoord2f(.51 / scale, 6.89 / scale); glVertex3f(.51 / scale, 6.89 / scale, -.2 / scale);
	glTexCoord2f(-.51 / scale, 6.89 / scale); glVertex3f(-.51 / scale, 6.89 / scale, -.2 / scale);
	glTexCoord2f(-.47 / scale, 6.85 / scale); glVertex3f(-.47 / scale, 6.85 / scale, -.2 / scale);
	glTexCoord2f(.47 / scale, 6.85 / scale); glVertex3f(.47 / scale, 6.85 / scale, -.2 / scale);

	//Sides of middle rectangle
	subtract3f(Ctopinside, CBtopinside, temp1);
	subtract3f(CBtopinside, Duppermid, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.24 / scale, 7.70 / scale); glVertex3f(.24 / scale, 7.70 / scale, .2 / scale);
	glTexCoord2f(.24 / scale, 7.70 / scale); glVertex3f(.24 / scale, 7.70 / scale, -.2 / scale);
	glTexCoord2f(.63 / scale, 7.70 / scale); glVertex3f(.63 / scale, 7.70 / scale, -.2 / scale);
	glTexCoord2f(.63 / scale, 7.70 / scale); glVertex3f(.63 / scale, 7.70 / scale, .2 / scale);

	subtract3f(Duppermid, DBuppermid, temp1);
	subtract3f(DBuppermid, Elowermid, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.63 / scale, 7.70 / scale); glVertex3f(.63 / scale, 7.70 / scale, -.2 / scale);
	glVertex3f(.63 / scale, 7.70 / scale, .2 / scale);
	glTexCoord2f(.63 / scale, 7.15 / scale); glVertex3f(.63 / scale, 7.15 / scale, .2 / scale);
	glVertex3f(.63 / scale, 7.15 / scale, -.2 / scale);

	subtract3f(EBlowermid, Elowermid, temp1);
	subtract3f(Elowermid, Fmidinside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glVertex3f(.63 / scale, 7.15 / scale, -.2 / scale);
	glVertex3f(.63 / scale, 7.15 / scale, .2 / scale);
	glTexCoord2f(.30 / scale, 7.15 / scale); glVertex3f(.30 / scale, 7.15 / scale, .2 / scale);
	glVertex3f(.30 / scale, 7.15 / scale, -.2 / scale);

	subtract3f(CLtopinside, CLBtopinside, temp1);
	subtract3f(CLBtopinside, DLuppermid, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.24 / scale, 7.70 / scale); glVertex3f(-.24 / scale, 7.70 / scale, .2 / scale);
	glVertex3f(-.24 / scale, 7.70 / scale, -.2 / scale);
	glTexCoord2f(-.63 / scale, 7.70 / scale); glVertex3f(-.63 / scale, 7.70 / scale, -.2 / scale);
	glVertex3f(-.63 / scale, 7.70 / scale, .2 / scale);

	subtract3f(DLBuppermid, DLuppermid, temp1);
	subtract3f(DLuppermid, ELlowermid, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.63 / scale, 7.70 / scale); glVertex3f(-.63 / scale, 7.70 / scale, -.2 / scale);
	glVertex3f(-.63 / scale, 7.70 / scale, .2 / scale);
	glTexCoord2f(-.63 / scale, 7.15 / scale); glVertex3f(-.63 / scale, 7.15 / scale, .2 / scale);
	glVertex3f(-.63 / scale, 7.15 / scale, -.2 / scale);

	subtract3f(ELBlowermid, ELlowermid, temp1);
	subtract3f(ELlowermid, FLmidinside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.63 / scale, 7.15 / scale); glVertex3f(-.63 / scale, 7.15 / scale, -.2 / scale);
	glVertex3f(-.63 / scale, 7.15 / scale, .2 / scale);
	glTexCoord2f(-.3 / scale, 7.15 / scale); glVertex3f(-.30 / scale, 7.15 / scale, .2 / scale);
	glVertex3f(-.30 / scale, 7.15 / scale, -.2 / scale);

	//Sides of diamond
	subtract3f(ABtoppeak, BBtopside, temp1);
	subtract3f(BBtopside, Btopside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(0, 8.02 / scale); glVertex3f(0, 8.02 / scale, -.2 / scale);
	glTexCoord2f(.31 / scale, 7.81 / scale); glVertex3f(.31 / scale, 7.81 / scale, -.2 / scale);
	glVertex3f(.31 / scale, 7.81 / scale, .2 / scale);
	glTexCoord2f(0, 8.02 / scale); glVertex3f(0, 8.02 / scale, .2 / scale);

	subtract3f(BBtopside, Btopside, temp1);
	subtract3f(Btopside, Ctopinside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.31 / scale, 7.81 / scale); glVertex3f(.31 / scale, 7.81 / scale, -.2 / scale);
	glVertex3f(.31 / scale, 7.81 / scale, .2 / scale);
	glTexCoord2f(.24 / scale, 7.70 / scale); glVertex3f(.24 / scale, 7.70 / scale, .2 / scale);
	glVertex3f(.24 / scale, 7.70 / scale, -.2 / scale);

	subtract3f(ABtoppeak, BLBtopside, temp1);
	subtract3f(BLBtopside, BLtopside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(0, 8.02 / scale); glVertex3f(0, 8.02 / scale, -.2 / scale);
	glTexCoord2f(-.31 / scale, 7.81 / scale); glVertex3f(-.31 / scale, 7.81 / scale, -.2 / scale);
	glVertex3f(-.31 / scale, 7.81 / scale, .2 / scale);
	glTexCoord2f(0, 8.02 / scale); glVertex3f(0, 8.02 / scale, .2 / scale);

	subtract3f(BLBtopside, BLtopside, temp1);
	subtract3f(BLtopside, CLtopinside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.31 / scale, 7.81 / scale); glVertex3f(-.31 / scale, 7.81 / scale, -.2 / scale);
	glVertex3f(-.31 / scale, 7.81 / scale, .2 / scale);
	glTexCoord2f(-.24 / scale, 7.70 / scale); glVertex3f(-.24 / scale, 7.70 / scale, .2 / scale);
	glVertex3f(-.24 / scale, 7.70 / scale, -.2 / scale);


	//Sides of bottom triangle
	subtract3f(Fmidinside, FBmidinside, temp1);
	subtract3f(FBmidinside, Glowerside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.3 / scale, 7.15 / scale); glVertex3f(.30 / scale, 7.15 / scale, .2 / scale);
	glVertex3f(.30 / scale, 7.15 / scale, -.2 / scale);
	glTexCoord2f(.51 / scale, 6.89 / scale); glVertex3f(.51 / scale, 6.89 / scale, -.2 / scale);
	glVertex3f(.51 / scale, 6.89 / scale, .2 / scale);

	subtract3f(FLmidinside, FLBmidinside, temp1);
	subtract3f(FLBmidinside, GLlowerside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.3 / scale, 7.15 / scale); glVertex3f(-.30 / scale, 7.15 / scale, .2 / scale);
	glVertex3f(-.30 / scale, 7.15 / scale, -.2 / scale);
	glTexCoord2f(-.51 / scale, 6.89 / scale); glVertex3f(-.51 / scale, 6.89 / scale, -.2 / scale);
	glVertex3f(-.51 / scale, 6.89 / scale, .2 / scale);
	//Sides of Bottom Triangle Bottom Half
	subtract3f(HBlowerinside, GBlowerside, temp1);
	subtract3f(GBlowerside, Glowerside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glVertex3f(.51 / scale, 6.89 / scale, -.2 / scale);
	glTexCoord2f(.47 / scale, 6.85 / scale); glVertex3f(.47 / scale, 6.85 / scale, -.2 / scale);
	glVertex3f(.47 / scale, 6.85 / scale, .2 / scale);
	glTexCoord2f(.51 / scale, 6.89 / scale); glVertex3f(.51 / scale, 6.89 / scale, .2 / scale);

	subtract3f(HLBlowerinside, HLlowerinside, temp1);
	subtract3f(HLlowerinside, GLlowerside, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.47 / scale, 6.85 / scale); glVertex3f(-.47 / scale, 6.85 / scale, -.2 / scale);
	glVertex3f(-.47 / scale, 6.85 / scale, .2 / scale);
	glTexCoord2f(-.51 / scale, 6.89 / scale); glVertex3f(-.51 / scale, 6.89 / scale, .2 / scale);
	glVertex3f(-.51 / scale, 6.89 / scale, -.2 / scale);

	glEnd();
	glPopMatrix();

	//Cylinders
	GLUquadricObj* object;
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_FILL);
	gluQuadricNormals(object, GL_SMOOTH);
	gluQuadricTexture(object, GL_TRUE);
	//H-I Disk and Top Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.85 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, .68 / scale, 10, 10);
	glPopMatrix();
	//I-J
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.69 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .82 / scale, .68 / scale, .16 / scale, 10, 10);
	glPopMatrix();
	//J-K
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 6.48 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.18 / scale, .82 / scale, .21 / scale, 15, 10);
	glPopMatrix();
	//K-L
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.38 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .88 / scale, 1.18 / scale, 1.1 / scale, 20, 10);
	glPopMatrix();
	//L-M
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.34 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .9 / scale, .88 / scale, .04 / scale, 10, 10);
	glPopMatrix();
	//M-N
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.22 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .9 / scale, .9 / scale, .12 / scale, 10, 10);
	glPopMatrix();
	//N-O
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 5.18 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .78 / scale, .9 / scale, .04 / scale, 10, 10);
	glPopMatrix();
	//O-P
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.79 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .78 / scale, .78 / scale, .39 / scale, 20, 20);
	glPopMatrix();
	//P-Q - Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.79 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .78 / scale, .86 / scale, 10, 10);
	glPopMatrix();
	//Q-R
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.66 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .86 / scale, .86 / scale, .11 / scale, 15, 10);
	glPopMatrix();
	//R-S
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.25 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.09 / scale, .86 / scale, .41 / scale, 20, 10);
	glPopMatrix();
	//S-T
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 4.09 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .53 / scale, 1.09 / scale, .16 / scale, 10, 10);
	glPopMatrix();
	//T-U
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.91 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, .88 / scale, .53 / scale, 2.18 / scale, 25, 10);
	glPopMatrix();
	//U-V - Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.91 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, .88 / scale, 1.02 / scale, 10, 10);
	glPopMatrix();
	//V-W
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.40 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.07 / scale, 1.02 / scale, .51 / scale, 15, 20);
	glPopMatrix();
	//W-X
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .67 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.51 / scale, 1.07 / scale, .73 / scale, 15, 10);
	glPopMatrix();
	//X-Y
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .42 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.37 / scale, 1.51 / scale, .25 / scale, 10, 10);
	glPopMatrix();
	//Y-Z
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .31 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.37 / scale, 1.51 / scale, .11 / scale, 10, 10);
	glPopMatrix();
	//Z-AA
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.51 / scale, 1.51 / scale, .31 / scale, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(object);
	return 0;
}


#endif // DRAWKING_H_INCLUDED
