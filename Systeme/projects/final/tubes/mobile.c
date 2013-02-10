#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define LGMAX 100

int main(int argc,char* argv[])
{
	int descw = atoi(argv[1]);
	int descr = atoi(argv[2]);
	char tampon[LGMAX];

	char carte[4];

	while(1){
	
		printf("mobile :\n");
		scanf("%s",carte);
		
		strcpy(tampon, carte);
		strcat(tampon,"0");
			
		write(descw,tampon,strlen(tampon)+1);
			  
	}
     
 exit(0);  

}
