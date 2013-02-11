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
	int descw2 = atoi(argv[3]);
	char tampon[LGMAX];
	
	char entre;

	int nbVehicule = 0;
	

	printf("COMPTEUR :\n");


while(1){
	

	read(descr1,tampon,LGMAX)>0;
	
	entre = tampon[strlen(tampon)-1];
	
	printf("Traitement ...\n");
	sleep(2);
	if(entre=='0'){
		nbVehicule++;
	
	}
	if(entre=='1'){
		nbVehicule--;
	}
	write(descw2,tampon,strlen(tampon)+1);

	printf(" NB de Vehicules : %d \n", nbVehicule);
	fflush(stdout);
       
}    
 exit(0);    
}
