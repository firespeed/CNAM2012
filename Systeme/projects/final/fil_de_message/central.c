#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define cle 314

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
	int  msgid, tailleMsg;
	tMessage req, rep, rep2;	
	char carte[20];
  
  tailleMsg = sizeof(tMessage) - sizeof(long);
 
  if (argc-1 != 0) {
       fprintf(stderr,"Appel %s <desc MSG>",argv[0]);
       exit(1);
       };


  if ((msgid = msgget(cle, 0)) == -1) // creation de l'identifiant
     erreur("Pb msgget dans central");
     
	while(1){
		/* construction message req */
		req.type = 4;		
	  
		
		/* reception message rep */
		msgrcv(msgid, &rep, tailleMsg, 1, 0); //reception mobile
		
		/* ... */

		rep2.type=2;
		rep2.numDesti=rep.numDesti;

		/* traitement message */
		if (rep.numDesti==1){
                        printf("*** Message received from mobile.\n");
                        sleep(3);
		
                        printf("*** Sending ACK to mobile.\n");
                        sleep(3);
			msgsnd(msgid, &rep2, tailleMsg, 0);
			printf("Voiture %s entree.\n",rep.num);
		}
		else {
			printf("*** Message received from vehicule.\n");
		        sleep(3);

                        if (nbVehicules > 0){
                                nbVehicules--;
			        printf("Voiture %s sortie\n",rep.num);
				
			}
			if (nbVehicules == 0) {		
				printf("Aucune voiture dans le parking\n");
			}
			
                        printf("*** Sending ACK to mobile.\n");
                        sleep(3);
			msgsnd(msgid, &rep2, tailleMsg, 0);
		}

		
		
                fflush(stdout);		

	}

  exit(0);
  }

