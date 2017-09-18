//Semestre 2018 - 1
//********Alumno: Paola Sánchez González **************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int merc, ven, tierra, luna, mar, jup, sat = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(2.0, 12, 12);  //Draw Sun (radio,Horizontal,Vertical);
	glPopMatrix();

	glPushMatrix();
	//mercurio
	glColor3f(0.56, 0.42, 0.33);
	glRotatef(merc, 0.0, 0.0, 1.0); //trasla
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(merc, 0.0, 1.0, 0.0);
	glutSolidSphere(0.25, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//venus
	glColor3f(0.72, 0.25, 0.33);
	glRotatef(ven, 0.0, 1.0, 0.0); //trasla
	glTranslatef(4.0, 0.2, 0.2);
	glRotatef(ven, 0.0, 1.0, 0.0);
	glutSolidSphere(0.50, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//tierra
	glColor3f(0.22, 0.25, 0.74);
	glRotatef(tierra, 1.0, 0.0, 1.0); //trasla
	glTranslatef(6.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glutSolidSphere(1.0, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1.0, 0.0, 1.0); //trasla
	glTranslatef(1.25, 0.2, 0.2);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(0.125, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//marte
	glColor3f(0.82, 0.22, 0.13);
	glRotatef(mar, 0.0, 1.0, 1.0); //trasla
	glTranslatef(9.0, 0.2, 0.2);
	glRotatef(mar, 1.0, 0.0, 0.0);
	glutSolidSphere(0.75, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//jupiter
	glColor3f(0.55, 0.72, 0.43);
	glRotatef(jup, 0.0, 0.0, 1.0); //trasla
	glTranslatef(13.0, 0.2, 0.2);
	glPushMatrix();
	glRotatef(ven, 0.0, 1.0, 0.0);
	glutSolidSphere(1.5, 12, 12);
	glPopMatrix();
	glPushMatrix();
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 1.0, 0.0); //trasla
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(0.125, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 0.0, 1.0); //trasla
	glTranslatef(3.0, 0.2, 0.2);
	glRotatef(45, 1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(0.125, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 1.0, 1.0); //trasla
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(45, 1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(0.1, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//saturno
	glColor3f(0.12, 0.22, 0.13);
	glRotatef(sat, 0.0, 1.0, 1.0); //trasla
	glTranslatef(19.0, 0.2, 0.2);
	glRotatef(sat, 1.0, 0.0, 0.0);
	glutSolidSphere(2.0, 12, 12);

	glPushMatrix();
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 0.0, 1.0); //trasla
	glTranslatef(3.0, 0.2, 0.2);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(0.125, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//luna
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 0.0, 1.0, 0.0); //trasla
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(luna, 0.0, 1.0, 0.0);
	glutSolidSphere(0.1, 12, 12);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.12, 0.22, 0.13);
	glutSolidTorus(0.5, 4.0, 10, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//urano
	glColor3f(0.65, 0.22, 0.83);
	glRotatef(merc, 0.0, 0.0, 1.0); //trasla
	glTranslatef(24.0, 0.2, 0.2);
	glRotatef(merc, 0.0, 1.0, 0.0);
	glutSolidSphere(1.2, 12, 12);
	glPopMatrix();

	glPushMatrix();
	//neptuno
	glColor3f(0.12, 0.25, 0.43);
	glRotatef(ven, 0.0, 1.0, 0.0); //trasla
	glTranslatef(28.0, 0.2, 0.2);
	glRotatef(ven, 0.0, 1.0, 0.0);
	glutSolidSphere(1.4, 12, 12);
	glPopMatrix();

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime() obtiene los frames per sec
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30) {
		sol = (sol - 5) % 360;
		merc = (merc - 2) % 360;
		ven = (ven - 3) % 360;
		tierra = (tierra - 4) % 360;
		luna = (luna - 5) % 360;
		mar = (mar - 2) % 360;
		jup = (jup - 3) % 360;
		sat = (sat - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}
	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

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
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}