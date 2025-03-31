#pragma once 

#include <stdint.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "SDL_error.h"
#include <stdio.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_opengl.h>

typedef struct Ventana{
	SDL_Window *ventana;
	SDL_Renderer *renderer;
	unsigned int width;
	unsigned int height;
	
} Ventana;

extern int ventana_init(Ventana *vent, unsigned int width, unsigned int height);
