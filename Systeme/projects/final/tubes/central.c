#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define LGMAX 100

int main(int argc,char* argv[])
{
	int descr1 = atoi(argv[1]);
	int descw1 = atoi(argv[2]);
	
	char tampon[LGMAX];
	
	char message[LGMAX];
	char response[50];
	
	char entre;

	printf("central :\n");


while(1){
	

	read(descr1,message,LGMAX)>0;
	
	printf("%s",message);
	
	printf("Traitement ...\n");
	sleep(2);
if(strncmp(message,"vehicule",8)==0){
		//~ traitement mobile

		write(descw1,message,sizeof(message));
		printf(" envoie msg en mobile! \n");
	}
	if(strncmp(message,"mobile",6)==0){
		//~ traitement vehicule

		write(descw1,message,sizeof(message));
		printf(" envoie msg en vehicule! \n");
	}


	
	fflush(stdout);
       
}    
 exit(0);    
}
