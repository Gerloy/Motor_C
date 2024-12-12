#include "winsdl.h"

int ventana_init(Ventana *_vent, uint _width, uint _height){

	_vent->width = _width;
	_vent->height = _height;
	_vent->ventana = SDL_CreateWindow("Motorcito",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL); 

	if(!_vent->ventana){
		printf("Error creando la ventana:\n");
		printf(SDL_GetError());
		return -1;
	}


	if(!SDL_GL_CreateContext(_vent->ventana)){
		printf("Error creando el contexto de OpenGL\n");
		printf(SDL_GetError());
	
	}

	_vent->renderer = SDL_CreateRenderer(_vent->ventana, 0, SDL_RENDERER_ACCELERATED);

	if (!_vent->renderer){
		printf("Error creando el rendere\n");
		printf(SDL_GetError());
		return -1;
	}

	//Cosas de OpenGL
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	SDL_GL_SetSwapInterval(1);

	glViewport(0,0,_vent->width,_vent->height);

	
	return 0;
}

void Ventana_render(Ventana *vent){
	SDL_GL_SwapWindow(vent->ventana);
}
