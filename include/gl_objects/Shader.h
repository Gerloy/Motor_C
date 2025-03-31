#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <stdio.h>

enum ShaderType {
	NONE = -1,
	VERTEX = 0,
	FRAGMENT= 1
};

//typedef struct Shader {
//	unsigned int id;
//	GLenum type;
//} Shader;

unsigned int Create_Shader (const char *source, const unsigned int type);

//GLenum getID(Shader *shader){
//	return shader->id;
//}
