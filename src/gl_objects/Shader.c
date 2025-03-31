#include "gl_objects/Shader.h"

unsigned int Create_Shader(const char *source, unsigned int type){
	
	unsigned int id = glCreateShader(type);
	
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);

	int result; 
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE){
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char *message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		printf("Fallo la compilacion del "); printf(type == GL_VERTEX_SHADER ? "vertex" : "fragment"); printf("shader!"); printf("\n");

		printf("%s",message);
		glDeleteShader(id);
		return 0;
	}

	return id;
}
