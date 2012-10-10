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
  
main(){
	

  //création du processus badge1
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : badge1 */
		
		if (execlp("xterm","xterm1","-e","./BADGE1","localhost", "cnam",NULL)==-1)
		erreur("execlp - Badge1");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Badge 1\n");
		}
	}

//création du processus badge2
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : badge2 */
		

		if (execlp("xterm","xterm2","-e","./BADGE2","localhost", "cnam",NULL)==-1)
		erreur("execlp - Badge2");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Badge 2\n");
		}
	}

//creation du processus compteur
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
		

		if (execlp("xterm","xterm3","-e","./COMPTEUR",NULL)==-1)
		erreur("execlp - Compteur");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Compteur\n");
		}
	}
	



//création du processus LCD
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : lcd */

		if (execlp("xterm","xterm4","-e","./LCD",NULL)==-1)
		erreur("execlp - Compteur");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation LCD\n");
		}
	}
  }
               
               
