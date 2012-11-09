/* exercice 2 */

#include <sys/types.h>		/* definitions de types */
#include <fcntl.h>		/* definit O_RDONLY, etc. */
#include <stdlib.h>		/* prototypes des appels systeme */
#include <unistd.h>		/* prototypes des appels systeme */
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
main()
{
   int f1, f2;
   char buf1[100], buf2[100];
   
   f1 = open("./bonjour", O_RDONLY);
   f2 = dup(f1);
   
   printf("position initiale du pointeur de lecture n1 : %d\n", lseek(f1,0,1));
   printf("position initiale du pointeur de lecture n2 : %d\n", lseek(f2,0,1));
   
   read(f1, buf1, 10);
   
   printf("position nouvelle du pointeur de lecture n1 : %d\n", lseek(f1,0,1));
   printf("position nouvelle du pointeur de lecture n2 : %d\n", lseek(f2,0,1));
   
   read(f2, buf2, 5);
   
   printf("position finale du pointeur de lecture n1 : %d\n", lseek(f1,0,1));
   printf("position finale du pointeur de lecture n2 : %d\n", lseek(f2,0,1));
}


/* exécution :
fougeres@fougeres-laptop:~/NSY103/RNCP/SGF$ ./PRG2
position initiale du pointeur de lecture n1 : 0
position initiale du pointeur de lecture n2 : 0
position nouvelle du pointeur de lecture n1 : 10
position nouvelle du pointeur de lecture n2 : 10
position finale du pointeur de lecture n1 : 15
position finale du pointeur de lecture n2 : 15
fougeres@fougeres-laptop:~/NSY103/RNCP/SGF$ 
*/
