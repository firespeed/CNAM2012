/*-----------------------------------------------------------
    recouvrement de processus et attente de terminaison du fils
-------------------------------------------------------------*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc,char* argv[],char* arge[])
  {
  switch (fork()) {
     case (pid_t) -1 :  perror(""),exit(1);// break inutile
     case (pid_t)  0 :   
                            /* on est dans le processus fils */
        execl("./fils","fils",NULL);
	exit(1);
     default:
                            /* on est dans le processus pere */
        wait(NULL);
        printf("je suis le pere \n");
     }
  }
   
        
