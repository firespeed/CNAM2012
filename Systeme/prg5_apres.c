/*-----------------------------------------------------------
                  recouvrement
-------------------------------------------------------------*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


/* Fonction identique a celle dans prg5_avant.c */
/* (dupliquee pour eviter compilation separee) */

void attributsProcessus(const char* quand)
  {
  printf("\n%s\n",quand);
  printf("--------------------------------\n");
  printf("Numero du processus      : %d\n",getpid());
  printf("Numero du processus pere : %d\n",getppid());
  printf("Proprietaire             : %d\n",getuid());
  }
  
main(int argc,char* argv[])
  {
  printf("\nrecuperation d'arguments argv[1] = %s\n\n",argv[1]);
  attributsProcessus("APRES recouvrement");
  printf("\nrecuperation d'arguments argv[1] = %s\n\n",argv[1]);
  }
