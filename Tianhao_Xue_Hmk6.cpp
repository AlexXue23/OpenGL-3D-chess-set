/*
Author: Tianhao Xue
Class: ECE6122
Last Date Modified: 2019/11/25
Description:
	Create a 3D chess set model using OpenGL.
*/

#include <iostream>
//#include <GL/glew.h> // Include the GLEW header file
#include <GL/glut.h> // Include the GLUT header file
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // standard definitions
#include <ctime>
///////////////////////////////////////////////////////////////
// Enhance mode h files
#include "DrawCal.h"
#include "DrawBishop.h"
#include "DrawPawn.h"
#include "DrawQueen.h"
#include "DrawRook.h"
#include "DrawKing.h"
#include "DrawKnight.h"


#define ESC 27
using namespace std;
//----------------------------------------------------------------------
// Global variables
//
//
// The values (x,y) are the current camera position. The values (lx, ly)
// point in the direction the camera is looking. The variables angle and
// deltaAngle control the camera's angle. The variable deltaMove
// indicates the amount of incremental motion for the camera with each
// redraw cycle. The variables isDragging and xDragStart are used to
// monitor the mouse when it drags (with the left button down).
//----------------------------------------------------------------------

int i, j, m; // m is to store random number during the movement of Knights and Pawns

// Camera position
float z = 10.0; // initially z value
float rotateAngle = 0.0; 

// Flags
bool lightSwitch0 = 0; // control light0
bool lightSwitch1 = 0; // control light1
bool knightFlag = 0;   // the loop flag of knight movement
bool pawnFlag = 0;     // the loop flag of pawn movement
bool modeFlag = 0;     // the switch between normal mode and enhanced mode

int knightPosition[2][4] = // store x, y values of each knight
{1, 6, 1, 6,
 0, 0, 7, 7}; 

int pawnPosition[2][16] = // store x, y values of each knight
{0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7,
 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 6, 6, 6, 6, 6, 6};

int boardStatus[8][8] =  // store every square's status (1 for occupied, 0 for empty)
{1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0,
 1, 1, 1, 1, 1, 1, 1, 1,
 1, 1, 1, 1, 1, 1, 1, 1 };

//----------------------------------------------------------------------
// Reshape callback
//
// Window size has been set/changed to w by h pixels. Set the camera
// perspective to 45 degree vertical field of view, a window aspect
// ratio of w/h, a near clipping plane at depth 0.1, and a far clipping
// plane at depth 100. The viewport is the entire window.
//
//----------------------------------------------------------------------
void changeSize(int w, int h)
{
	float ratio = ((float)w) / ((float)h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	gluPerspective(45.0, ratio, 0.1, 100.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}

// Update with each idle event
void update(void)
{
	glutPostRedisplay(); // redisplay everything
}

//----------------------------------------------------------------------
// Draw the chess board and chess pieces
//----------------------------------------------------------------------
void drawBoard(void)
{
	// Clear color and depth buffers
	glClearColor(0.5, 0.6, 0.7, 1.0); // background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Use smooth model
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	// Reset transformations
	glLoadIdentity();	

	// Set the lighting and material properties
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	if (lightSwitch0)	glEnable(GL_LIGHT0);
	else   glDisable(GL_LIGHT0);
	if (lightSwitch1)   glEnable(GL_LIGHT1);
	else   glDisable(GL_LIGHT1);

	GLfloat light0_ambient[] =  { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light0_diffuse[] =  { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light0_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light1_ambient[] =  { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light1_diffuse[] =  { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light1_specular[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light1_position[] = { 5.0, 5.0, 8.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

	GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };   
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	// Set the camera 
	gluLookAt(
		4, -5, z,
		4.0, 4.0, 0.0,
		0.0, 0.0, 1.0);

	// Rotate chess board
	glTranslatef(4, 4, 0);
	glRotatef(rotateAngle, 0, 0, 1);
	glTranslatef(-4, -4, 0);

	// Draw chess board - 8x8 square
	glNormal3f(0, 0, 1);
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			if ((i + j) % 2 != 0)
			{
				glColor3f(1, 1, 1);
				glBegin(GL_QUADS);
				glVertex3i(i, j, 0);
				glVertex3i(i, j + 1, 0);
				glVertex3i(i + 1, j + 1, 0);
				glVertex3i(i + 1, j, 0);
				glEnd();
			}
			else
			{
				glColor3f(0, 0, 0);
				glBegin(GL_QUADS);
				glVertex3i(i, j, 0);
				glVertex3i(i, j + 1, 0);
				glVertex3i(i + 1, j + 1, 0);
				glVertex3i(i + 1, j, 0);
				glEnd();
			}
		}
	}

	// Draw chess pieces in Enhanced mode
	if (modeFlag)
	{
		//   Draw Pawns
		for (i = 0; i < 8; i++)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(pawnPosition[0][i] + 0.13, pawnPosition[1][i] + 0.86, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(3.0, 3.0, 3.0);
			DrawPawn(0.0, 0.0);
			glPopMatrix();

			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(pawnPosition[0][i + 8] + 0.13, pawnPosition[1][i + 8] + 0.86, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(3.0, 3.0, 3.0);
			DrawPawn(0.0, 0.0);
			glPopMatrix();
		}
		//    Draw Rooks
		for (i = 0; i < 8; i += 7)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(i + 0.13, 0.86, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(3.0, 3.0, 3.0);
			DrawRook(0, 0);
			glPopMatrix();

			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(i + 0.13, 7.86, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glScalef(3.0, 3.0, 3.0);
			DrawRook(0, 0);
			glPopMatrix();
		}
		//    Draw Knights
		for (i = 0; i < 2; ++i)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(knightPosition[0][i] + 0.13, knightPosition[1][i] + 0.1, 0.0);
			glScalef(3.0, 3.0, 3.0);
			glRotatef(90.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			DrawKnight(0, 0);
			glPopMatrix();
		}
		for (i = 2; i < 4; ++i)
		{
			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(knightPosition[0][i] + 0.88, knightPosition[1][i] + 0.9, 0.0);
			glScalef(3.0, 3.0, 3.0);
			glRotatef(-90.0, 0.0, 0.0, 1.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			DrawKnight(0, 0);
			glPopMatrix();
		}
		//    Draw Bishops
		for (i = 2; i < 8; i += 3)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(i + 0.12, 0.9, 0.0);
			glScalef(3.0, 3.0, 3.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			DrawBishop(0, 0);
			glPopMatrix();

			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(i + 0.12, 7.9, 0.0);
			glScalef(3.0, 3.0, 3.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			DrawBishop(0, 0);
			glPopMatrix();
		}
		//    Draw Queens
		glColor3ub(140, 140, 135);
		glPushMatrix();
		glTranslatef(3.88, 0.88, 0.0);
		glScalef(3.0, 3.0, 3.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		DrawQueen(0, 0);
		glPopMatrix();

		glColor3ub(150, 75, 0);
		glPushMatrix();
		glTranslatef(3.88, 7.88, 0.0);
		glScalef(3.0, 3.0, 3.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		DrawQueen(0, 0);
		glPopMatrix();

		//    Draw Kings
		glColor3ub(140, 140, 135);
		glPushMatrix();
		glTranslatef(4.1, 0.9, 0.0);
		glScalef(3.0, 3.0, 3.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		DrawKing(0, 0);
		glPopMatrix();

		glColor3ub(150, 75, 0);
		glPushMatrix();
		glTranslatef(4.1, 7.9, 0.0);
		glScalef(3.0, 3.0, 3.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		DrawKing(0, 0);
		glPopMatrix();
	}

	// Draw chess pieces in Normal mode	
	else 
	{
		//   Draw Pawns
		for (i = 0; i < 8; i++)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(pawnPosition[0][i] + 0.5, pawnPosition[1][i] + 0.5, 0.375);
			glutSolidSphere(0.375, 30, 30);
			glPopMatrix();

			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(pawnPosition[0][i + 8] + 0.5, pawnPosition[1][i + 8] + 0.5, 0.375);
			glutSolidSphere(0.375, 30, 30);
			glPopMatrix();
		}
		//    Draw Rooks
		for (i = 0; i < 8; i += 7)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(i + 0.5, 0.5, 0.375);
			glutSolidCube(0.75);
			glPopMatrix();

			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(i + 0.5, 7.5, 0.375);
			glutSolidCube(0.75);
			glPopMatrix();
		}
		//    Draw Knights
		for (i = 0; i < 2; ++i)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(knightPosition[0][i] + 0.5, knightPosition[1][i] + 0.5, 0.3);
			glScalef(0.55, 0.55, 1);
			glRotatef(90.0, 1, 0, 0);
			glutSolidTeapot(0.4);
			glPopMatrix();
		}
		for (i = 2; i < 4; ++i)
		{
			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(knightPosition[0][i] + 0.5, knightPosition[1][i] + 0.5, 0.3);
			glScalef(0.55, 0.55, 1);
			glRotatef(90.0, 1, 0, 0);
			glutSolidTeapot(0.4);
			glPopMatrix();
		}
		//    Draw Bishops
		for (i = 2; i < 8; i += 3)
		{
			glColor3ub(140, 140, 135);
			glPushMatrix();
			glTranslatef(i + 0.5, 0.5, 0.0);
			glutSolidCone(0.375, 1.0, 20, 20);
			glPopMatrix();

			glColor3ub(150, 75, 0);
			glPushMatrix();
			glTranslatef(i + 0.5, 7.5, 0.0);
			glutSolidCone(0.375, 1.0, 20, 20);
			glPopMatrix();
		}
		//    Draw Queens
		glColor3ub(140, 140, 135);
		glPushMatrix();
		glTranslatef(3.5, 0.5, 0.16);
		glScalef(0.47, 0.47, 0.47);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glutSolidTetrahedron();
		glPopMatrix();

		glColor3ub(150, 75, 0);
		glPushMatrix();
		glTranslatef(3.5, 7.5, 0.16);
		glScalef(0.47, 0.47, 0.47);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glutSolidTetrahedron();
		glPopMatrix();

		//    Draw Kings
		glColor3ub(140, 140, 135);
		glPushMatrix();
		glTranslatef(4.5, 0.5, 0.5);
		glScalef(0.375, 0.375, 0.5);
		glutSolidOctahedron();
		glPopMatrix();

		glColor3ub(150, 75, 0);
		glPushMatrix();
		glTranslatef(4.5, 7.5, 0.5);
		glScalef(0.375, 0.375, 0.5);
		glutSolidOctahedron();
		glPopMatrix();
	}
	
	glutSwapBuffers(); // Make it all visible
}

// Movement of Knights
void knightMove(int n, int dy, int dx)
{
	boardStatus[7 - knightPosition[1][n]][knightPosition[0][n]] = 0;
	knightPosition[0][n] = knightPosition[0][n] + dx;
	knightPosition[1][n] = knightPosition[1][n] - dy;
	boardStatus[7 - knightPosition[1][n]][knightPosition[0][n]] = 1;
	knightFlag = 0;
}

// Movement of Pawns
void pawnMove(int n, int dy)
{
	boardStatus[7 - pawnPosition[1][m]][pawnPosition[0][m]] = 0;
	pawnPosition[1][n] = pawnPosition[1][n] - dy;
	boardStatus[7 - pawnPosition[1][m]][pawnPosition[0][m]] = 1;
	pawnFlag = 0;
}

//----------------------------------------------------------------------
// User-input callbacks
// 'r' or 'R': rotates the chess set by 10 degrees around the z - axis at its center point each time.
// 'd' or 'D': moves the eye location down z ¨C axis 0.25 m each time.
// 'u' or 'U': moves the eye location up z - axis 0.25 m each time.
// '0'(zero) : toggles GL_LIGHT0 on and off(enable / disable)
// '1'       : toggles GL_LIGHT1 on and off(enable / disable)
// 'k' or 'K': causing a random knight to move only one position
// 'p' or 'P': causing a random pawn to move one position
// 'e' or 'E': toggles between normal mode and enhanced mode that makes some of the pieces look more realistic
//----------------------------------------------------------------------
void processNormalKeys(unsigned char key, int xx, int yy)
{
	switch (key)
	{
	case 'e':
	case 'E':
		modeFlag = 1 - modeFlag;
		break;
	case 'r':
	case 'R':
		rotateAngle += 10.0;
		break;
	case 'u':
	case 'U':
		z += 0.25; 
		break;
	case 'd':
	case 'D':
		z -= 0.25;
		break;
	case '0':
		lightSwitch0 = 1 - lightSwitch0;
		break;
	case '1':
		lightSwitch1 = 1 - lightSwitch1;
		break;
	case 'k':
	case 'K':
		knightFlag = 1;
		while (knightFlag)
		{
			// Randomly choose a knight and let it move in 'L' shape clockwise inside the chess board
			m = rand() % 4;
			if (5 - knightPosition[1][m] >= 0 && knightPosition[0][m] + 1 <= 7 && boardStatus[5 - knightPosition[1][m]][knightPosition[0][m] + 1] == 0) knightMove(m, -2, 1);
			else if (6 - knightPosition[1][m] >= 0 && knightPosition[0][m] + 2 <= 7 && boardStatus[6 - knightPosition[1][m]][knightPosition[0][m] + 2] == 0) knightMove(m, -1, 2);
			else if (8 - knightPosition[1][m] <= 7 && knightPosition[0][m] + 2 <= 7 && boardStatus[8 - knightPosition[1][m]][knightPosition[0][m] + 2] == 0) knightMove(m, 1, 2);
			else if (9 - knightPosition[1][m] <= 7 && knightPosition[0][m] + 1 <= 7 && boardStatus[9 - knightPosition[1][m]][knightPosition[0][m] + 1] == 0) knightMove(m, 2, 1);
			else if (9 - knightPosition[1][m] <= 7 && knightPosition[0][m] - 1 >= 0 && boardStatus[9 - knightPosition[1][m]][knightPosition[0][m] - 1] == 0) knightMove(m, 2, -1);
			else if (8 - knightPosition[1][m] <= 7 && knightPosition[0][m] - 2 >= 0 && boardStatus[8 - knightPosition[1][m]][knightPosition[0][m] - 2] == 0) knightMove(m, 1, -2);
			else if (6 - knightPosition[1][m] >= 0 && knightPosition[0][m] - 2 >= 0 && boardStatus[6 - knightPosition[1][m]][knightPosition[0][m] - 2] == 0) knightMove(m, -1, -2);
			else if (5 - knightPosition[1][m] >= 0 && knightPosition[0][m] - 1 >= 0 && boardStatus[5 - knightPosition[1][m]][knightPosition[0][m] - 1] == 0) knightMove(m, -2, -1);
			else knightFlag = 0;
		}
		break;
	case 'p':
	case 'P':
		pawnFlag = 1;
		while (pawnFlag)
		{
			// Randomly choose a pawn and let it move 1 square forward or backward inside the chess board
			m = rand() % 16;
			if (7 - pawnPosition[1][m] - 1 >= 0 && boardStatus[7 - pawnPosition[1][m] - 1][pawnPosition[0][m]] == 0) pawnMove(m, -1);
			else if(7 - pawnPosition[1][m] + 1 >= 0 && boardStatus[7 - pawnPosition[1][m] + 1][pawnPosition[0][m]] == 0) pawnMove(m, 1);
			else pawnFlag = 0;
		}
		break;
	}
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
int main(int argc, char** argv)
{
	cout << "User-input callbacks" << endl;
	cout << " 'r' or 'R': rotates the chess set by 10 degrees around the z - axis at its center point each time." << endl;
	cout << " 'd' or 'D': moves the eye location down z ¨C axis 0.25 m each time." << endl;
	cout << " 'u' or 'U': moves the eye location up z - axis 0.25 m each time." << endl;
	cout << " '0'(zero) : toggles GL_LIGHT0 on and off(enable / disable)" << endl;
	cout << " '1'       : toggles GL_LIGHT1 on and off(enable / disable)" << endl;
	cout << " 'k' or 'K': causing a random knight to move only one position" << endl;
	cout << " 'p' or 'P': causing a random pawn to move one position" << endl;
	cout << " 'e' or 'E': toggles between normal mode and enhanced mode that makes some of the pieces look more realistic" << endl;
	srand((int)time(0));
	printf("Tianhao Xue's Chess Board");
	// general initializations
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 100);
	// Window Size
	glutInitWindowSize(600, 600);
	glutCreateWindow("Tianhao Xue's Chess Board");
	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	// register callbacks
	glutReshapeFunc(changeSize); // window reshape callback
	glutDisplayFunc(drawBoard); // (re)display callback
	glutIdleFunc(update); // incremental update
	glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
	glutKeyboardFunc(processNormalKeys); // process standard key clicks

	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0; // this is just to keep the compiler happy
}