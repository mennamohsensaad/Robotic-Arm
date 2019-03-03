/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED 
 * Permission to use, copy, modify, and distribute this software for 
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that 
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. 
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * US Government Users Restricted Rights 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 * robot.c
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  pressing the s and e keys (shoulder and elbow)
 * alters the rotation of the robot arm.
 */
#include <stdlib.h>
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, fingerBase1 = 0, fingerUp1 = 0, fingerBase2 = 0, fingerUp2 = 0,
fingerBase3 = 0, fingerUp3 = 0, fingerBase4 = 0, fingerUp4 = 0, fingerBase5 = 0, fingerUp5 = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle2, 1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(2.0, 0.6, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	//Draw finger flang 1
	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)fingerBase1, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger flang 1 
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp1, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();

	glPopMatrix();


	//Draw finger flang 2 
	glPushMatrix();
	glTranslatef(1.0, 0.25, 0.0);
	glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger flang 2
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();


	glPopMatrix();

	//Draw finger flang 3
	glPushMatrix();
	glTranslatef(1.0, 0.25, -0.15);
	glRotatef((GLfloat)fingerBase3, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger flang 3
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp3, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();


	glPopMatrix();

	//Draw finger flang 4
	glPushMatrix();
	glTranslatef(1.0, 0.25, -0.3);
	glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger flang 4
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();


	glPopMatrix();

	//Draw finger flang 5
	glPushMatrix();
	glTranslatef(1.0, 0.25, -0.45);
	glRotatef((GLfloat)fingerBase5, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();
	//Draw finger flang 5
	glTranslatef(0.15, 0.0, 0.0);
	glRotatef((GLfloat)fingerUp5, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.3, 0.1, 0.1);
	glutWireCube(1);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();





}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
		shoulder = (shoulder + 5) % 180;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 180;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 180;
		glutPostRedisplay();
		break;
	case 'E': //NOT LOGIC
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'f':
		fingerBase1 = (fingerBase1 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'F':
		fingerBase1 = (fingerBase1 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'g':
		fingerUp1 = (fingerUp1 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'G':
		fingerUp1 = (fingerUp1 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'a':
		fingerBase2 = (fingerBase2 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'A':
		fingerBase2 = (fingerBase2 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'b':
		fingerUp2 = (fingerUp2 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'B':
		fingerUp2 = (fingerUp2 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'c':
		fingerBase3 = (fingerBase3 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'C':
		fingerBase3 = (fingerBase3 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'd':
		fingerUp3 = (fingerUp3 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'D':
		fingerUp3 = (fingerUp3 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'i':
		fingerBase4 = (fingerBase4 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'I':
		fingerBase4 = (fingerBase4 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'j':
		fingerUp4 = (fingerUp4 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'J':
		fingerUp4 = (fingerUp4 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'x':
		fingerBase5 = (fingerBase5 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'X':
		fingerBase5 = (fingerBase5 - 5) % 90;
		glutPostRedisplay();
		break;
	case 'y':
		fingerUp5 = (fingerUp5 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'Y':
		fingerUp5 = (fingerUp5 - 5) % 90;
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			moving = 1;
			startx = x;
			starty = y;
		}
		if (state == GLUT_UP) {
			moving = 0;
		}
	}
}


static void motion(int x, int y)
{
	if (moving) {
		angle = angle + (x - startx);
		angle2 = angle2 + (y - starty);
		startx = x;
		starty = y;
		glutPostRedisplay();
	}
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}