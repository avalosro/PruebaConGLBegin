#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <GLFW/glfw3.h>

class GameWindow
{
	private:
		bool _running;
		GLFWwindow* _window;

		/* Frame buffer size */
		GLsizei _width;
		GLsizei _height;

	public:
		void setRunning(bool newRunning);
		bool getRunning();

		GameWindow(bool running, GLFWwindow* window);

		void render();
		void update();
};

#endif
