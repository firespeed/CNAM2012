/*-----------------------------------------------------------
                 Gestion du Ctrl-C, Ctrl-Z
-------------------------------------------------------------*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void erreur(char* msg)
  {
  fprintf(stderr,"%s\n",msg);
  exit(1);
  }

void traitantSIGINT(int num)
  {
  if (num!=SIGINT) erreur("y-a un lezard...");
  printf("\n---- Ctrl-C interdit -----\n");
  }
  
  
main(int argc,char* argv[])
  {
  int s,i;
  struct sigaction action;
  
  if (argc-1 != 1) {
     fprintf(stderr,"Appel : %s <nb de secondes>\n",argv[0]);
     exit(1);
     }
  s=atoi(argv[1]);

  /* ---------------installation des traitants de signaux */

  /* Avec sigaction :
                    sigemptyset(&action.sa_mask);
                    action.sa_handler=traitantSIGINT;
                    sigaction(SIGINT,&action,NULL);
     Avec signal
  */
  signal(SIGINT,traitantSIGINT);
  
  /* --------------le programme fait son boulot  -> il dort ... */

  for (i=1;i<=s;i++) {
    sleep(1);
    printf("\r %d secondes ecoules...",i);
    fflush(stdout);               /* force affichage */
    }
  printf("\n");
  }
  
