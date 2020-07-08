#include "drive.h"
#include "bmp.h"




//unsigned char bmp[];


void funcion(void){
char *pointer;
pointer=(char *)&bmp;
INFO my_info ;

	/*
	my_info.alto=(int)((*pointer) <<7 | *pointer++);
	my_info.ancho=(int)((*pointer++) <<7 | *pointer++);
	my_info.bits=(int)((*pointer++) <<7 | *pointer++);
	my_info.size=(int)((*pointer++) <<7 | *pointer++);
	*/

	my_info.alto=1;
	my_info.ancho=2;
	my_info.n_bits=3;
	my_info.size=4;

	printf("alto:%d",my_info.alto);
	printf("ancho:%d",my_info.ancho);
	printf("bits:%d",my_info.n_bits);
	printf("size:%d",my_info.size);
}
