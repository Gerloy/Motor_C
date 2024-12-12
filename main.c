#include "main.h"

int main(int argc, char *argv[]){

	_Bool abierto = 1;

	Engine motor;
	if(Engine_init(&motor,640,480) == -1){return -1;}

	while(abierto){}
	return 0;
}
