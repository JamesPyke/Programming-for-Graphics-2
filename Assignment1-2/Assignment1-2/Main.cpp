#include <glut.h>
#include <IL/ilut.h> 
#include <iostream>
#include <random>

float Angle = 0.0f;
float speed = 0.05f;
float x = 0.8;
float y = 0.8;
float z = 0.0;

int window1ID;
int window2ID;

GLuint myImage; 
GLuint myImage2;
GLuint myImage3;
GLuint myImage4;
GLuint myImage5;
GLuint myImage6;

GLfloat qaGreen[] = { 0.0, 1.0, 0.0, 1.0 };		// values for green
GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };		// values for white
GLfloat qaBlue[] = { 0.0, 0.0, 1.0, 1.0 };		// values for blue
GLfloat qaRed[] = { 1.0, 0.0, 0.0, 1.0 };		// values for red
GLfloat qaEmmission[] = { 0.8, 0.8, 0.8, 1.0 }; // values for emmisve surface

GLfloat randomFloat() 
{
	std::uniform_int_distribution<int> randomFloat(0, 100);
	std::random_device randomDevice;

	return (GLfloat)randomFloat(randomDevice) / 100;
}

void InitTextures(void)
{
	// Define wrapping behaviour for material
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Define texture Filtering behaviour for material
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	//myImage = ilutGLLoadImage("box.bmp"); // Load an image and apply it to the variable myImage
	myImage = ilutGLLoadImage("one.bmp");
	myImage2 = ilutGLLoadImage("two.bmp");
	myImage3 = ilutGLLoadImage("three.bmp");
	myImage4 = ilutGLLoadImage("four.bmp");
	myImage5 = ilutGLLoadImage("five.bmp");
	myImage6 = ilutGLLoadImage("six.bmp");

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Define how material is sent further down the rendering pipeline

}

void Cube() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage2);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage3);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage4);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage5);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, myImage6);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Light()
{
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);  // Use the normals from each surface to calculate lighting (FALSE = faster but not as accurate)
	glEnable(GL_LIGHTING);		// Enable Lighting
	glEnable(GL_LIGHT0);		// Create a light called LIGHT0

	GLfloat qaAmbientLight[] = { 0.5, 0.5, 0.5, 1.0 }; // ambient settings
	GLfloat qaDiffuseLight[] = { 0.5, 0.5, 0.5, 1.0 }; // diffuse settings
	GLfloat qaSpecularLight[] = { 0.6, 0.6, 0.6, 1.0 }; // specular settings
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);   // Define ambient light behaviour
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);   // Define diffuse ambient light behaviour
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight); // Define specular light behaviour

	////////////////////////////////////////////////////////////////  
	//These commands add specular and diffuse lisghting to the material, so when the light is applied to the material
	// you see a better gradation between the specular and diffuse areas
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glColorMaterial(GL_FRONT, GL_SPECULAR);

	GLfloat qaLightPosition[] = { 0.0, 0.0, -1.8, 1.0 };	// vector to store location of light0
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);	// Set position of light0

}

void display() 
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMaterialfv(GL_FRONT, GL_AMBIENT, qaRed);	// Set the reflective colour for ambient light
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaBlue);	// set the reflective colour for diffuse light
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaBlue);	// set the colour for specular light
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);		// define how shiney the surface is

	// Add perspective view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 9.0);

	// moving the camera and target the same relative distance, creates a pan
	gluLookAt(0.0, 6.0, 0.0, 0.0, 0.0, -7.0, 0, 1, 0);

	// Switch back to Model view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(0.0, 2.5, -4.0);
	glRotatef(Angle += speed, Angle += speed, Angle += speed, Angle += speed);
	Cube();
	Light();

	glutSwapBuffers();

	glutPostRedisplay();
}


void initGL()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


void myMenu(GLint menuNumber) {}

void SpeedMenu(GLint submenuNumber) {
	switch (submenuNumber) {
	case 10:
		speed += 0.05f;
		break;
	case 11:
		speed -= 0.05f;
		break;
	case 12:
		speed = 0.05f;
	}
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1000, 0);
	glutCreateWindow("cube 1");
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	ilInit();
	iluInit();
	ilutRenderer(ILUT_OPENGL);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	InitTextures();
	initGL();
	glutDisplayFunc(display);

	int SpeedMenuID = glutCreateMenu(SpeedMenu);
	glutAddMenuEntry("Faster", 10);
	glutAddMenuEntry("Slower", 11);
	glutAddMenuEntry("Reset", 12);

	glutCreateMenu(myMenu);
	glutAddSubMenu("Change Speed", SpeedMenuID);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	glutMainLoop();
}