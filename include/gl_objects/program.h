#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "utils/strings.h"
#include "gl_objects/shader.h"

typedef struct Program{
	GLuint id;
}Program;

//Crea un nuevo programa asignandole el shader
void Program_Init(Program *program, const char *path);

//Borra el program de la memoria
void Program_Delete(Program *program);
