#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define LGMAX 100

int main(int argc,char* argv[])
{
	int descr1 = atoi(argv[1]);
	char tampon[LGMAX];
	char temp[LGMAX];
	char entre;
	int size;

	int nbVehicule = 0;
	

	printf("LCD :\n");


	while(1){
	
		printf("En attente ...\n");
		sleep(5);
		read(descr1,tampon,LGMAX)>0;
	
		entre = tampon[strlen(tampon)-1];
		size = strlen(tampon)-1;


		if(entre=='0'){
			nbVehicule++;
			printf("Véhicule %s entré\n",tampon);
		}
		if(entre=='1'){
			nbVehicule--;
			printf("Véhicule %s sorti\n",tampon);
		}


		printf(" NB de Vehicules : %d \n", nbVehicule);
		fflush(stdout);
	       
	}    
 exit(0);    
}
