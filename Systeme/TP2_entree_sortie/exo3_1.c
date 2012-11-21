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
		

   if (argc != 3) {
    	write(2, "erreur parametre\n",18);
	exit(1);
   }
   
	FILE * File_first, *File_second;
	  char ch;
	  char buffer[500] ;
	  File_first=fopen (argv[1],"r");
	  File_second=fopen (argv[2],"wb");
	  if (File_first==NULL) perror ("Error opening file");
	  else
	  {
		ch = getc( File_first );
		while( ch != EOF ) {
		  printf( "%c", ch );
		  fwrite (buffer , 1 , sizeof(buffer) , File_second );
 
		  // changement de caractere
		  ch = getc( input );
		}
		fclose (File_first);
		fclose (File_second);


	  }

   
	
   exit(0);
}
   
