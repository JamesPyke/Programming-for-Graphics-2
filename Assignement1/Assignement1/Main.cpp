#include <glut.h>
#include <IL/ilut.h>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "Box.h"
#include "Text.h"
#include <vector>

int sizeX = 1000;
int sizeY = 500;
int sizeZ = 0;
int windowID;
int window2ID;
int player1Score = 0;
int player2Score = 0;
int Angle = 45;

GLuint background;

Paddle Paddle1;
Paddle Paddle2;
Ball Ball1;
Box Box1;
Box Box2;
Box Box3;
Box Box4;
Box Box5;
Box Box6;
Box Box7;
Box Box8;

Text textHel;
Text textTNR;

std::vector<Box> score1;
std::vector<Box> score2;

void init()
{
	Ball1.setPosition(Vector(sizeX / 2, sizeY / 2, 0));
	Ball1.setVelocity(Vector(Ball1.speed, Ball1.speed, 0));

	Paddle1.SetPosition(Vector(16, Paddle1.size.y * 2, 0));
	Paddle2.SetPosition(Vector(952, Paddle2.size.y * 2, 0));

	Paddle1.initTextures();
	Paddle2.initTextures();
}

void init2()
{
	//Player 2
	Box1.setPosition(Vector(0.1, 0.15, 0));
	Box2.setPosition(Vector(0.3, 0.15, 0));
	Box3.setPosition(Vector(0.5, 0.15, 0));
	Box4.setPosition(Vector(0.7, 0.15, 0));
	//Player1
	Box5.setPosition(Vector(0.1, 0.65, 0));
	Box6.setPosition(Vector(0.3, 0.65, 0));
	Box7.setPosition(Vector(0.5, 0.65, 0));
	Box8.setPosition(Vector(0.7, 0.65, 0));
	score2.push_back(Box1);
	score2.push_back(Box2);
	score2.push_back(Box3);
	score2.push_back(Box4);
	score1.push_back(Box5);
	score1.push_back(Box6);
	score1.push_back(Box7);
	score1.push_back(Box8);
}


void moveBall()
{
	Ball1.update();
	if (Paddle1.position.x < Ball1.position.x + Ball1.radius
		&& Paddle1.position.x + Paddle1.size.x > Ball1.position.x - Ball1.radius
		&& Paddle1.position.y < Ball1.position.y
		&& Paddle1.position.y + Paddle1.size.y > Ball1.position.y) {

		Ball1.setVelocity(Vector(-Ball1.getVelocity().x, Ball1.getVelocity().y, -Ball1.getVelocity().z));
	}
	else if (Paddle2.position.x < Ball1.position.x + Ball1.radius
		&& Paddle2.position.x + Paddle2.size.x > Ball1.position.x - Ball1.radius
		&& Paddle2.position.y < Ball1.position.y
		&& Paddle2.position.y + Paddle2.size.y > Ball1.position.y) {

		Ball1.setVelocity(Vector(-Ball1.getVelocity().x, Ball1.getVelocity().y, -Ball1.getVelocity().z));
	}

	else if (Ball1.position.y + Ball1.radius >= 500)
	{
		Ball1.setVelocity(Vector(Ball1.getVelocity().x, -Ball1.getVelocity().y, -Ball1.getVelocity().z));
	}

	else if (Ball1.position.y - Ball1.radius <= 0)
	{
		Ball1.setVelocity(Vector(Ball1.getVelocity().x, -Ball1.getVelocity().y, -Ball1.getVelocity().z));
	}
}

void playerScore()
{
	if (Ball1.position.x >= 1000)
	{
		player1Score = player1Score < 4 ? player1Score + 1 : 1;
	}
	if (Ball1.position.x <= 0)
	{
		player2Score = player2Score < 4 ? player2Score + 1 : 1;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	moveBall();
	Ball1.draw();
	Ball1.reset();
	Paddle1.draw();
	Paddle2.draw();
	playerScore();
	glutSwapBuffers();
	glutPostRedisplay();
}

void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < player1Score; i++)
	{
		score1[i].draw();
	}
	for (int i = 0; i < player2Score; i++)
	{
		score2[i].draw();
	}
	textHel.displayTextHel(0.05, 0.85, 1, 1, 1, "Player 1 Score: ");
	textHel.displayTextHel(0.05, 0.35, 1, 1, 1, "Player 2 Score: ");

	glutSwapBuffers();
	glutPostRedisplay();
}

void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	textHel.displayTextHel(0.4, 0.8, 1, 1, 1, "Controls ");
	textHel.displayTextHel(0.15, 0.5, 0.141, 0.564, 0.737, "Player1: ");
	textHel.displayTextHel(0.2, 0.38, 0.141, 0.564, 0.737, "Up: W ");
	textHel.displayTextHel(0.2, 0.28, 0.141, 0.564, 0.737, "Down: S ");
	textHel.displayTextHel(0.55, 0.5, 1, 0, 0, "Player2: ");
	textHel.displayTextHel(0.6, 0.38, 1, 0, 0, "Up: Up Arrow ");
	textHel.displayTextHel(0.6, 0.28, 1, 0, 0, "Down: Down Arrow ");
	glutSwapBuffers();
	glutPostRedisplay();
}

void myMenu(GLint menuNumber)
{
	switch (menuNumber) {
	case 1:
		glColor3f(1.0, 0.0, 0.0);
		break;
	case 2:
		glColor3f(0.0, 0.0, 1.0);
		break;
	case 3:
		glColor3f(1.0, 1.0, 0.0);
		break;
	case 4:
		glColor3f(0.0, 1.0, 0.0);
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w': //Up -- W
		Paddle1.move(Vector(0, 10, 0));
		std::cout << "Up Pressed" << std::endl;
		break;

	case 's': //Down -- S
		Paddle1.move(Vector(0, -10, 0));
		std::cout << "Down Pressed" << std::endl;
		break;
	}
}

void keyboard2(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP:
		Paddle2.move(Vector(0, 10, 0));
		break;
	case GLUT_KEY_DOWN:
		Paddle2.move(Vector(0, -10, 0));
		break;
	}
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	//Display 3
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(750, 200);
	glutInitWindowPosition(250, 600);
	windowID = glutCreateWindow("Controls");
	glOrtho(0.0, 1, 0.0, 1, -1, 1);
	glutDisplayFunc(display3);

	//Display 2(Score Screen)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1250, 100);
	windowID = glutCreateWindow("Score");
	glOrtho(0.0, 1, 0.0, 1, -1, 1);
	glutDisplayFunc(display2);
	init2();

	//Display 1(Game Screen)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(sizeX, sizeY);
	glutInitWindowPosition(250, 100);
	glutCreateWindow("Game Screen");
	glOrtho(0, sizeX, 0, sizeY, -1, 1);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboard2);
	init();

	//Menu
	glutCreateMenu(myMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Yellow", 3);
	glutAddMenuEntry("Green", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//Hides the console
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	glutMainLoop();
}