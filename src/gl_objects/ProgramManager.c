#include "gl_objects/ProgramManager.h"
#include "gl_objects/Program.h"

//Tamano base del array es de 5
void ProgramManager_Init(ProgramManager *manager){
	manager->node = malloc(sizeof(ProgramNode) * 5);
	manager->count = 0;
}


void ProgramManager_AddProgramFromFile(ProgramManager *manager, const char *path){
	if (sizeof(*manager->node) >= sizeof(ProgramNode) * manager->count){
		manager->node = realloc(manager->node, sizeof(ProgramNode) * (manager->count+5));
	}	
	
	manager->count ++;
	Program_Init(manager->node[manager->count].program, path);
}

Program *ProgramManager_GetProgramFromID(ProgramManager *manager, int id){
	return manager->node[id].program;
}

Program *ProgramManager_GetProgramFromName(ProgramManager *manager, char _name[32]){
	int i;
	//Se supone que la division va a devolver un entero si o si
	for (i=0; i<(sizeof(*manager->node) / sizeof(manager->node[0])); i++){
		if (manager->node[i].name == _name){
			return manager->node[i].program;
		} 
	}
	printf("No se encontro el program");
	return NULL;
}

void ProgramManager_Clean(ProgramManager *manager){
	int i;
	for (i=sizeof(*manager->node) / sizeof(manager->node[0]);i>=0;i--){
		if(i<=manager->count){
			manager->node[i].name[0] = '\0';
			Program_Delete(manager->node[i].program);
		}
		free(&manager->node[i]);
	}

}
