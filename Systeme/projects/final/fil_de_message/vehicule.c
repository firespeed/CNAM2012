#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define cle 318

int msgid, tailleMsg;

typedef struct {
        long  type;
	char num[20];
	int numDesti;
	int nbV;
        } tMessage;

void erreur(const char* msg) {perror(msg);exit(1);}

int main(int argc,char* argv[])
{
	int  msgid, tailleMsg;;
	tMessage req, rep;	

	char carte[20];
;
  
  tailleMsg = sizeof(tMessage) - sizeof(long);
 
  if (argc-1 != 0) {
       fprintf(stderr,"Appel %s <desc MSG>",argv[0]);
       exit(1);
       };

  if ((msgid = msgget(cle, 0)) == -1) 
     erreur("Pb msgget dans vehicule");

	while(1){
/* reception message rep */
		msgrcv(msgid, &rep, tailleMsg, 2, 0); //reception compteur
		
		/* ... */
        printf("Nombre de vehicules : %d\n",rep.num);	
        fflush(stdout);

		printf("Inserez votre vehicule : \n");
		scanf("%s",carte);
		sleep(3);
		
		/* construction message req */
		req.type = 1;
		strcpy(req.num, carte);
		req.numDesti=2;
                printf("*** Message built.\n");
                sleep(3);
		/* ... */

		/* envoi message req */
		msgsnd(msgid, &req, tailleMsg, 0);
		printf("*** Message sent.\n");
                sleep(3);
                /* ... */
		  
	
	
  
	}

  exit(0);
  }
