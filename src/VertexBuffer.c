#include "VertexBuffer.h"

void VertexBuffer_init(VertexBuffer *vbuffer,const unsigned int *_data, unsigned int size){
	glGenBuffers(1, &vbuffer->rendererID);
	glBindBuffer(GL_ARRAY_BUFFER, vbuffer->rendererID);
	glBufferData(GL_ARRAY_BUFFER, size, _data, GL_STATIC_DRAW);
}

void IndexBuffer_bind(VertexBuffer *vbuffer){glBindBuffer(GL_ARRAY_BUFFER, vbuffer->rendererID);}
void IndexBuffer_unbind(){glBindBuffer(GL_ARRAY_BUFFER, 0);}

void IndexBuffer_delete(VertexBuffer *vbuffer){glDeleteBuffers(1, &vbuffer->rendererID);}
