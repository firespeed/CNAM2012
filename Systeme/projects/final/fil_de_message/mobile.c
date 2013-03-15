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

	char carte[20]={'\0'};
;
  
  tailleMsg = sizeof(tMessage) - sizeof(long);
 
  if (argc-1 != 0) {
       fprintf(stderr,"Appel %s <desc MSG>",argv[0]);
       exit(1);
       };

  if ((msgid = msgget(cle, 0)) == -1) // creation de l'identifiant
     erreur("Pb msgget dans mobile");
     
	while(1){
                
		printf("Où voulez vous aller : \n");
		scanf("%s",carte);
                sleep(1);
		
		/* construction message req */
		req.type = 1;//id mobile 1
		strcpy(req.num, carte);
		char carte[20]={'\0'};
		req.numDesti=1;
                printf("*** Message built.\n");
                sleep(3);
		/* ... */

		/* envoi message req */
		msgsnd(msgid, &req, tailleMsg, 0);
                printf("*** Message sent.\n");
                sleep(3);
		/* ... */
		
		/* reponse message rep */
		msgrcv(msgid, &rep, tailleMsg, 3, 0);
		if (rep.numDesti==1) printf("\nVehicule vient vous chercher !\n");
                printf("*** ACK received from central.\n");
                sleep(10);
                system("clear");
                
		/* ... */
  
	}

  exit(0);
  }
