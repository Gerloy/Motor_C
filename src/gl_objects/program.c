#include "gl_objects/program.h"
#include "gl_objects/shader.h"
#include "utils/strings.h"
#include <string.h>

void Program_Init(Program *program, const char *path){
	//Carga en memoria el codigo de los 2 shaders que va a llevar el programa
	FILE *file;
	file = fopen(path,"r");
	
	//shaders source
	char *vertex;
	char *fragment;
	enum ShaderType type = -1;

	char line[256];
	if (file != NULL){
		while (fgets(line,sizeof(line),file)){
			if(containsString("#shader",line)){
				if(containsString("vertex",line)){
					type = VERTEX;
				}else if(containsString("fragment",line)){
					type = FRAGMENT;
				}
			}
			if(type == VERTEX){
				strcat(line, vertex);
			}else if(type == FRAGMENT){
				strcat(line, fragment);
			}else if(type == NONE){
				printf("Escribi bien los shaders tonto");
				break;
			}
		}
		fclose(file);
	}else{
		printf("No se pudo encontrar el archivo");
	}

	//Linkea los shaders para crear el program y despues los borra
	unsigned int vshader = Create_Shader(vertex, VERTEX);
	unsigned int fshader = Create_Shader(fragment, FRAGMENT);

	glAttachShader(program->id, vshader);
	glAttachShader(program->id, fshader);
	glLinkProgram(program->id);
	glValidateProgram(program->id);

	glDeleteShader(vshader);
	glDeleteShader(fshader);
}

void Progrm_Delete(Program *program){
	glDeleteProgram(program->id);
}
