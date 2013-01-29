
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

void aller_retour();
void trajet_simple(char* point_A, char* point_B);

int main(int argc,char* argv[]){
	int entreeTube;

char nomTube[]="mobile_1.fifo";
	//ouverture en lecture et en ecriture
	if((entreeTube = open(nomTube, O_WRONLY)) == -1) 
	{
		fprintf(stderr, "Impossible d'ouvrir l'entrée du tube nommé.\n");
		exit(EXIT_FAILURE);
	}

	
	char tampon[100];
	char data[100];
  
	while(1){
       
       	printf("Que voulez vous faire?\n");
		scanf("%s", data);
        strcpy(tampon,data);

		write(entreeTube, tampon, strlen(tampon)+1);
               
           sleep(1);
     }
  
}

void aller_retour(char* point_A, char* point_B){



}
void trajet_simple(char* point_A, char* point_B){



}

