/*-----------------------------------------------------------
-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define LGMSG 20

main(int argc,char* argv[])
  {
  char msg[LGMSG];
  int  E,S;
  if (argc-1 != 2) {
       fprintf(stderr,"Appel %s <desc E> <desc S>",argv[0]);
       exit(1);
       };
  E=atoi(argv[1]);
  S=atoi(argv[2]); 
  while (1) {
    int lg,i;
    read(E,msg,LGMSG);
    lg = strlen(msg);
    for (i=0;i<lg;i++) msg[i]=toupper(msg[i]);
    sleep(3);
    write(S,msg,LGMSG);
    }
  }
     
               
