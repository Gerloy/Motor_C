#include "gl_objects/Texture.h"

void Texture_Init(Texture * texture, const char * path){

	//Cargamos la imagen con stb_image
	int width;
	int height;
	int bpp;
	unsigned char *image;
	stbi_set_flip_vertically_on_load(0);
	image = stbi_load(path, &width, &height, &bpp, 4);
	
	//Creamos el puntero de la textura para manejarla con OpenGL
	unsigned int *p_texture;
	glGenTextures(1, p_texture);
	glBindTexture(GL_TEXTURE_2D, *p_texture);

	//Si tiene 3 canales de color se carga como RGB, si tiene 4 se carga como RGBA
	if(bpp == 4){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	}else if(bpp == 3){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	}

	//Desligamos todo porque terminamos
	glBindTexture(GL_TEXTURE_2D,0);	
	stbi_image_free(image);

	//Pasamos los valores a la struct de Textura que se pasa como referencia
	texture->width = width;
	texture->height = height;
	texture->texture = p_texture;
}
