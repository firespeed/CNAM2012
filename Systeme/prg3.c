/*-----------------------------------------------------------
         Duplication de l'espace d'adressage
-------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

void erreurSystemeFin(const char* msg,int valeur_retour)
  {
  perror(msg);
  exit(valeur_retour);
  }

void erreurFin(const char* format,const char* msg)
  {
  fprintf(stderr,format,msg);
  exit(1);
  }

int n = 10;
 
main(int argc,char* argv[],char* arge[])
  {
  n++;
  
  switch (fork()) {
     case (pid_t) -1 : erreurSystemeFin("",1); /* break inutile */
     case (pid_t)  0 :   
        sleep(2);       /* pour que l'ordonanceur elise le pere */
        printf("FILS n : adresse = %p  valeur = %d\n",&n,n);
        exit(0);                    
     default:           /* processus pere */
        n++;
        printf("PERE n : adresse = %p  valeur = %d\n",&n,n);
	wait(NULL);
	exit(0);
     }
  }
   
        
