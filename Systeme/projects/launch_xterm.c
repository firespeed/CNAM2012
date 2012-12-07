/*-----------------------------------------------------------
    recouvrement de processus et attente de terminaison du fils
-------------------------------------------------------------*/

#include <unistd.h>
#include <stdio.h>

main(int argc,char* argv[],char* arge[])
  {
  switch (fork()) {
     case (pid_t) -1 :  perror(""),exit(1);// break inutile
     case (pid_t)  0 :   /* on est dans le processus fils */
        execlp("xterm","xterm", "-e","mobile",NULL);
        /* ne revient jamais ici, saut sur échec de exec */
        exit(2);
     default:
                        /* on est dans le processus pere */
        wait(NULL);
        printf("je suis le pere et je me termine \n");
     }
     exit(0);
  }
