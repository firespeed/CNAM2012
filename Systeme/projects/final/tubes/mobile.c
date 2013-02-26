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
	

	char message[LGMAX];
printf("Que voulez vous faire :\n");
		scanf("%s",message);
		
		write(descw,message,sizeof(message));
	while(1){
	
				
printf("reception message :\n");
	if(read(descr,message,sizeof(message))==0)
printf("erreur");
	

	if(strncmp(message,"vehicule",6)==0){
	printf("response vehicule: %s\n",message);
	printf("Que voulez vous faire ");
	scanf("%s",message);
		
	write(descw,message,sizeof(message));
}
			  
	}
     
 exit(0);  

}
