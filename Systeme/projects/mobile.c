
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <sys/wait.h>
#include <errno.h>

void aller_retour();
void trajet_simple(char* point_A, char* point_B);

int main(int argc,char* argv[]){
 
  char tampon[100];
   char data[100];
  
 printf("tube 0 %d",atoi(argv[1]));
  printf("tube 1 %d",atoi(argv[2]));
  
 while(1){
               close(atoi(argv[1]));
               	printf("Que voulez vous faire?\n");
		scanf("%s", data);
               strcpy(tampon,data);
		//sleep(10);
               write(atoi(argv[2]),tampon,strlen(tampon)+1);
           sleep(10);
           
      
              
               
     }
  
}

void aller_retour(char* point_A, char* point_B){



}
void trajet_simple(char* point_A, char* point_B){



}

