/* exercice 1 */

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
   char buffer[100];
   
   f1 = open("./bonjour", O_RDONLY);
   f2 = open("./bonjour", O_RDONLY);
   
   printf("position initiale du pointeur de lecture n1 : %d\n", lseek(f1,0,1));
   printf("position initiale du pointeur de lecture n2 : %d\n", lseek(f2,0,1));
   
   read(f1, buffer, 40);
   
   printf("position nouvelle du pointeur de lecture n1 : %d\n", lseek(f1,0,1));
   printf("position nouvelle du pointeur de lecture n2 : %d\n", lseek(f2,0,1));
}

/* exécution :
fougeres@fougeres-laptop:~/NSY103/RNCP/SGF$ ./PRG1
position initiale du pointeur de lecture n1 : 0
position initiale du pointeur de lecture n2 : 0
position nouvelle du pointeur de lecture n1 : 40
position nouvelle du pointeur de lecture n2 : 0
fougeres@fougeres-laptop:~/NSY103/RNCP/SGF$ 
*/
