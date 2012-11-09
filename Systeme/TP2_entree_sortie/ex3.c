/* Exercice 3 SGF : cp avec prinmitives d'E/S */
/*		    open, creat, read, write  */

#include <sys/types.h>		/* definitions de types */
#include <fcntl.h>		/* definit O_RDONLY, etc. */
#include <stdlib.h>		/* prototypes des appels systeme */
#include <unistd.h>		/* prototypes des appels systeme */
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
   int f1, f2;
   int nbLu;
   char buffer[512];
   
   if (argc != 3) {
    	write(2, "erreur parametre\n",18);
	exit(1);
   }
   if ((f1 = open(argv[1], 0)) == -1) {
   	write(2, "ouverture fichier source impossible\n",36);
	exit(2);
   }
   if ((f2 = creat(argv[2], 0666)) == -1) {
   	write(2, "création fichier destination impossible\n",41);
	exit(3);
   }
   
   while ((nbLu = read(f1, buffer, 512)) > 0)
   	write(f2, buffer, nbLu);
	
   exit(0);
}
   
