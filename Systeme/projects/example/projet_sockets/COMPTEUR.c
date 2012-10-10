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

#define LGUSER  20
#define LGREP  256
#define PORTS  6260	// port du serveur
#define PORTC  6257	// port du client

void erreur(const char* msg) {perror(msg);exit(1);}

struct sockaddr_in adr_clientBadge;
struct sockaddr_in adr_clientLcd;
struct reponse {
   char type;
   char info[LGREP];
   } rep;

struct reponseLcd{
char type;
char info[LGREP];
} repLcd;


service(int sock) {
	int r,v;		//pour les valeurBadges de retour des primitives
	int m, i, lg;
	char user[LGUSER];
   	struct passwd * getpwdnam(), *p;;
	int cpt;
	cpt = 0;
	char valeurBadge[LGREP];
	char val[LGREP];

   bzero(&adr_clientLcd, sizeof(adr_clientLcd));
   adr_clientLcd.sin_family = AF_INET;
   adr_clientLcd.sin_port = htons(PORTC);		//passage au format réseau
   adr_clientLcd.sin_addr.s_addr = INADDR_ANY;

 while(1) {
	lg = sizeof(adr_clientBadge);
	/* initialisation a zero de la zone de reception */
	bzero(user, LGUSER); //à vérifier
	/* initialisation a zero de la zone de reponse */
	bzero((char *)&rep, sizeof(rep));

	printf("En attente...\n");
   	if ((r=recvfrom(sock,valeurBadge,strlen(valeurBadge),0,(struct sockaddr*)&adr_clientBadge,&lg)) == -1) {
   	   fprintf(stderr, "Client pb fromto!valeurBadge de retour = %d\n", r);
	   exit(1);
   	}
	
	printf("valeurBadge entrée : %s \n",valeurBadge);

	if (valeurBadge[0] == 'e')
	{
		cpt++;
		sprintf(repLcd.info,"voiture entrée\n");
	}
	else
	{
		if(valeurBadge[0] == 's')
		{
			cpt--;
			sprintf(repLcd.info,"voiture sortie\n");
		}
		else
		{
			printf("Caractere saisi incorrect !!!");
			sprintf(repLcd.info,"erreur badge\n");
		}
	}
	printf("nombre de voiture : %d \n",cpt);
	
	
	/* emission de la reponse */
   	if ((r=sendto(sock,(char *)&rep,sizeof(struct reponse),0,(struct sockaddr*)&adr_clientBadge,lg)) == -1) {
   	   fprintf(stderr, "Client pb sendto! valeurBadge de retour = %d\n", r);
	   exit(1);
   	}
	
	/*emission lcd*/
   	if ((r=sendto(sock,(char *)&repLcd,sizeof(struct reponseLcd),0,(struct sockaddr*)&adr_clientLcd,lg)) == -1) {
   	   fprintf(stderr, "Client pb sendto! valeurBadge de retour = %d\n", r);
	   exit(1);
   	}	
   }
}

int main(int args, char* argv[])
{
	//declaration
	int sock;
	int namelen;
	int pid, status,fd;
	int longueur;
	struct sockaddr_in adr;

	/* creation du socket de communication */
	if ((sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
		fprintf(stderr, "creation impossible !\n");
		exit(2);
	}

   /* preparation de l'adresse */
   /* la zone mémoire pour l'adresse est mise à 0 */
   bzero(&adr, sizeof(adr));
   adr.sin_family = AF_INET;
   adr.sin_port = htons(PORTS);		//passage au format réseau
   adr.sin_addr.s_addr = INADDR_ANY;	//n'importe quelle @ IP machine locale   
   
   /* attachement du socket cree à l'adresse locale */
   if (bind(sock, (struct sockaddr *)&adr, sizeof(adr))) {
   	fprintf(stderr, "Bind : nommage de socket impossible\n");
	exit(3);
   }

	

   /* detachement du terminal */
   close(0);
   /*close(1);  si on desire l'affichage des messages*/
   close(2);
   if ((fd = open("/dev/tty", O_RDWR,0)) > -1) {
	close(fd);
   }
	service(sock);
}
