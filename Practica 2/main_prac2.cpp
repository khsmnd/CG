//Semestre 2017 - 2
//*********** Alumno: Paola Sánchez González      *************//
//************Práctica 2 -	21 / agosto / 2017  **************//


//************* r e p o r t e   p r a c t i c a  2  ***********//
//			INICIALES DEL NOMBRE Y ESTRELLA SIN TRASLAPES


#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	glPointSize(10); //para aumentar el tamaño

	/**************** C L A S E *********************
	//glBegin(GL_POINTS); //solo dibuja puntos
	//glBegin(GL_LINES); //solo toma pares de puntos PARES
	//glBegin(GL_LINE_LOOP); //se unen todos los puntos (vertices) no cares if even or odd
	//glBegin(GL_TRIANGLES); //solo toma en cuenta cada tres pide TERCIAS de vertices
	glBegin(GL_POLYGON); //no need a maximo o un min, not even nor odd
	glVertex3f(0.0f,0.0f,-1.2f);
	glColor3f(0.0, 0.5, 0.4); //COLOR VERDE RARO
	glVertex3f(-3.0f,3.0f,-1.2f);
	glVertex3f(3.5f,4.0f,-1.2f);
	glVertex3f(4.0f,-1.0f,-1.2f);
	glVertex3f(4.0f, -1.0f, -1.2f);
	//Si queda un punto afuera... ir a ORTOGONAL a aumentar --> reshape/ortogonal
	glEnd();
	//*************************************************/

	/*** EJERCICIO DE LA PRACTICA - LETRA C ***********
	glColor3f(1.0,0.0,0.4); //COLOR ROSA FEO
	glBegin(GL_POLYGON);
	glVertex3f(1.0f, 9.0f, -1.2f); 
	glVertex3f(9.0f, 9.0f, -1.2f);
	glVertex3f(9.0f, 7.0f, -1.2f); 
	glVertex3f(3.0f, 7.0f, -1.2f);
	glEnd();

	glColor3f(0.0, 0.5, 0.4); //VERDE RARO
	glBegin(GL_POLYGON);
	glVertex3f(1.0f, 9.0f, -1.2f);
	glVertex3f(3.0f, 7.0f, -1.2f);
	glVertex3f(3.0f, 3.0f, -1.2f);
	glVertex3f(1.0f, 1.0f, -1.2f);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); // VERDE
	glBegin(GL_POLYGON);
	glVertex3f(1.0f, 1.0f, -1.2f);
	glVertex3f(9.0f, 1.0f, -1.2f);
	glVertex3f(9.0f, 3.0f, -1.2f);
	glVertex3f(3.0f, 3.0f, -1.2f);
	glEnd();
	****************************************/

	// R E P O R T E - Practica 2
	//Iniciales del nombre (contorno P - relleno S - contorno G)

	//P
	glColor3f(0.9016, 0.9016, 0.9803); //blanco rosita
	glBegin(GL_LINE_LOOP);
	glVertex3f(1.0f, 1.0f, -1.2f);
	glVertex3f(3.0f, 1.0f, -1.2f);
	glVertex3f(3.0f, 5.0f, -1.2f);
	glVertex3f(7.0f, 5.0f, -1.2f);
	glVertex3f(7.0f, 10.0f, -1.2f);
	glVertex3f(1.0f, 10.0f, -1.2f);
	glEnd();
	//cuadrito de la P	
	glBegin(GL_LINE_LOOP);
	glVertex3f(3.0f, 6.5f, -1.2f);
	glVertex3f(5.5f, 6.5f, -1.2f);
	glVertex3f(5.5f, 9.0f, -1.2f);
	glVertex3f(3.0f, 9.0f, -1.2f);
	glEnd();

	//S
	glColor3f(0.678, 0.847, 0.9019); // azulillo
	glBegin(GL_POLYGON);
	glVertex3f(9.0f, 1.0f, -1.2f);
	glVertex3f(9.0f, 3.0f, -1.2f);
	glVertex3f(13.0f, 3.0f, -1.2f);
	glVertex3f(15.0f, 1.0f, -1.2f);
	glEnd();

	glColor3f(1.0, 0.713, 0.756); //rosa
	glBegin(GL_POLYGON);
	glVertex3f(13.0f, 3.0f, -1.2f);
	glVertex3f(15.0f, 1.0f, -1.2f);
	glVertex3f(15.0f, 6.0f, -1.2f);
	glVertex3f(13.0f, 5.0f, -1.2f);
	glEnd();

	glColor3f(0.87, 1.0, 1.0); // azul
	glBegin(GL_POLYGON);
	glVertex3f(15.0f, 6.0f, -1.2f);
	glVertex3f(13.0f, 5.0f, -1.2f);
	glVertex3f(9.0f, 5.0f, -1.2f);
	glColor3f(0.87, 1.0, 1.0); // azul
	glVertex3f(11.0f, 6.0f, -1.2f);
	glEnd();

	glColor3f(0.827, 0.827, 0.827); // gris
	glBegin(GL_POLYGON);
	glVertex3f(9.0f, 5.0f, -1.2f);
	glColor3f(0.827, 0.827, 0.827); // gris
	glVertex3f(11.0f, 6.0f, -1.2f);
	glVertex3f(11.0f, 8.0f, -1.2f);
	glVertex3f(9.0f, 10.0f, -1.2f);
	glEnd();

	glColor3f(0.9411, 0.5019, 0.5019); //rosado
	glBegin(GL_POLYGON);
	glVertex3f(11.0f, 8.0f, -1.2f);
	glVertex3f(9.0f, 10.0f, -1.2f);
	glVertex3f(15.0f, 10.0f, -1.2f);
	glVertex3f(15.0f, 8.0f, -1.2f);
	glEnd();

	//G 
	glColor3f(0.9016, 0.9016, 0.9803); //blanco rosita
	glBegin(GL_LINE_LOOP);
	glVertex3f(24.0f, 10.0f, -1.2f);
	glVertex3f(17.0f, 10.0f, -1.2f);
	glVertex3f(17.0f, 1.0f, -1.2f);
	glVertex3f(24.0f, 1.0f, -1.2f);
	glVertex3f(24.0f, 6.0f, -1.2f);
	glVertex3f(21.0f, 6.0f, -1.2f);
	glVertex3f(21.0f, 5.0f, -1.2f);
	glVertex3f(23.0f, 5.0f, -1.2f);
	glVertex3f(23.0f, 3.0f, -1.2f);
	glVertex3f(19.0f, 3.0f, -1.2f);
	glVertex3f(19.0f, 8.0f, -1.2f);
	glVertex3f(24.0f, 8.0f, -1.2f);
	glEnd();

	//E S T R E L L A
	 //Pentágono
	glColor3f(0.9411, 0.5019, 0.5019); //rosado
	glBegin(GL_POLYGON);
	glVertex3f(12.5f, -7.0f, -1.2f);
	glVertex3f(10.0f, -12.0f, -1.2f);
	glVertex3f(15.0f, -12.0f, -1.2f);
	glEnd();

	glColor3f(1.0, 0.713, 0.756); //rosa
	glBegin(GL_POLYGON);
	glVertex3f(12.5f, -7.0f, -1.2f);
	glVertex3f(10.0f, -12.0f, -1.2f);
	glVertex3f(9.0f, -8.0f, -1.2f);
	glEnd();

	glColor3f(0.87, 1.0, 1.0); // azul
	glBegin(GL_POLYGON);
	glVertex3f(12.5f, -7.0f, -1.2f);
	glVertex3f(15.0f, -12.0f, -1.2f);
	glVertex3f(16.0f, -8.0f, -1.2f);
	glEnd();

	glColor3f(0.827, 0.827, 0.827); // gris
	glBegin(GL_POLYGON);
	glVertex3f(12.5f, -7.0f, -1.2f);
	glVertex3f(9.0f, -8.0f, -1.2f);
	glVertex3f(12.5f, -5.0f, -1.2f);
	glEnd();

	glColor3f(0.678, 0.847, 0.9019); // azulillo
	glBegin(GL_POLYGON);
	glVertex3f(12.5f, -7.0f, -1.2f);
	glVertex3f(16.0f, -8.0f, -1.2f);
	glVertex3f(12.5f, -5.0f, -1.2f);
	glEnd();

	//picos
	glColor3f(0.37, 0.619, 0.627); //
	glBegin(GL_TRIANGLES);
	glVertex3f(12.5f, -15.0f, -1.2f);
	glVertex3f(10.0f, -12.0f, -1.2f);
	glVertex3f(15.0f, -12.0f, -1.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(7.0f, -10.0f, -1.2f);
	glVertex3f(10.0f, -12.0f, -1.2f);
	glVertex3f(9.0f, -8.0f, -1.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(18.0f, -10.0f, -1.2f);
	glVertex3f(15.0f, -12.0f, -1.2f);
	glVertex3f(16.0f, -8.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(9.5f, -4.0f, -1.2f);
	glVertex3f(9.0f, -8.0f, -1.2f);
	glVertex3f(12.5f, -5.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(16.0f, -4.0f, -1.2f);
	glVertex3f(16.0f, -8.0f, -1.2f);
	glVertex3f(12.5f, -5.0f, -1.2f);
	glEnd();

	glFlush();
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

	// Ortogonal
	glOrtho(-5,30,-25,15,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}