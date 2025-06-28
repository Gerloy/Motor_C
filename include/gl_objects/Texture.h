#pragma once

#include <SDL2/SDL_image.h>
#include "extern/stb_image.h"
#include <GL/gl.h>

struct Texture{
	int width, height, bpp;
	unsigned int *texture;
} typedef Texture;

void Texture_Init(Texture * texture, const char * path);
