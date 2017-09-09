//Semestre 2018 - 2
//************ Alumno: Sánchez González Paola    *************//
//**********   Perrito: Lilo, es un pug :B     **************//

#include "Main.h"

float transZ = -5.0f;
float transX, transY;
int screenW = 0.0;
int screenH = 0.0;
float r, g, b;

float angleX, angleY, angleZ;


void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
														//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float r, float g, float b)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glColor3f(r,g,b);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(transX, transY, transZ);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);

	glPushMatrix();
	glScalef(2.0, 3.0, 2.0);
	prisma(0.77,0.51,0.25); // (0,0,0,) perrito cabeza
	glPopMatrix();

	glPushMatrix(); //orejita 1
	glTranslatef(1.0, 1.75, 0.25);
	glScalef(0.5, 0.5, 0.5);
	prisma(0.38,0.26,0.13);
	glPopMatrix();

	glPushMatrix(); //orejita 2
	glTranslatef(-1.0, 1.75, 0.25);
	glScalef(0.5, 0.5, 0.5);
	prisma(0.38, 0.26, 0.13);
	glPopMatrix();

	glPushMatrix(); //nariz
	glTranslatef(0.0, 0.0, 1.25);
	glScalef(0.5, 0.5, 0.5);
	prisma(0.19,0.13,0.07);
	glPopMatrix();

	glPushMatrix(); //hocico 1
	glTranslatef(0.0, -0.75, 1.5);
	prisma(0.56,0.38,0.21);
	glPopMatrix();

	glPushMatrix(); //hocico 2
	glTranslatef(0.0, -0.75, 2.0);
	glScalef(0.4, 0.1, 0.2);
	prisma(0.0, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix(); //diente raro 1
	glTranslatef(0.25, -0.75, 2.0);
	glScalef(0.1, 0.1, 0.2);
	prisma(1.0,1.0,1.0);
	glPopMatrix();

	glPushMatrix(); //diente raro 1
	glTranslatef(-0.25, -0.75, 2.0);
	glScalef(0.1, 0.1, 0.2);
	prisma(1.0,1.0,1.0);
	glPopMatrix();

	glPushMatrix(); //ojo 1
	glTranslatef(0.5, 0.5, 1.125);
	glScalef(0.5, 0.5, 0.25);
	prisma(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix(); //ojo 2
	glTranslatef(-0.5, 0.5, 1.125);
	glScalef(0.5, 0.5, 0.25);
	prisma(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix(); //ojo 1
	glTranslatef(0.5625, 0.5625, 1.25);
	glScalef(0.25, 0.25, 0.125);
	prisma(0.0, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix(); //ojo 2
	glTranslatef(-0.5625, 0.5625, 1.25);
	glScalef(0.25, 0.25, 0.125);
	prisma(0.0, 0.0, 0.0);
	glPopMatrix();

	glPushMatrix(); //cuello
	glTranslatef(0.0, -1.5, 0.0);
	glScalef(2.0, 0.25, 2.0);
	prisma(0.92,0.63,0.35);
	glPopMatrix();

	glPushMatrix(); //cuerpo
	glTranslatef(0.0, -0.50, -3.0);
	glScalef(5.0, 4.0, 4.0);
	prisma(0.55,0.39,0.21);
	glPopMatrix();

	glPushMatrix(); //pata trasera 1
	glTranslatef(1.0, -3.0, -4.0);
	prisma(0.92,0.66,0.35);
	glPopMatrix();

	glPushMatrix(); //pata trasera 2
	glTranslatef(-1.0, -3.0, -4.0);
	prisma(0.92, 0.66, 0.35);
	glPopMatrix();

	glPushMatrix(); //pata del 1
	glTranslatef(1.0, -3.0, -2.0);
	prisma(0.92, 0.66, 0.35);
	glPopMatrix();

	glPushMatrix(); //pata del 2
	glTranslatef(-1.0, -3.0, -2.0);
	prisma(0.92, 0.66, 0.35);
	glPopMatrix();

	glPushMatrix(); //rabo 1
	glTranslatef(0.0, 0.0, -5.5);
	prisma(0.37,0.27,0.14);
	glPopMatrix();

	glPushMatrix(); //rabo 2
	glRotatef(-45, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 4.75, -4.75); // x y z
	prisma(0.77, 0.51, 0.25);
	glPopMatrix();

	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'q':
	case 'Q':
		transY -= 0.2f;
		break;
	case 'e':
	case 'E':
		transY += 0.2f;
		break;
	case 't': //en x
	case 'T':
		angleX -= 1.0f;
		break;
	case 'r': //en x
	case 'R':
		angleX += 1.0f;
		break;
	case 'l': //en y
	case 'L':
		angleY -= 1.0f;
		break;
	case 'k': //en y
	case 'K':
		angleY += 1.0f;
		break;
	case 'v': //en z
	case 'V':
		angleZ -= 1.0f;
		break;
	case 'b': //en z
	case 'B':
		angleZ += 1.0f;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}