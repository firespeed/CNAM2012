#include <sys/types.h>		/* definitions de types */
#include <fcntl.h>		/* definit O_RDONLY, etc. */
#include <stdlib.h>		/* prototypes des appels systeme */
#include <unistd.h>		/* prototypes des appels systeme */
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

main(int argc, char *argv[])
{
	int temp = 25;
	FILE lecture;
	lecture = fopen(argv[1], "r");
	c = getc(lecture);
	while(lecture != EOF)
	{
		fprintf(lecture,"%d",c);
		c = getc(lecture);
	}
	
   
   
   exit(0);
}
   
