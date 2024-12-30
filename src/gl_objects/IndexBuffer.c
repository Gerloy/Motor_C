#include "gl_objects/IndexBuffer.h"

void IndexBuffer_init(IndexBuffer *ibuffer,const unsigned int *_data, unsigned int _count){
	ibuffer->count = _count;
	glGenBuffers(1, &ibuffer->rendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibuffer->rendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ibuffer->count * sizeof(unsigned int), _data, GL_STATIC_DRAW);
}

void IndexBuffer_bind(IndexBuffer *ibuffer){glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibuffer->rendererID);}
void IndexBuffer_unbind(){glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);}

void IndexBuffer_delete(IndexBuffer *ibuffer){glDeleteBuffers(1, &ibuffer->rendererID);}
