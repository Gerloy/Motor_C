#include "Engine.h"

int Engine_init(Engine *_eng, int _w, int _h){

	if (SDL_Init(SDL_INIT_VIDEO)>0){
		printf("Error al iniciar SDL_Video: \n");
		printf(SDL_GetError());
		return -1;
	}

	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0){
		printf("Error iniciando el cargador de imagenes: \n");
		printf(IMG_GetError());
		return -1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	if (ventana_init(&_eng->ventana, _w, _h) != 0){return -1;}

	return 0;
}
