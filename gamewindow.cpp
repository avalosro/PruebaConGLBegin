#include "gamewindow.h"
#include <math.h>
#define v3f glVertex3f  

void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
}

GameWindow::GameWindow(bool running, GLFWwindow* window): _running(running)
{
	_window = window;
	/* glClearColor - specify clear values for the color buffers
	   void glClearColor(GLfloat red, GLfloat green, GLfloat blue,
			     GLfloat alpha); */
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	/* This function retrieves the size, in pixels, of the framebuffer of
	 * the specified window. */
	glfwGetFramebufferSize(window, &_width, &_height);
	glViewport(0, 0, _width, _height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* void glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
			GLdouble top, GLdouble nearVal, GLdouble farVal); */
	glOrtho(0.0, _width, 0.0, _height, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}

void GameWindow::render()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(1.2f, .2f, .5f);



   /*Poligono formando una planicie*/
   glColor3f(3.5f, 8.2f, 0.5f);
   glBegin(GL_POLYGON);

   v3f( 1.0, 100.0, 1.0 );   v3f( 1.0, -100.0, 1.0 );
   v3f( 100000.0, -350.0, -300.0 ); v3f( 110.0, 300.0, 120.0 );

   glColor3f(9.5f, 0.2f, 0.5f);
   v3f( 100.0, 100.0, 1.0 );   v3f( 1.0, -100.0, 1.0 );
   v3f( 100000.0, -350.0, -300.0 ); v3f( 110.0, 300.0, 120.0 );

   glEnd();

	glColor3f(1.5f, 0.8f, 0.2f);
	glBegin(GL_LINE_STRIP);
	     glVertex3f(100.0f, 0.0f, 0.0f);  // V0
	     glVertex3f(200.0f,      100.0f, 0.0f);  // V1
	     glVertex3f(250.0f,      100.0f, 3200.0f);  // V2

      	     glVertex3f(550.0f, 0.0f, 0.0f);  // V0
	     glVertex3f(400.0f,      100.0f, 0.0f);  // V1
	     glVertex3f(250.0f,      100.0f, 3200.0f);  // V2
        glEnd();

	glColor3f(9.0f, 15.0f, 5.0f);
        

	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);   
	      glColor3f(50.0f, 0.0f, 0.0f);  // activamos el color rojo
	      glVertex3f(-100.0f, 0.0f, 0.0f);
	      glColor3f(5.0f,1.0f, 0.0f);  // activamos el color verde
	      glVertex3f(120.0f, 50.0f, 0.0f);
	      glColor3f(3.0f, 0.0f, 1.0f);  // activamos el color azul
	      glVertex3f(300.0f, 219.0f, 0.0f);
	glEnd();
	
   
  	GLfloat angulo;

	int i=0; 

	/*Lineas formando una Nave*/
	glColor3f(0.5f, 0.8f, 0.2f);
	glBegin(GL_LINES);
	for (i=0; i<360; i+=3)
	{
	      angulo = (GLfloat)i*15.14159f/180.0f; // grados a radianes
	      glVertex3f(1000.0f, 700.0f, 100.0f);
	      glVertex3f(cos(angulo)*100, sin(angulo)*10, -45.0f);
	      /*circulo completo*/
	      angulo = (GLfloat)i*81.14159f/180.0f; // grados a radianes
	      glVertex3f(1000.0f, 700.0f, 100.0f);
	      glVertex3f(cos(angulo)*100, sin(angulo)*100, -45.0f);
	}
	glEnd();
	 
	glColor3f(0.1f, 0.1f, 0.3f);  

    glBegin(GL_TRIANGLES);
      glVertex3f(-10,-1,0);
      glVertex3f(150,-1,0);
      glVertex3f(200,100,0);
    glEnd();
    //glFlush();


	/* Swap front and back buffers */
	glfwSwapBuffers(_window);
}

void GameWindow::update()
{
}
