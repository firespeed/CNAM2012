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
	
	char entre;
	char response[50];
	
	

	printf("central :\n");


while(1){
	

	read(descr1,tampon,LGMAX)>0;
	
	entre = tampon[strlen(tampon)-1];
	
	printf("Traitement ...\n");
	sleep(2);
	if(entre=='0'){
		//~ tratement mobile 
	strcpy(response,"vehicule_0");
	
	 write(descw1,response,strlen(response)+1);
	 printf("ok");
	}
	if(entre=='1'){
		//~ traitement vehicule 
	}


	printf(" envoie msg en vehicule! \n");
	fflush(stdout);
       
}    
 exit(0);    
}
