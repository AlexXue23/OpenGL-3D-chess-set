#ifndef DRAWKNIGHT_H_INCLUDED
#define DRAWKNIGHT_H_INCLUDED
#include <GL/glut.h>
#include "DrawCal.h"
//Includes the OpenGL code to draw a 3D knight
//The letters in the comments correspond to different parts of a knight
//They align with points on one of my drawings on paper of a knight
//Letter 'A' is at the very top of the knight
//Ending in the letter 'B' symbolizes that it is on the -z side of the knight

int DrawKnight(int x, int y)
{
	//Below are listed the vertices and their mirror on the back since the knight is symmetrical
	float scale = 3.72 * 4.0;
	float A[] = { -.4, 5.47, .31 };   float AB[] = { -.4, 5.47, -.31 };
	float B[] = { 0, 5.12, .19 };     float BB[] = { 0, 5.12, -.19 };
	float C[] = { .86, 4.48, .12 };   float CB[] = { .86, 4.48, -.12 };
	float D[] = { .78, 4.13, .16 };   float DB[] = { .78, 4.13, -.16 };
	float E[] = { .83, 3.99, .18 };   float EB[] = { .83, 3.99, -.18 };
	float E1[] = { .24, 4.86, .05 };  float E1B[] = { .24, 4.86, -.05 };
	float F[] = { .05, 3.84, .19 };   float FB[] = { .05, 3.84, -.19 };
	float G[] = { .89, 2.70, .22 };   float GB[] = { .89, 2.70, -.22 };
	float H[] = { .61, 1.99, .48 };   float HB[] = { .61, 1.99, -.48 };
	float P[] = { -.75, 1.91, .2 };   float PB[] = { -.75, 1.91, -.2 };
	float Q[] = { -1.06, 2.85, .1 };  float QB[] = { -1.06, 2.85, -.1 };
	float R[] = { -1.12, 3.51, .05 }; float RB[] = { -1.12, 3.51, -.05 };
	float S[] = { -.92, 4.22, .09 };  float SB[] = { -.92, 4.22, -.09 };
	float T[] = { -.48, 4.86, .28 };  float TB[] = { -.48, 4.86, -.28 };
	float U[] = { -.37, 4.32, .33 };  float UB[] = { -.37, 4.32, -.33 };
	float V[] = { -.25, 3.52, .38 };  float VB[] = { -.25, 3.52, -.38 };
	float W[] = { 0, 2.49, .40 };     float WB[] = { 0, 2.49, -.40 };
	float X[] = { .15, 2.49, .45 };   float XB[] = { .05, 4.75, -.19 };
	float Y[] = { .05, 4.75, .19 };   float YB[] = { .05, 4.75, -.19 };
	float Z[] = { .40, 4.57, .13 };   float ZB[] = { .40, 4.57, -.13 };
	float A2[] = { -.19, 5.12, .19 }; float A2B[] = { -.19, 5.12, -.19 };
	//Front-side of horse; multiple pieces to avoid concave polygons
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glBegin(GL_POLYGON);
	float temp1[3];
	float temp2[3];
	float temp3[3];
	subtract3f(W, X, temp1);
	subtract3f(X, H, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.61 / scale, 1.99 / scale);    glVertex3f(.61 / scale, 1.99 / scale, .48 / scale); //H
	glTexCoord2f(.15 / scale, 2.49 / scale);    glVertex3f(.15 / scale, 2.49 / scale, .45 / scale); //X
	glTexCoord2f(0, 2.49 / scale);      glVertex3f(0, 2.49 / scale, .40 / scale); //W
	glTexCoord2f(-.25 / scale, 3.52 / scale);   glVertex3f(-.25 / scale, 3.52 / scale, .38 / scale); //V
	glTexCoord2f(-.37 / scale, 4.32 / scale);   glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U
	glTexCoord2f(.05 / scale, 3.84 / scale);    glVertex3f(.05 / scale, 3.84 / scale, .19 / scale); //F
	glTexCoord2f(.89 / scale, 2.70 / scale);    glVertex3f(.89 / scale, 2.70 / scale, .22 / scale); //G
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(F, E, temp1);
	subtract3f(E, D, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, .19 / scale); //F
	glTexCoord2f(.83 / scale, 3.99 / scale); glVertex3f(.83 / scale, 3.99 / scale, .18 / scale); //E
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, .16 / scale); //D
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(C, D, temp1);
	subtract3f(D, F, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);

	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, .12 / scale); //C
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, .16 / scale); //D
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, .19 / scale); //F
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U
	glTexCoord2f(.4 / scale, 4.57 / scale);  glVertex3f(.40 / scale, 4.57 / scale, .13 / scale); //Z
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(U, Y, temp1);
	subtract3f(Y, Z, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U
	glTexCoord2f(.05 / scale, 4.75 / scale); glVertex3f(.05 / scale, 4.75 / scale, .19 / scale); //Y
	glTexCoord2f(.40 / scale, 4.57 / scale); glVertex3f(.40 / scale, 4.57 / scale, .13 / scale); //Z
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(A, A2, temp1);
	subtract3f(A2, Y, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, .31 / scale); //A
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, .19 / scale); //A2
	glTexCoord2f(.05 / scale, 4.75 / scale); glVertex3f(.05 / scale, 4.75 / scale, .19 / scale); //Y
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U
	glEnd();
	//Back front-side
	glBegin(GL_POLYGON);
	subtract3f(HB, XB, temp1);
	subtract3f(XB, WB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.61 / scale, 1.99 / scale); glVertex3f(.61 / scale, 1.99 / scale, -.48 / scale); //H
	glTexCoord2f(.15 / scale, 2.49 / scale); glVertex3f(.15 / scale, 2.49 / scale, -.45 / scale); //X
	glTexCoord2f(0, 2.49 / scale); glVertex3f(0, 2.49 / scale, -.40 / scale); //W
	glTexCoord2f(-.25 / scale, 3.52 / scale); glVertex3f(-.25 / scale, 3.52 / scale, -.38 / scale); //V
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, -.19 / scale); //F
	glTexCoord2f(.89 / scale, 2.70 / scale); glVertex3f(.89 / scale, 2.70 / scale, -.22 / scale); //G
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(FB, EB, temp1);
	subtract3f(EB, DB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, -.19 / scale); //F
	glTexCoord2f(.83 / scale, 3.99 / scale); glVertex3f(.83 / scale, 3.99 / scale, -.18 / scale); //E
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, -.16 / scale); //D
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(CB, DB, temp1);
	subtract3f(DB, FB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, -.12 / scale); //C
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, -.16 / scale); //D
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, -.19 / scale); //F
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U
	glTexCoord2f(.40 / scale, 4.57 / scale); glVertex3f(.40 / scale, 4.57 / scale, -.13 / scale); //Z
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(UB, YB, temp1);
	subtract3f(YB, ZB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U
	glTexCoord2f(.05 / scale, 4.75 / scale); glVertex3f(.05 / scale, 4.75 / scale, -.19 / scale); //Y
	glTexCoord2f(.40 / scale, 4.57 / scale); glVertex3f(.40 / scale, 4.57 / scale, -.13 / scale); //Z
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(AB, A2B, temp1);
	subtract3f(A2B, YB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, -.31 / scale); //A
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, -.19 / scale); //A2
	glTexCoord2f(.05 / scale, 4.75 / scale); glVertex3f(.05 / scale, 4.75 / scale, -.19 / scale); //Y
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U
	glEnd();
	//Back-side Split into multiple sections to avoid convex polygons
	glBegin(GL_TRIANGLES);
	subtract3f(A, T, temp1);
	subtract3f(T, U, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, .31 / scale); //A
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, .28 / scale); //T
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U

	subtract3f(T, U, temp1);
	subtract3f(U, S, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, .28 / scale); //T
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, .09 / scale); //S
	glEnd();
	glBegin(GL_QUADS);
	subtract3f(S, U, temp1);
	subtract3f(U, R, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, .33 / scale); //U
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, .09 / scale); //S
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, .05 / scale); //R
	glTexCoord2f(-.25 / scale, 3.52 / scale); glVertex3f(-.25 / scale, 3.52 / scale, .38 / scale); //V

	subtract3f(V, W, temp1);
	subtract3f(W, R, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, .05 / scale); //R
	glTexCoord2f(-.25 / scale, 3.52 / scale); glVertex3f(-.25 / scale, 3.52 / scale, .38 / scale); //V
	glTexCoord2f(0, 2.95 / scale); glVertex3f(0, 2.95 / scale, .40 / scale);  //W
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, .1 / scale); //Q

	subtract3f(X, P, temp1);
	subtract3f(P, Q, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(0, 2.95 / scale); glVertex3f(0, 2.95 / scale, .40 / scale);  //W
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, .1 / scale); //Q
	glTexCoord2f(-.75 / scale, 1.91 / scale); glVertex3f(-.75 / scale, 1.91 / scale, .2 / scale); //P
	glTexCoord2f(.15 / scale, 2.49 / scale); glVertex3f(.15 / scale, 2.49 / scale, .45 / scale); //X
	glEnd();
	glBegin(GL_TRIANGLES);
	subtract3f(P, X, temp1);
	subtract3f(X, H, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.75 / scale, 1.91 / scale); glVertex3f(-.75 / scale, 1.91 / scale, .2 / scale); //P
	glTexCoord2f(.15 / scale, 2.49 / scale); glVertex3f(.15 / scale, 2.49 / scale, .45 / scale); //X
	glTexCoord2f(.61 / scale, 1.99 / scale); glVertex3f(.61 / scale, 1.99 / scale, .48 / scale); //H
	glEnd();
	//Back Side Back
	glBegin(GL_TRIANGLES);
	subtract3f(AB, TB, temp1);
	subtract3f(TB, UB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, -.31 / scale); //A
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, -.28 / scale); //T
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U

	subtract3f(TB, UB, temp1);
	subtract3f(UB, SB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, -.28 / scale); //T
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, -.09 / scale); //S
	glEnd();
	glBegin(GL_QUADS);
	subtract3f(RB, UB, temp1);
	subtract3f(UB, VB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.37 / scale, 4.32 / scale); glVertex3f(-.37 / scale, 4.32 / scale, -.33 / scale); //U
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, -.09 / scale); //S
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, -.05 / scale); //R
	glTexCoord2f(-.25 / scale, 3.52 / scale); glVertex3f(-.25 / scale, 3.52 / scale, -.38 / scale); //V

	subtract3f(RB, VB, temp1);
	subtract3f(VB, WB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, -.05 / scale); //R
	glTexCoord2f(-.25 / scale, 3.52 / scale); glVertex3f(-.25 / scale, 3.52 / scale, -.38 / scale); //V
	glTexCoord2f(0, 2.95 / scale); glVertex3f(0, 2.95 / scale, -.40 / scale);  //W
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, -.1 / scale); //Q

	subtract3f(QB, WB, temp1);
	subtract3f(WB, PB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(0, 2.95 / scale); glVertex3f(0, 2.95 / scale, -.40 / scale);  //W
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, -.1 / scale); //Q
	glTexCoord2f(-.75 / scale, 1.91 / scale); glVertex3f(-.75 / scale, 1.91 / scale, -.2 / scale); //P
	glTexCoord2f(.15 / scale, 2.49 / scale); glVertex3f(.15 / scale, 2.49 / scale, -.45 / scale); //X
	glEnd();
	glBegin(GL_TRIANGLES);
	subtract3f(PB, XB, temp1);
	subtract3f(XB, HB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.75 / scale, 1.91 / scale); glVertex3f(-.75 / scale, 1.91 / scale, -.2 / scale); //P
	glTexCoord2f(.15 / scale, 2.49 / scale); glVertex3f(.15 / scale, 2.49 / scale, -.45 / scale); //X
	glTexCoord2f(.61 / scale, 1.99 / scale); glVertex3f(.61 / scale, 1.99 / scale, -.48 / scale); //H
	glEnd();
	//Front and Chest of horse
	glBegin(GL_QUADS);
	subtract3f(HB, H, temp1);
	subtract3f(H, G, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.61 / scale, 1.99 / scale); glVertex3f(.61 / scale, 1.99 / scale, -.48 / scale); //H
	glTexCoord2f(.61 / scale, 1.99 / scale); glVertex3f(.61 / scale, 1.99 / scale, .48 / scale); //H
	glTexCoord2f(.89 / scale, 2.70 / scale); glVertex3f(.89 / scale, 2.70 / scale, .22 / scale); //G
	glTexCoord2f(.89 / scale, 2.70 / scale); glVertex3f(.89 / scale, 2.70 / scale, -.22 / scale); //G

	subtract3f(G, GB, temp1);
	subtract3f(GB, F, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.89 / scale, 2.70 / scale); glVertex3f(.89 / scale, 2.70 / scale, .22 / scale); //G
	glTexCoord2f(.89 / scale, 2.70 / scale); glVertex3f(.89 / scale, 2.70 / scale, -.22 / scale); //G
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, -.19 / scale); //F
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, .19 / scale); //F

	subtract3f(F, FB, temp1);
	subtract3f(FB, E, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, -.19 / scale); //F
	glTexCoord2f(.05 / scale, 3.84 / scale); glVertex3f(.05 / scale, 3.84 / scale, .19 / scale); //F
	glTexCoord2f(.83 / scale, 3.99 / scale); glVertex3f(.83 / scale, 3.99 / scale, .18 / scale); //E
	glTexCoord2f(.83 / scale, 3.99 / scale); glVertex3f(.83 / scale, 3.99 / scale, -.18 / scale); //E

	subtract3f(W, Q, temp1);
	subtract3f(Q, P, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.83 / scale, 3.99 / scale); glVertex3f(.83 / scale, 3.99 / scale, .18 / scale); //E
	glTexCoord2f(.83 / scale, 3.99 / scale); glVertex3f(.83 / scale, 3.99 / scale, -.18 / scale); //E
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, -.16 / scale); //D
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, .16 / scale); //D

	subtract3f(D, DB, temp1);
	subtract3f(DB, C, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, .16 / scale); //D
	glTexCoord2f(.78 / scale, 4.13 / scale); glVertex3f(.78 / scale, 4.13 / scale, -.16 / scale); //D
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, -.12 / scale); //C
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, .12 / scale); //C

	subtract3f(C, CB, temp1);
	subtract3f(CB, E1, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, -.12 / scale); //C
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, .12 / scale); //C
	glTexCoord2f(.24 / scale, 4.86 / scale); glVertex3f(.24 / scale, 4.86 / scale, .05 / scale); //E1
	glTexCoord2f(.24 / scale, 4.86 / scale); glVertex3f(.24 / scale, 4.86 / scale, -.05 / scale); //E1

	subtract3f(E1, E1B, temp1);
	subtract3f(E1B, B, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(.24 / scale, 4.86 / scale); glVertex3f(.24 / scale, 4.86 / scale, .05 / scale); //E1
	glTexCoord2f(.24 / scale, 4.86 / scale); glVertex3f(.24 / scale, 4.86 / scale, -.05 / scale); //E1
	glTexCoord2f(0, 5.12 / scale); glVertex3f(0, 5.12 / scale, -.19 / scale); //B
	glTexCoord2f(0, 5.12 / scale); glVertex3f(0, 5.12 / scale, .19 / scale); //B

	subtract3f(B, A2, temp1);
	subtract3f(A2, BB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(0, 5.12 / scale); glVertex3f(0, 5.12 / scale, -.19 / scale); //B
	glTexCoord2f(0, 5.12 / scale); glVertex3f(0, 5.12 / scale, .19 / scale); //B
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, .19 / scale); //A2
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, -.19 / scale); //A2
	glEnd();
	//Eye Depressions
	glBegin(GL_POLYGON);
	subtract3f(A2, B, temp1);
	subtract3f(B, E1, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, .19 / scale); //A2
	glTexCoord2f(0, 5.12 / scale); glVertex3f(0, 5.12 / scale, .19 / scale); //B
	glTexCoord2f(.24 / scale, 4.86 / scale); glVertex3f(.24 / scale, 4.86 / scale, .05 / scale); //E1
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, .12 / scale); //C
	glTexCoord2f(.40 / scale, 4.57 / scale); glVertex3f(.40 / scale, 4.57 / scale, .19 / scale); //Z
	glTexCoord2f(.05 / scale, 4.75 / scale); glVertex3f(.05 / scale, 4.75 / scale, .19 / scale); //Y
	glEnd();
	glBegin(GL_POLYGON);
	subtract3f(A2B, BB, temp1);
	subtract3f(BB, E1B, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, -.19 / scale); //A2
	glTexCoord2f(0, 5.12 / scale); glVertex3f(0, 5.12 / scale, -.19 / scale); //B
	glTexCoord2f(.24 / scale, 4.86 / scale); glVertex3f(.24 / scale, 4.86 / scale, -.05 / scale); //E1
	glTexCoord2f(.86 / scale, 4.48 / scale); glVertex3f(.86 / scale, 4.48 / scale, -.12 / scale); //C
	glTexCoord2f(.40 / scale, 4.57 / scale); glVertex3f(.40 / scale, 4.57 / scale, -.19 / scale); //Z
	glTexCoord2f(.05 / scale, 4.75 / scale); glVertex3f(.05 / scale, 4.75 / scale, -.19 / scale); //Y
	glEnd();
	//Ears
	glBegin(GL_TRIANGLES);
	float A3[3] = { -.19, 5.12, 0 };
	float A4[3] = { -.48, 4.86, 0 };

	subtract3f(A, A2, temp1);
	subtract3f(A2, A3, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, .31 / scale); //A
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, .19 / scale); //A2
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, 0); //A3

	subtract3f(A, A3, temp1);
	subtract3f(A3, A4, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, .31 / scale); //A
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, 0); //A3
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, 0); //A4

	subtract3f(A, A4, temp1);
	subtract3f(A4, T, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, .31 / scale); //A
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, 0); //A4
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, .28 / scale); //T

	subtract3f(AB, A2B, temp1);
	subtract3f(A2B, A3, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, -.31 / scale); //A
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, -.19 / scale); //A2
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, 0); //A3

	subtract3f(AB, A3, temp1);
	subtract3f(A3, A4, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, -.31 / scale); //A
	glTexCoord2f(-.19 / scale, 5.12 / scale); glVertex3f(-.19 / scale, 5.12 / scale, 0); //A3
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, 0); //A4

	subtract3f(AB, A4, temp1);
	subtract3f(A4, TB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.4 / scale, 5.47 / scale); glVertex3f(-.4 / scale, 5.47 / scale, -.31 / scale); //A
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, 0); //A4
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, -.28 / scale); //T
	glEnd();
	//Back of horse
	glBegin(GL_QUADS);
	subtract3f(TB, T, temp1);
	subtract3f(T, S, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, -.28 / scale); //T
	glTexCoord2f(-.48 / scale, 4.86 / scale); glVertex3f(-.48 / scale, 4.86 / scale, .28 / scale); //T
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, .09 / scale); //S
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, -.09 / scale); //S

	subtract3f(S, SB, temp1);
	subtract3f(SB, RB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, .09 / scale); //S
	glTexCoord2f(-.92 / scale, 4.22 / scale); glVertex3f(-.92 / scale, 4.22 / scale, -.09 / scale); //S
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, -.05 / scale); //R
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, .05 / scale); //R

	subtract3f(R, RB, temp1);
	subtract3f(RB, QB, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, .05 / scale); //R
	glTexCoord2f(-1.12 / scale, 3.51 / scale); glVertex3f(-1.12 / scale, 3.51 / scale, -.05 / scale); //R
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, -.10 / scale); //Q
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, .10 / scale); //Q

	subtract3f(QB, Q, temp1);
	subtract3f(QB, P, temp2);
	crossproduct3f(temp1, temp2, temp3);
	rescalenormals(temp3);
	glNormal3fv(temp3);
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, -.10 / scale); //Q
	glTexCoord2f(-1.06 / scale, 2.85 / scale); glVertex3f(-1.06 / scale, 2.85 / scale, .10 / scale); //Q
	glTexCoord2f(-.75 / scale, 1.91 / scale); glVertex3f(-.75 / scale, 1.91 / scale, .2 / scale); //P
	glTexCoord2f(-.75 / scale, 1.91 / scale); glVertex3f(-.75 / scale, 1.91 / scale, -.2 / scale); //P
	glEnd();
	glPopMatrix();

	//Cylinders
	GLUquadricObj* object;
	object = gluNewQuadric();
	gluQuadricDrawStyle(object, GLU_FILL);
	gluQuadricNormals(object, GL_SMOOTH);
	gluQuadricTexture(object, GL_TRUE);
	//H-I Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.99 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, .85 / scale, 10, 10);
	glPopMatrix();
	//I-J
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.68 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.09 / scale, .85 / scale, .31 / scale, 10, 10);
	glPopMatrix();
	//J-K
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 1.45 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.02 / scale, 1.09 / scale, .23 / scale, 10, 10);
	glPopMatrix();
	//K-L
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .93 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.49 / scale, 1.02 / scale, .52 / scale, 15, 15);
	glPopMatrix();
	//L-M
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .52 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.39 / scale, 1.49 / scale, .41 / scale, 15, 10);
	glPopMatrix();
	//M-N
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, .36 / scale, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.52 / scale, 1.39 / scale, .16 / scale, 10, 10);
	glPopMatrix();
	//N-0
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluCylinder(object, 1.52 / scale, 1.52 / scale, .36 / scale, 15, 10);
	glPopMatrix();
	//Bottom Disk
	glPushMatrix();
	glTranslatef((x + .5) / 4.0, 0, (y + .5) / 4.0);
	glRotatef(90, -1, 0, 0);
	gluDisk(object, 0, 1.52 / scale, 15, 10);
	glPopMatrix();

	//Eyes - last because the color changes.
	//Change this so that it is white instead of gray
	float mat_gray[] = { .5, .5, .5, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_gray);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_gray);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_gray);
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
	glTranslatef((x + .5) / 4.0 + .24 / scale, 4.82 / scale, (y + .5 + 1.09 / scale) / 4.0);
	gluSphere(object, .04 / 4.0, 10, 10);
	glPopMatrix();
	glPushMatrix();
	glTranslatef((x + .5) / 4.0 + .24 / scale, 4.82 / scale, (y + .5 - 1.09 / scale) / 4.0);
	gluSphere(object, .04 / 4.0, 10, 10);
	glPopMatrix();

	gluDeleteQuadric(object);
	return 0;
}



#endif // DRAWKNIGHT_H_INCLUDED
