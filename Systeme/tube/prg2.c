/*-----------------------------------------------------------
               Les tubes (sans nom)
               le pere ecrit, le fils lit

               => A COMMENTER
-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>


void erreur(const char* msg)      {perror(msg);exit(1);}

  
void traitantAbsenceLecteur (int num)
  {
  printf("passage par traitantAbsenceLecteur\n");
  exit(1);
  }

#define TailleTubeMax PIPE_BUF-1 /*5120 max # bytes atomic in write to a pipe */

main()
  {
  int pfd[2];
  char tampon[TailleTubeMax+1];

  if (pipe(pfd) == -1) erreur("pipe");
  
  switch (fork()) {
     case -1 : erreur("fork");
     case 0  :                     /* fils lecteur */                     
        close(pfd[1]);
        printf("fils : attente RC clavier");
        getchar();                             /* ? */
        read(pfd[0],tampon,1);                 /* ? */
        sleep(1);                  /* assure 1 lecteur pour le 1er write */
        break;
     default :                     /* pere ecrivain */
        signal(SIGPIPE,traitantAbsenceLecteur);
        close(pfd[0]);
        write(pfd[1],tampon,TailleTubeMax+1);  /* ? */
        printf("pere : %d car. ecrits dans tube\n",TailleTubeMax+1);
        wait(NULL);                            /* ? */
        write(pfd[1],"A",1);                   /* ? */
        break;
      }
  }
               
               
