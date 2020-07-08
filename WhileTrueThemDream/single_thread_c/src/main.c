#include <stdio.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

void *thread_routine(void *arg)
{
	int nr_lines = *((int*)arg);
	int i ;
	int fd;
	char buf[]={"New line\n"};

	printf("el hilo comienza a ejecutarse ..\n");

	for(i=0 ; i < nr_lines ; i++)
	{
		fd = open("../folder/file.txt",O_WRONLY | O_APPEND);
		write(fd,buf,sizeof(buf)-1);
		close(fd);
	}
}

int main(int argc,char *argv[])
{
//	pthread_t thread1;
	int value =0;
	
	if(argc>1)
	{
        	value =atoi(argv[1]);
	}
else{
	printf("falta argumento \n");
	return -1;
}

        pthread_t thread1;

	if(0 != pthread_create( &thread1 , NULL , thread_routine , &value))
	{
		return 1;
	}
	pthread_join(thread1,NULL);


return 0;
}
