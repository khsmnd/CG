//Semestre 2018 - 1
//************** Alumno (s): Paola Sánchez González


#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

#include "Main.h"

//RECIEN AGREGADO
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;

float movDedo1 = 0.0f;
float movDedo2 = 0.0f;
float movDedo3 = 0.0f;

//END

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float movHombro = 0.0f,
movCodo = 0.0f;

#define MAX_FRAMES 25
int i_max_steps = 90; //VARIABLES PARA LOS CUADROS INTERMEDIOS (entre menos más rápida pero también muy brusca)
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;

	float movDedo1; //la variable para guardar
	float movDedo1Inc; //para hacer los calculos

	float movDedo2;
	float movDedo2Inc;
	float movDedo3;
	float movDedo3Inc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

//AGREGADO	

void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
	KeyFrame[FrameIndex].giroMonito = giroMonito;
	KeyFrame[FrameIndex].movDedo1 = movDedo1;
	KeyFrame[FrameIndex].movDedo2 = movDedo2;
	KeyFrame[FrameIndex].movDedo3 = movDedo3;

	FrameIndex++;
}

void resetElements(void) //regresa al primer cuadro clave
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	rotRodIzq = KeyFrame[0].rotRodIzq;
	giroMonito = KeyFrame[0].giroMonito;
	movDedo1 = KeyFrame[0].movDedo1;
	movDedo2 = KeyFrame[0].movDedo2;
	movDedo3 = KeyFrame[0].movDedo3;

}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;
	KeyFrame[playIndex].movDedo1Inc = (KeyFrame[playIndex + 1].movDedo1 - KeyFrame[playIndex].movDedo1) / i_max_steps;
	KeyFrame[playIndex].movDedo2Inc = (KeyFrame[playIndex + 1].movDedo2 - KeyFrame[playIndex].movDedo2) / i_max_steps;
	KeyFrame[playIndex].movDedo3Inc = (KeyFrame[playIndex + 1].movDedo3 - KeyFrame[playIndex].movDedo3) / i_max_steps;
}

//ASDADD

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
 
		glRotatef(movHombro, 0.0, 0.0, 1.0);
		// para ir desde el origen
		glTranslatef(1.25, 0.0, 0.0);
		//a partir de la fig A
		glPushMatrix();
			glScalef(2.5, 1.0, 1.0);
			glColor3f(1.0, 1.0, 1.0);
			prisma(); //A
		glPopMatrix();

			glTranslated(1.25, 0.0, 0.0); //para ponernos en la sig. articulación
			glRotated(movCodo, 0.0, 1.0, 0.0);
			glTranslated(1.0, 0.0, 0.0);
		glPushMatrix(); //para que sea a partir del centro de B
			glScalef(2.0, 1.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma(); //B (codo)
		glPopMatrix();

glPushMatrix(); //dedos indep

		glTranslatef(1.0, 0.35, 0.375); //porque hay que bajar y luego subir la mitad de .25 para ponernos en la sig. artic
		glRotatef(movDedo1, 0.0, 0.0, 1.0); //mov para
		glTranslatef(0.375, 0.0, 0.0); //para hacerrrrlo
	glPushMatrix();
		glScalef(0.75, 0.3, 0.25);
		glColor3f(1.0, 1.0, 0.0);
		prisma(); // C (dedo)
	glPopMatrix();

		glTranslated(0.5, 0.0, 0.0);
		glRotated(movDedo2, 0.0, 0.0, 1.0);
		glTranslatef(0.375, 0.0, 0.0);
	glPushMatrix();
			glScalef(1.0, 0.3, 0.25);
			glColor3f(1., 1.0, 1.0);
			prisma(); //D (dedo)
	glPopMatrix();
	
glPopMatrix();

glPushMatrix();

//volvemos a B
		glTranslatef(1.0, -0.35, 0.375); //ponernos en la arti
		glRotatef(movDedo3, 0.0, -1.0, 0.0); //en qué eje y VA HACIA ADENTRO
		glTranslatef(0.375, 0.0, 0.0); //ponernos en la figura
	glPushMatrix();
		glScalef(0.75, 0.3, 0.25); //lo que mide
		glColor3f(1.0, 1.0, 0.0);
		prisma(); // E (dedo) PULGAR
	glPopMatrix();

	glTranslatef(0.375, 0.0, 0.0); //ponernos en la arti
		glRotatef(movDedo3, 0.0, -1.0, 0.0); //en qué eje y VA HACIA ADENTRO
		glTranslatef(0.375, 0.0, 0.0); //ponernos en la figura NOS RECORRIMOS	
	glPushMatrix();
		glScalef(0.75, 0.3, 0.25); //lo que mide
		glColor3f(1.0, 1.0, 1.0);
		prisma(); // F (dedo) PULGAR
	glPopMatrix();

glPopMatrix();

//volvemos a partir de B

glPushMatrix();
	glTranslatef(1.0, 0.35, 0.0); //ponernos en la arti **********
		glRotatef(movDedo1, 0.0, 0.0, 1.0); //en qué eje z *****
		glTranslatef(0.5, 0.0, 0.0); //ponernos en la figura
	glPushMatrix();
		glScalef(1.0, 0.3, 0.25); //lo que mide
		glColor3f(1.0, 1.0, 0.0);
		prisma(); // G (dedo) ANULAR
	glPopMatrix();

	glTranslatef(0.75, 0.0, 0.0); //ponernos en la arti **********
		glRotatef(movDedo2, 0.0, 0.0, 1.0); //en qué eje z *****
		glTranslatef(0.5, 0.0, 0.0); //ponernos en la figura
	glPushMatrix();
		glScalef(1.5, 0.3, 0.25); //lo que mide
		glColor3f(1.0, 1.0, 1.0);
		prisma(); // H (dedo) ANULAR
	glPopMatrix();
glPopMatrix();

//volvemos a empezar desde B

glPushMatrix();
	glTranslatef(1.0, 0.35, -0.375); //ponernos en la arti **********
		glRotatef(movDedo3, 0.0, 0.0, 1.0); //en qué eje z *****
		glTranslatef(0.5, 0.0, 0.0); //ponernos en la figura
	glPushMatrix();
		glScalef(1.0, 0.3, 0.25); //lo que mide
		glColor3f(1.0, 1.0, 0.0);
		prisma(); // I
	glPopMatrix();

	glTranslatef(0.5, 0.0, 0.0); //ponernos en la arti **********
		glRotatef(movDedo3, 0.0, 0.0, 1.0); //en qué eje z *****
		glTranslatef(0.5, 0.0, 0.0); //ponernos en la figura
	glPushMatrix();
		glScalef(1.0, 0.3, 0.25); //lo que mide
		glColor3f(1.0, 1.0, 1.0);
		prisma(); // J
	glPopMatrix();
glPopMatrix();

	glutSwapBuffers ( );
  // Swap The Buffers
}


void animacion()
{
	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movDedo1 += KeyFrame[playIndex].movDedo1Inc;
			movDedo2 += KeyFrame[playIndex].movDedo2Inc;
			movDedo3 += KeyFrame[playIndex].movDedo3Inc;

			i_curr_steps++;
		}

	}


	glutPostRedisplay();
}



void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;

		case 'r':
			if(movHombro < 90.0)
			movHombro +=0.7f;
			break;

			case 'R':
				if(movHombro > -110.0)
			movHombro -=0.7f;
			break;

			case 't':
				if(movCodo > -95.0)
				movCodo -=0.7f;
			break;

			case 'T':
				if(movCodo < 5.0)
			movCodo +=0.7f;
			break;

			case 'o':
				//if(movDedo1 < 5.0)
			movDedo1 -=0.7f;
			break; 

			case 'O':
				//if(movDedo1 < 5.0)
				movDedo1 += 0.7f;
				break;

			case 'p':
				//if(movDedo1 < 5.0)
			movDedo2 -=0.7f;
			break;

			case 'P':
				//if(movDedo1 < 5.0)
				movDedo2 += 0.7f;
				break;

			case 'q':
				//if(movDedo1 < 5.0)
				movDedo3 -= 0.7f;
				break;

			case 'Q':
				//if(movDedo1 < 5.0)
				movDedo3 += 0.7f;
				break;

		/*	case 'y':
				//if(movDedo1 < 5.0)
				//movDedo -= 0.7f;
				break;

			case 'Y':
				//if(movDedo1 < 5.0)
				//movDedo- += 0.7f;
				break;*/

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
