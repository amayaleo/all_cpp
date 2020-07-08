/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//	Aplicacion FIFO o pipe
//	programa para comunicarse atraves de pipe 
//	Crear un folder de nombre "../tmp/" , donde se va a crear un "FILE" temporal para que las aplicaciones se comuniquen
//	compilar por separado 
//
//	gcc write_fifo.c -o write
//
//	#ejecutar las dos aplicaciones , read no va a terminar haste que write escriba y viceversa. 
//
//	./write
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



int main(int argc,char *argv[])
{
	int fd;
	char buf[]={"Mensaje guardado en para leet por fifo . Desde read\n"};
	mkfifo ("../tmp/me_fifo",0666);
	fd=open("../tmp/me_fifo",O_WRONLY);
	write(fd,buf,sizeof(buf));
	close(fd);
return 0;
}
