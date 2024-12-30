#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

typedef struct IndexBuffer{
	unsigned int rendererID;
	unsigned int count;
} IndexBuffer;

void IndexBuffer_init(IndexBuffer *ibuffer,const unsigned int *data, unsigned int count);

void IndexBuffer_bind(IndexBuffer *ibuffer);
void IndexBuffer_unbind();

void IndexBuffer_delete(IndexBuffer *ibuffer);
