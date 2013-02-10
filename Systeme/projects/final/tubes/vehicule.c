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
	char tampon_lecture[LGMAX];
   
	char carte[4];
printf("vehicule :\n");
	while(1)
	{
		
		printf("repondre :\n");
		scanf("%s",carte);
		
	read(descr,tampon_lecture,LGMAX)>0;
	if(strcmp (tampon_lecture, "vehicule_0")==0)
	printf(" va chercher le mobile! \n");
	
		strcpy(tampon, carte);
		strcat(tampon,"1");

		write(descw,tampon,strlen(tampon)+1);
		  
	}
     
 exit(0);  

}
