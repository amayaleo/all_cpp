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
//	gcc read_fifo.c -o read
//
//	#ejecutar las dos aplicaciones , read no va a terminar haste que write escriba y viceversa. 
//
//	./read
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////




#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



int main()
{
	int fd,n;
	char buf[1024];

	fd = open("../tmp/me_fifo",O_RDONLY);

	n = read(fd,buf,sizeof(buf));

	printf("sizeof(buf) : %d \n",n);
	printf("msj : \n %s\n ",buf);

	close(fd);
return 0;
}
