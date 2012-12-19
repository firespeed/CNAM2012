/*-----------------------------------------------------------
 -------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int tube1[2],tube2[2];

void erreur(const char* msg)      {perror(msg);exit(1);}

#define LGMSG 20

void lectureLigne(char* ligne, int lgmax)
  {
  int i=-1;
  
  do {
    i++;
    read(STDIN_FILENO,ligne+i,1);
    }
  while (ligne[i]!='\n' && i<lgmax);
  ligne[i]='\0';
  }

void au_boulot(int dLect,int dEcr)
  {
  char   msgEmis[LGMSG],msgRecu[LGMSG];
  fd_set ens;

  while (1) {
    printf("Entrez une ligne : \n");
    FD_ZERO(&ens);
    FD_SET(0,&ens);
    FD_SET(dLect,&ens);
    select(1+dLect,&ens,NULL,NULL,NULL);
    if (FD_ISSET(0,&ens)) {
       lectureLigne(msgEmis,LGMSG);
       printf("echo -> %s\n",msgEmis);
       write(dEcr,msgEmis,LGMSG);
       }
    else if (FD_ISSET(dLect,&ens)) {
       read(dLect,msgRecu,LGMSG);
       printf("reception tube2 -> %s\n",msgRecu);
       fflush(stdout);
       }
    }
  }
     
main()
  {

  if (pipe(tube1) == -1) erreur("pipe tube1");
  if (pipe(tube2) == -1) erreur("pipe tube2");
  
  switch (fork()) {
     case -1 : erreur("fork"); break;
     case 0  : {
               char* arg[4];          /* fils  transforme */                   
               close(tube1[1]);
               close(tube2[0]);
               arg[0] = "prog4_p2";
               arg[1] = (char*) malloc(3);sprintf(arg[1],"%d",tube1[0]);
               arg[2] = (char*) malloc(3);sprintf(arg[2],"%d",tube2[1]);
               arg[3] = NULL;
               execv("prg3Aux",arg);
               }
     default :                        /* pere gere clavier */
               close(tube1[0]);
               close(tube2[1]);
               au_boulot(tube2[0],tube1[1]);
      }
  }
               
               
