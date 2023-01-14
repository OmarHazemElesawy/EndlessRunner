#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <random>
#include <glut.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;
void Display(void);
void print(int x, int y, char* string);
void drawCircle(int x, int y, float r);
void Anim(void);
void drawCoin(int coinX);
// collide();
void drawRect(int x, int y, int w, int h);
void drawBackground();
void drawCharacter();
void drawObstcale(int x);
void drawObstcaleHelper();
//void obstacleTimer1(int value);
//void obstacleTimer2(int value);
//void obstacleTimer3(int value);
///void obstacleTimerMain(int value);
//void coinTimer1(int value);
//void coinTimer2(int value);
//void coinTimer3(int value);
//void coinTimerMain(int value);
void key(int key, int mx, int my);
double posX = 0;
double posY = 0;
double rotated1 = 0;
double rotated2 = 0;
double rotated3 = 0;
double  down1 = 800;
double down2 = 0;
int position = 2;
int numberOfLoops = 0;

int obstacleY = 800;
int obstacleX = 1;
int obstacleHits = 0;
//double obstacleYPosition = obstacleY;
//int randomObstacle = 0;

int coinY = 900;
int coinX = 2;
double coinYPosition = coinY;
int randomCoin= 0;
int coinHits = 0;
bool endFlag = false;
bool increased = false;
unsigned seed = time(NULL);
double speed = 1;
//double speedOld = 1;

void main(int argc, char** argr) {
	glutInit(&argc, argr);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Subway");
	glutDisplayFunc(Display);
	glutIdleFunc(Anim);
	glutSpecialFunc(key);
	//glutTimerFunc(0, coinTimerMain, 0);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glPointSize(10.0);
	glLineWidth(5.0);
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
	glutMainLoop();
}

void key(int key, int mx, int my) {
	if (key == GLUT_KEY_LEFT) {
		if (position > 1) {
			posX -= 200;
			position--;
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		if (position < 3) {
			posX += 200;
			position++;
		}
	}
	glutPostRedisplay();
}

void drawCircle(int x, int y, float r) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	glPopMatrix();
}

void Coin1(int x, int y, float r) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotated(rotated1, 0, 1, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	glPopMatrix();
}

void Coin2(int x, int y, float r) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotated(rotated2, 0, 1, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	glPopMatrix();
}

void Coin3(int x, int y, float r) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotated(rotated3, 0, 1, 0);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	glPopMatrix();
}

void drawRect(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}

void drawBackground() {
	glBegin(GL_QUADS);

	//side recs
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 800.0f, 0.0f);
	glVertex3f(0.0f, 800.0f, 0.0f);
	glVertex3f(750.0f, 0.0f, 0.0f);
	glVertex3f(800.0f, 0.0f, 0.0f);
	glVertex3f(800.0f, 800.0f, 0.0f);
	glVertex3f(750, 800.0f, 0.0f);

	//main background
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glVertex3f(750.0f, 0.0f, 0.0f);
	glVertex3f(750.0f, 800.0f, 0.0f);
	glVertex3f(50.0f, 800.0f, 0.0f);

	//left sidewalks
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 100.0f, 0.0f);
	glVertex3f(100.0f, 100.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 200.0f, 0.0f);
	glVertex3f(50.0f, 300.0f, 0.0f);
	glVertex3f(100.0f, 300.0f, 0.0f);
	glVertex3f(100.0f, 200.0f, 0.0f);
	glVertex3f(50.0f, 400.0f, 0.0f);
	glVertex3f(50.0f, 500.0f, 0.0f);
	glVertex3f(100.0f, 500.0f, 0.0f);
	glVertex3f(100.0f, 400.0f, 0.0f);
	glVertex3f(50.0f, 600.0f, 0.0f);
	glVertex3f(50.0f, 700.0f, 0.0f);
	glVertex3f(100.0f, 700.0f, 0.0f);
	glVertex3f(100.0f, 600.0f, 0.0f);


	//right sidewalks
	glVertex3f(700.0f, 0.0f, 0.0f);
	glVertex3f(700.0f, 100.0f, 0.0f);
	glVertex3f(750.0f, 100.0f, 0.0f);
	glVertex3f(750.0f, 0.0f, 0.0f);
	glVertex3f(700.0f, 200.0f, 0.0f);
	glVertex3f(700.0f, 300.0f, 0.0f);
	glVertex3f(750.0f, 300.0f, 0.0f);
	glVertex3f(750.0f, 200.0f, 0.0f);
	glVertex3f(700.0f, 400.0f, 0.0f);
	glVertex3f(700.0f, 500.0f, 0.0f);
	glVertex3f(750.0f, 500.0f, 0.0f);
	glVertex3f(750.0f, 400.0f, 0.0f);
	glVertex3f(700.0f, 600.0f, 0.0f);
	glVertex3f(700.0f, 700.0f, 0.0f);
	glVertex3f(750.0f, 700.0f, 0.0f);
	glVertex3f(750.0f, 600.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 800.0f, 0.0f);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 800.0f, 0.0f);
	glVertex3f(750.0f, 0.0f, 0.0f);
	glVertex3f(750.0f, 800.0f, 0.0f);
	glVertex3f(700.0f, 0.0f, 0.0f);
	glVertex3f(700.0f, 800.0f, 0.0f);
	glVertex3f(300.0f, 0.0f, 0.0f);
	glVertex3f(300.0f, 800.0f, 0.0f);
	glVertex3f(500.0f, 0.0f, 0.0f);
	glVertex3f(500.0f, 800.0f, 0.0f);
	glEnd();

}

void drawCharacter() {
	glColor3f(0.0f, 0.0f, 0.0f);
	drawCircle(400, 150, 20);
	drawRect(375, 80, 50, 50);
	drawRect(375, 50, 20, 30);
	drawRect(405, 50, 20, 30);
}

void drawObstcaleHelper() {
	if (down1 <= ((double)obstacleY-700) && down1 >= ((double)obstacleY-701)) {
		if (down2 <= ((double)obstacleY-1500) && down2 >= ((double)obstacleY-1501)) {
			//srand(seed);
			obstacleX = ((rand() % 3) + 1);
		}
	}
	drawObstcale(obstacleX);
}

void drawCoinHelper() {
	if (down1 <= ((double)coinY - 700) && down1 >= ((double)coinY - 701)) {
		if (down2 <= ((double)coinY - 1500) && down2 >= ((double)coinY - 1501)) {
			//srand(seed);
			coinX = ((rand() % 3) + 1);
			//numberOfLoops++;
		}
	}
	drawCoin(obstacleX);
}

void drawObstcale(int x) {
	glColor3f(0.0f, 1.0f, 0.0f);
	if (x == 1) {
		drawCircle(200, 800, 15);
		drawRect(190, 800 - 45, 20, 35);
	}
	else
		if (x == 2) {
			drawCircle(400, 800, 15);
			drawRect(390, 800 - 45, 20, 35);
		}
		else
			if (x == 3) {
				drawCircle(600, 800, 15);
				drawRect(590, 800 - 45, 20, 35);
			}
}

void drawCoin(int coinX) {

	glColor3f(1.0f, 1.0f, 0.0f);
	if (coinX == 1) {
		Coin1(200, coinY, 20);
	}else if (coinX == 2) {
		Coin2(400, coinY, 20);
	}else if (coinX == 3) {
		Coin3(600, coinY, 20);
	}
	glutPostRedisplay();
}

/*void coinTimer1(int value) {
	coinX = 1;

	glutPostRedisplay();

 glutTimerFunc(0, coinTimerMain, 0);
}

void coinTimer2(int value) {
	coinX = 2;

	glutPostRedisplay();

	glutTimerFunc(0, coinTimerMain, 0);
}

void coinTimer3(int value) {
	coinX = 3;

	glutPostRedisplay();

	glutTimerFunc(0, coinTimerMain, 0);
}

void coinTimerMain(int value) {
	coinY = 900;
	coinYPosition = coinY;
	srand(seed);
	randomCoin = (rand() % 3 + 1);

	if (randomCoin == 1) {
		glutTimerFunc(40*1000, coinTimer1, 0);
	}
	else if (randomCoin == 2) {
		glutTimerFunc(40*1000, coinTimer2, 0);
	}
	else if (randomCoin == 3) {
		glutTimerFunc(40*1000, coinTimer3, 0);
	}
}*/

void Display() {
	if (!endFlag) {
		glPushMatrix();
		glTranslated(0, down1, 0);
		drawBackground();
		glPopMatrix();
		glPushMatrix();
		glTranslated(0, down2, 0);
		drawBackground();
		drawObstcaleHelper();
		///if (numberOfLoops % 6 == 0) {
			drawCoinHelper();
		//}
		glPopMatrix();

		glPushMatrix();
		glTranslated(posX, posY, 0);
		drawCharacter();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 0);
		drawRect(700, 685, 85, 90);
		glColor3f(1, 0, 0);
		char* p0s[20];
		sprintf((char*)p0s, "Score: %d", coinHits);
		print(700, 700, (char*)p0s);
		sprintf((char*)p0s, "Lives: %d",  3- obstacleHits);
		print(700, 750, (char*)p0s);
		glPopMatrix();

		glFlush();
		glutSwapBuffers();
	}
	else {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glColor3f(1, 0, 0);
		char* p0s[20];
		sprintf((char*)p0s, "YOU LOST");
		print(350, 400, (char*)p0s);
		glPopMatrix();

		glFlush();
		glutSwapBuffers();
	}
}

bool areSame(double a, double b) {
	return fabs(a - b) < FLT_EPSILON;
}

void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void Anim() {

	rotated1 += 0.09;
	rotated2 += 0.09;
	rotated3 += 0.09;

	down1 -= 0.07*speed;
	down2 -= 0.07*speed;
	//printf("%d", obstacleHits);
	coinYPosition -= 0.06;

	if (down1 <= 0) {
		down1 = 800;
	}
	if (down2 <= -800) {
		down2 = 0;
	}

	if ((position == coinX) && areSame(down1,74.94)) {
		coinHits++;
	}

	if ((position == obstacleX) && areSame(down1,1199.4)&& areSame(down2,-600.6) ){
		obstacleHits++;

	}
	if (obstacleHits == 3) {
		endFlag = true;
	}
	if (coinHits != 0) {
		if ((coinHits % 5==0) && !increased) {
			increased = true;
			speed = speed * 1.5;
		}
	}
	if (coinHits % 5 != 0 && increased) {
		increased = false;
	}
	glutPostRedisplay();
}

