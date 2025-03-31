#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "gl_objects/Program.h"
#include <stdio.h>
#include "utils/Strings.h"
#include "gl_objects/Shader.h"

typedef struct ProgramNode{
	Program *program;
	char name[32];
} ProgramNode;

//typedef struct ProgramNodeList{
//	ProgramNode node;
//struct	ProgramNodeList* next;
//struct	ProgramNodeList* prev;
//} ProgramNodeList;

typedef struct ProgramManager{
	ProgramNode *node;	
	int count;
} ProgramManager;

/*Esto queda para cuando necesite tener los dos tipos de Program Managers*/

//union ProgramManager{
///	struct ProgramManagerArray{
//		ProgramNode *node;
//	}ProgramManagerArray;
//
//	struct ProgramManagerList{
//		ProgramNode node;
//		struct ProgramManagerList *next;
//		struct ProgramManagerList *prev;
//	}ProgramManagerList;
//} ProgramManager;

void ProgramManager_Init(ProgramManager *manager);
void ProgramManager_AddProgramFromFile(ProgramManager *manager, const char *path);
Program *ProgramManager_GetProgramFromID(ProgramManager *manager, int _id);
Program *ProgramManager_GetProgramFromName(ProgramManager *manager, char _name[32]);
void ProgramManager_Clean(ProgramManager *manager);
//Esto solo puede ser usado si se implementa con linked list
//void ProgramManager_RemoveProgram(ProgramManager *manager, size_t _id);
