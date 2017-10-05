//Semestre 2012 - 1
//**************Alumnno: Sánchez González Paola ****************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5;
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position

CTexture t_crackedgrass;
CTexture t_wood;
CTexture t_stone;
CTexture t_mud;
CTexture t_rock;
CTexture t_cozzy;
CTexture t_cam;
CTexture t_pos;

int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D); //SE AGREGÓ

							 //glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_crackedgrass.LoadTGA("doors.tga");
	t_crackedgrass.BuildGLTexture();
	t_crackedgrass.ReleaseImage();

	t_mud.LoadTGA("mud.tga");
	t_mud.BuildGLTexture();
	t_mud.ReleaseImage();

	t_wood.LoadTGA("wood2.tga");
	t_wood.BuildGLTexture();
	t_wood.ReleaseImage();

	t_stone.LoadTGA("stone.tga");
	t_stone.BuildGLTexture();
	t_stone.ReleaseImage();

	t_rock.LoadTGA("rock.tga");
	t_rock.BuildGLTexture();
	t_rock.ReleaseImage();

	t_cozzy.LoadTGA("cozzy.tga");
	t_cozzy.BuildGLTexture();
	t_cozzy.ReleaseImage();

	t_cam.LoadTGA("hog.tga");
	t_cam.BuildGLTexture();
	t_cam.ReleaseImage();

	t_pos.LoadTGA("pos.tga");
	t_pos.BuildGLTexture();
	t_pos.ReleaseImage();
}

void renderBitmapCharacter(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void prisma(GLuint textura1, GLuint textura2, GLuint textura3, GLuint textura4, GLuint textura5, GLuint textura6)  //Funcion creacion prisma
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

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]); // 0
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]); // 4
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]); // 7
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]); // 1
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura4);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]); // 1
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]); // 7  //recorrí los vertices
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]); // 6
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]); // 2
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura5);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura6);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();
		glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);

		glPushMatrix(); //base
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, -4.063, -2.0);
			glScalef(14.0,0.125,14.0);
			prisma(t_mud.GLindex, t_mud.GLindex, t_mud.GLindex, t_mud.GLindex, t_mud.GLindex, t_mud.GLindex);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0); //estructura
			glTranslatef(0.0,3.0,-2.0);
			glScalef(8.0, 14.0, 8.0);
			prisma(t_wood.GLindex, t_wood.GLindex, t_cam.GLindex, t_wood.GLindex, t_stone.GLindex, t_wood.GLindex);
		glPopMatrix();
			//prisma(t_wood.GLindex, t_wood.GLindex, t_wood.GLindex, t_wood.GLindex, t_wood.GLindex, t_wood.GLindex);
	
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0); //puerta
			glTranslatef(0.0, -1.0, 2.0);
			glScalef(4.0, 6.0, 0.125);
			prisma(t_crackedgrass.GLindex, t_crackedgrass.GLindex, t_crackedgrass.GLindex, t_crackedgrass.GLindex, t_crackedgrass.GLindex, t_crackedgrass.GLindex);
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0); //camino 
			glTranslatef(0.0, -4.0, 3.5);
			glScalef(3.0, 0.25, 3.0);
			prisma(t_stone.GLindex, t_stone.GLindex, t_stone.GLindex, t_stone.GLindex, t_stone.GLindex, t_stone.GLindex);
		glPopMatrix();

		glPushMatrix(); //mesa
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, -1.0, -4.0);
			glScalef(2.0, 0.3, 2.0);
			prisma(t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex);
		glPopMatrix();

		glPushMatrix(); //PATA 1
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.85, -2.5, -4.75);
			glScalef(0.25, 3.0, 0.25);
			prisma(t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 2
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.85, -2.5, -4.75);
			glScalef(0.25, 3.0, 0.25);
			prisma(t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 3
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(-0.85, -2.5, -3.15);
			glScalef(0.25, 3.0, 0.25);
			prisma(t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex);
		glPopMatrix();

		glPushMatrix(); //pata 4
			glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.85, -2.5, -3.15);
			glScalef(0.25, 3.0, 0.25);
			prisma(t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex, t_rock.GLindex);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.0, 0.0, 0.0);
			prisma(t_cozzy.GLindex, t_cozzy.GLindex, t_cozzy.GLindex, t_cozzy.GLindex, t_cozzy.GLindex, t_cozzy.GLindex);
		glPopMatrix();

		glPushMatrix(); // tetera
		glColor3f(1.0, 1.0, 1.0);
			glTranslatef(0.0, -0.5, -4.0);
			glutSolidTeapot(0.4);
		glPopMatrix();

		/*glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //letrero
		glTranslatef(0.0, 6.0, 2.0);
		glScalef(6.0, 4.0, 0.1);
		prisma(t_pos.GLindex, t_pos.GLindex, t_pos.GLindex, t_pos.GLindex, t_pos.GLindex, t_pos.GLindex);
		glPopMatrix();*/

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
	renderBitmapCharacter(-11, 10.5, -14, (void *)font, "ejercicio de casa");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

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
	glLoadIdentity();
}

void animacion()
{

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		pos_camZ += 0.5f;
		//eye_camZ -= 0.5f;
		break;

	case 's':
	case 'S':
		pos_camZ -= 0.5f;
		//eye_camZ += 0.5f;
		break;

	case 'a':
	case 'A':
		pos_camX += 0.5f;
		//eye_camX -= 0.5f;
		break;
	case 'd':
	case 'D':
		pos_camX -= 0.5f;
		//eye_camX += 0.5f;
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
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX - 15) % 360;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX + 15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY - 15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY + 15) % 360;
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
	glutInitWindowSize(5000, 5000);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 8"); // Nombre de la Ventana
									//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}