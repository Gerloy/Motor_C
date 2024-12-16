#pragma once

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "SDL_error.h"
#include <stdio.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_opengl.h>
#include "winsdl.h"

typedef struct Engine{
	Ventana	 ventana;
} Engine;

int Engine_init(Engine *_eng, int _w, int _h);
