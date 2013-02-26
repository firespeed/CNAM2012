/* p2.c : processus utilisateur de la file de message
          créée par p1.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define cle 314

void erreur(const char* msg) {perror(msg);exit(1);}

/* structure du message */
typedef struct {
        long  type;
        pid_t numPID;
        } tMessage;


main(int argc,char* argv[])
  {
  int  msgid, tailleMsg;
  tMessage req, rep;
  
  tailleMsg = sizeof(tMessage) - sizeof(long);
 
  if (argc-1 != 0) {
       fprintf(stderr,"Appel %s <desc MSG>",argv[0]);
       exit(1);
       };

  if ((msgid = msgget(cle, 0)) == -1) 
     erreur("Pb msgget dans P2");
     
  /* construction message req */
  /* ... */
  
  /* envoi message req */
  /* ... */
  
  /* reponse message rep */
  /* ... */

  printf("P2 : mon pid %d, son pid %d \n", getpid(), rep.numPID);
  exit(0);
  }
     
