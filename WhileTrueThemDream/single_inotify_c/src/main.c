#include <stdio.h>
#include <sys/inotify.h>
#include <unistd.h>

int main(){


char buffer[200];
int fd=inotify_init(); //file descriptor
//int wd= inotify_add_watch(fd,"/media/leo/FILES/development/source/sourceCpp2020/AprenderSrcCpp/WhileTrueThemDream/single_open_read_close/bin/folder",IN_CLOSE_WRITE);
int wd= inotify_add_watch(fd,"./folder",IN_CLOSE_WRITE);


while(1){
		read(fd,buffer,200);
		printf("archivo es escrito y cerrado : %s \n",((struct inotify_event*)buffer)->name);
	}



return 0;
}
