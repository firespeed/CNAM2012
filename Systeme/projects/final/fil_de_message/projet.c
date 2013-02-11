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
  
int main(){
  
	if ((msgid = msgget(cle,IPC_CREAT  | IPC_EXCL | 0600)) == -1) 
		erreur("Pb msgget 1");

	printf("Creation de la file de message %d\n",msgid);

//création du processus mobile
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : mobile */

		if (execlp("xterm","xterm","-e","./mobile",NULL)==-1)
		erreur("execlp - mobile");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation mobile\n");
		}
	}

//creation du processus central
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : central */

		if (execlp("xterm","xterm","-e","./central",NULL)==-1)
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
			// fils : vehicule 

		

		if (execlp("xterm","xterm","-e","./vehicule",NULL)==-1)
		erreur("execlp - vehicule");
		exit(1);
		}

		default :
			// pere 
		{
		printf("Creation vehicule\n");
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
               
               
