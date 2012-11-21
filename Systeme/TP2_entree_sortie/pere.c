#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main() {
   int pid, fp, j;
   char ch[4], conv[11];

   fp = open("bonjour", O_RDONLY);
   printf("valeur de fp à l'ouverture : %d\n", fp);

   pid = fork();
   if (pid == 0) {
	sprintf(conv, "%d", fp);
	execlp("./FILS", "FILS", conv, NULL);
	perror("pb exec");
   } else {
	j = 0;
	while (j<5) {
	   read(fp, ch, 4);
	   printf("père -  %s\n", ch);
	   j++;
	}
	wait(NULL);
	close(fp);
   }
   exit(0);	
}

