#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

typedef struct VertexBuffer{
	unsigned int rendererID;
} VertexBuffer;

void VertexBuffer_init(VertexBuffer *vbuffer, const unsigned int *_data, const unsigned int size);

void VertexBuffer_bind(VertexBuffer *vbuffer);
void VertexBuffer_unbind(VertexBuffer *vbuffer);

void VertexBuffer_delete(VertexBuffer *vbuffer);
