/*P1.c : processus créateur*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define cle 314

int msgid;

void erreur(const char* msg) {perror(msg);exit(1);}
     
main()
{
  int pid_p2, pid_p3;
  int n, num;

  if ((msgid = msgget(cle,IPC_CREAT  | IPC_EXCL | 0600)) == -1) 
     erreur("Pb msgget 1");

  printf("Lancement de P1\n");
  printf("Creation de la file de message %d\n",msgid);

  switch (pid_p2 = fork()) {
     case -1 : erreur("fork"); break;
     case 0  : {
               char* arg[3];	/* fils  P2 */                   
               arg[0] = "P2";
               arg[1] = NULL;
               execv("P2",arg);
	       erreur("execv");
	       exit(2);
               }
     default : { 
     	       printf("Creation de P2 (pid = %d)\n", pid_p2);
	       }
  }
  switch (pid_p3 = fork()) {
     case -1 : erreur("fork"); break;
     case 0  : {
               char* arg[3];	/* fils  P3 */                   
               arg[0] = "P3";
               arg[1] = NULL;
               execv("P3",arg);
	       erreur("execv");
	       exit(3);
               }
     default : { 
     	       printf("Creation de P3 (pid = %d)\n", pid_p3);
	       }
  }

  for(n=0; n <=1; n++) {
  	num=wait(NULL);
	if (num == pid_p2) printf("P2 termine\n");
	else printf("P3 termine\n");
  }

  printf("P1 termine\n");

  /* destruction de la file */
  /* ... */

  exit(0);
}
