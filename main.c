// Ripped out of https://github.com/cemegginson/SDL2-Demo
// gcc -D_REENTRANT -I/usr/include/SDL2 main.c -lSDL2 -lGLESv2 -o main
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Error during SDL_Init: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("OpenGL Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
	if(window == NULL) {
		fprintf(stderr, "Error while creating window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_GLContext context = SDL_GL_CreateContext(window);
	if(context == NULL) {
		fprintf(stderr, "GL context invaild: %s\n", SDL_GetError());
		return 1;
	}
	printf("Version %s\n", glGetString(GL_VERSION));

	glClearColor ( 0.0, 1.0, 0.0, 1.0 );
	glClear ( GL_COLOR_BUFFER_BIT );
	SDL_GL_SwapWindow(window);
	SDL_Delay(2000);

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
