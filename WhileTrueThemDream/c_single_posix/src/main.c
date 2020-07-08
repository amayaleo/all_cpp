/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//	autor : 
//						Amaya Leo
//	Compilardor:
//						gcc
//
//	Tipo de aplicacion:
//						Semaforos Posix
//	Caracteristicas:
//
//	Makefile:
//
//						gcc main.c -o app		
//	
//	./app
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define NR_LOOP 10000

// Prueba de compentar y descomentar Semaphore y verificar que el semaforo restinge el orden del contador
#define SEMAPHORE


static int counter = 0;
#ifdef SEMAPHORE
	sem_t sem1;
#endif

static void * thread_1_function(void* arg);
static void * thread_2_function(void* arg);

int main(int argc,char *argv[])
{

	pthread_t thread_1,thread_2;
	#ifdef SEMAPHORE
	sem_init(&sem1,0,1);
	#endif
	pthread_create(&thread_1,NULL,*thread_1_function,NULL);
	pthread_create(&thread_2,NULL,*thread_2_function,NULL);

	pthread_join(thread_2,NULL);
	pthread_join(thread_1,NULL);

	printf("Value counter : %d \n", counter);
return 0;
}



static void * thread_1_function(void* arg)
{


	for(int i=0; i < NR_LOOP ; i++)
	{
#ifdef SEMAPHORE
		sem_wait(&sem1);
#endif
		
		counter +=1;
#ifdef SEMAPHORE
		sem_post(&sem1);
#endif
	}
}


static void * thread_2_function(void* arg)
{

	for(int i=0; i < NR_LOOP ; i++)
	{
		#ifdef SEMAPHORE
		sem_wait(&sem1);
		#endif

		counter -=1;
		#ifdef SEMAPHORE
		sem_post(&sem1);
		#endif
	}
}
