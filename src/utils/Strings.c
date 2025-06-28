#include "utils/Strings.h"
#include <stdlib.h>

//Checkea la string where y se fija si la string find esta incluida en esta
//Devuelve 1 si encuente, 0 si no encuentra, o -1 si alguna de las strings no existe
int containsString(const char *find, const char *where){
	if ((find != NULL) && (where != NULL)){
		const size_t find_len = strlen(find);
		const size_t where_len = strlen(where);

		size_t equals = 0; 

		for (size_t w=0, f=0; w<where_len; w++){
			do{
				if(find[f] == where[w]){
					if(++equals == find_len){return 1;}
					w++; f++;
				}else{w-=equals; f=0; equals=0;}
			}while(equals);
		}
		return 0;

	}else{
		printf("Manda bien las cosas pelotudo");
		return -1;
	} 
}

//void initString(char *str){str=malloc(1);}

//char *addToString(const char *original, const char *to_add){
//	size_t add_len = strlen(to_add);
//	if (original == NULL) initString(original);
//	original = realloc(original, strlen(original) + strlen(to_add));
//	for (size_t)		
//}
