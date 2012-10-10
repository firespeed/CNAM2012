/*-----------------------------------------------------------
               Les tubes ordinaires
               le pere lit, le fils ecrit
-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define cle 314

void erreur(const char* msg)      {perror(msg);exit(1);}

int msgid, tailleMsg;
  
main(){
  
	if ((msgid = msgget(cle,IPC_CREAT  | IPC_EXCL | 0600)) == -1) 
		erreur("Pb msgget 1");

	printf("Creation de la file de message %d\n",msgid);

//création du processus badge1
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : badge1 */

		if (execlp("xterm","xterm","-e","./BADGE1",NULL)==-1)
		erreur("execlp - Badge1");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Badge 1\n");
		}
	}

//creation du processus compteur
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : compteur */

		if (execlp("xterm","xterm","-e","./COMPTEUR",NULL)==-1)
		erreur("execlp - Compteur");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Compteur\n");
		}
	}
	

//création du processus badge2
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			// fils : badge2 

		//Fermeture des descripteurs de tubes inutiles pour badge1; 

		if (execlp("xterm","xterm","-e","./BADGE2",NULL)==-1)
		erreur("execlp - Badge2");
		exit(1);
		}

		default :
			// pere 
		{
		printf("Creation Badge 2\n");
		}
	}

//création du processus LCD
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			// fils : lcd 

		if (execlp("xterm","xterm","-e","./LCD",NULL)==-1)
		erreur("execlp - Compteur");
		exit(1);
		}

		default :
			// pere 
		{
		printf("Creation LCD\n");
		}
	}

/* destruction de la file */

	wait(NULL);
	if (msgctl(msgid, IPC_RMID, 0) == -1)
		erreur("Erreur destruction de la file");
	else
		printf("destruction de la file <3\n");
  /* ... */

  }
               
               
