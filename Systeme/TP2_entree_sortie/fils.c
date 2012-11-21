#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main(int argc, char *argv[]) {
   int fp, i;
   char ch[4];

   fp = atoi(argv[1]);
   printf("valeur de fp dans le dils : %d\n", fp);

   i = 0;
   while (i<5) {
	read(fp, ch, 4);
	printf("fils -  %s\n", ch);
	i++;
   }
   close(fp);
   exit(0);	
}

