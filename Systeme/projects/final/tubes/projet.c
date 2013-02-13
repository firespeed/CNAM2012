/*-----------------------------------------------------------
               Les tubes ordinaires
               le pere lit, le fils ecrit
-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void erreur(const char* msg)      {perror(msg);exit(1);}

#define LGMAX 100
  
int main(){
	  int des_mob[2];
	  int des_mob_read[2];

	 
 
  
	if (pipe(des_mob) == -1) erreur("pipe");
	if (pipe(des_mob_read) == -1) erreur("pipe");



	
  

  //création du processus mobile
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : mobile */
		char desc1[4]; char desc2[4];

		//Fermeture des descripteurs de tubes inutiles pour mobile
		close(des_mob[0]); close(des_mob_read[1]) ;

		sprintf(desc1,"%d",des_mob[1]); /* communique num des_mob[1] ecrire */
		sprintf(desc2,"%d",des_mob_read[0]); /* communique num des_mob_read[0] lire */

		if (execlp("xterm","xterm","-e","./mobile",desc1, desc2,NULL)==-1)
		erreur("execlp - mobile");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation mobile \n");
		}
	}
	
	

//creation du processus central
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : central */
		char desc1[4]; char desc2[4]; 

		//Fermeture des descripteurs de tubes inutiles pour central
		close(des_mob[1]); close(des_mob_read[0]); 

		sprintf(desc1,"%d",des_mob[0]); /* communique num des_mob[1] lire */
		sprintf(desc2,"%d",des_mob_read[1]); /* communique num des_mob_read[1] ecrire */
	

		if (execlp("xterm","xterm","-e","./central",desc1,desc2,NULL)==-1)
		erreur("execlp - central");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation central\n");
		}
	}
	

//création du processus vehicule
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : vehicule */
		char desc1[4]; char desc2[4];

		//Fermeture des descripteurs de tubes inutiles pour vehicule
		close(des_mob[0]); close(des_mob_read[1]); 

		sprintf(desc1,"%d",des_mob[1]); /* communique num des_mob[1] ecrire */
		sprintf(desc2,"%d",des_mob_read[0]); /* communique num des_mob_read[0] lire */

		if (execlp("xterm","xterm","-e","./vehicule",desc1, desc2,NULL)==-1)
		erreur("execlp - vehicule");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation vehicule \n");
		}
	}

  }
               
               
