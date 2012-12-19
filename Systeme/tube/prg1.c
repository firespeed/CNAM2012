/*-----------------------------------------------------------
               Les tubes ordinaires
               le pere lit, le fils ecrit
-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

void erreur(const char* msg)      {perror(msg);exit(1);}

#define LGMAX 100
  
main()
  {
  int pfd[2];
  char tampon[LGMAX];
  
  if (pipe(pfd) == -1) erreur("pipe");
  
  switch (fork()) {
         case -1 : erreur("fork");
         case 0   :                   /* fils */
               close(pfd[0]);
               strcpy(tampon,"salut a toi");
		//sleep(10);
               write(pfd[1],tampon,strlen(tampon)+1);
               exit(0);
        default  :                  /* pere */ 
               {
               char *p = tampon;                    
               close(pfd[1]);
               while (read(pfd[0],p,1) != 0) p++;
               printf("chaine lue dans le tube : %s\n",tampon);
               exit(0);
               }
     }
  }
               
               
