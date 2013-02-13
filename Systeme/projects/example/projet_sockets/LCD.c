#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stropts.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define PORTC  6257	//port du client
#define LGREP  256

void erreur(const char* msg) {perror(msg);exit(1);}



int main(int args, char* argv[])
{

	//Declaration
	int sock, lg;
	int uid=0, gid=0;
	int r;
	char p[LGREP];
	struct hostent *h = NULL;
	struct sockaddr_in sin = {0};
	const char *hostname = "localhost";

	/* reponse du serveur */
	struct {
	char type;
	char info[LGREP];
	} rep;
	
  	//Création du socket
	if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) <0) {
		perror("socket");
		exit(1);
	}

	/* preparation de l'adresse du client */
	bzero((char *)&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTC);
	sin.sin_addr.s_addr = INADDR_ANY;


	if(bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		perror("Client : bind");
		exit(2);
	}
	if ((h = gethostbyname("localhost")) == NULL) {   
		fprintf(stderr, "nom de machine incorrect!\n");
		exit(1);
	}


		

while(1){

	//fprintf(stdout, "En attente d'une voiture...\n");	

	/* attente de la reponse du serveur */
		lg = sizeof(sin);
		if ((r=recvfrom(sock,(char *)&rep,sizeof(rep),0,(struct sockaddr*)&sin,&lg)) == -1) {
		fprintf(stderr, "Client pb fromto!valeur de retour = %d\n", r);
		exit(1);
	}
	fprintf(stdout,"%s",rep.info);
	}
   close(sock);

}
