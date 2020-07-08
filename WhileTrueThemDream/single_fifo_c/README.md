#aplicacion FIFO o 
#programa para comunicarse atraves de pipe 
#crear un folder de nombre "../tmp/" , donde se va a crear un "FILE" temporal para que las aplicaciones se comuniquen


#compilar por separado 

gcc src/write_fifo.c -o write
gcc src/read_fifo.c -o read

#ejecutar las dos aplicaciones , read no va a terminar haste que write escriba y viceversa. 
#ex
./write
./read 
