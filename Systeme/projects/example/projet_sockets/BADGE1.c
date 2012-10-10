/*****************************************************************************/
/* clientUDP.c :                                                             */
/*                                                                           */
/* Programme permettant d'obtenir les informations contenues dans le         */
/* fichier /etc/passwd d'une machine de nom donne en premier parametre       */
/* concernant un utilisateur dont le nom est donne en second parametre       */
/* Le service correspondant est associe au port 6260 sur la machine distante */
/*                                                                           */
/* compilation : cc clientUDP.c -o clientUDP                                 */
/* appel       : clientUDP localhost fougeres                                */
/*               clientUDP sunserv fougeres                                  */
/*****************************************************************************/

/***** EXECUTION :
 fougeres@fougeres-laptop: ./clientUDP localhost fougeres
 Envoi requête (à localhost, sur port 6260) / attente réponse
 utilisateur afougere sur sunserv2

         uid = 1000 ; gid = 1000

 fougeres@fougeres-laptop: clientUDP localhost xxxx
 xxxx : utilisateur inconnu sur localhost!
 *****/

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
#include <signal.h>

#define PORTS  6260	//port du serveur
#define PORTC  6259	//port du client
#define LGREP  256

int sock;

void erreur(char* msg)
  {
  fprintf(stderr,"%s\n",msg);
  exit(1);
  }

void traitantSIGINT(int num)
  {
  if (num!=SIGINT) erreur("y-a un lezard...");
  close(sock);
}

int main(int argc, char * argv[])
{
   struct sockaddr_in sin;
   struct hostent *h;  
   int lg;
   int uid=0, gid=0;
   int r,i=0, nbEnvois=0;		//pour les valeurs de retour des primitives
   char p[LGREP];

   char valeurBadge[20];
   
   /* reponse du serveur */
   struct {
 	 char type;
	 char info[LGREP];
	 } rep;
   
   if (argc < 3) {
   	fprintf(stderr, "nombre de parametres incorrect!\n");
        exit(1);
   }

   if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) <0) {
	perror("socket");
	exit(1);
   }   

   // en cas d'arrêt brutal, Ctrl + C
   signal(SIGINT,traitantSIGINT);
   
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

   bzero((char *)&sin, sizeof(sin));
   sin.sin_family = AF_INET;
   bcopy(h->h_addr, &sin.sin_addr, h->h_length); /*maj de l'adresse*/ 
   sin.sin_port = htons(PORTS);

while(1){
   printf("Entrez la valeur de votre badge, SVP\n");
   scanf("%s", valeurBadge);
   strcat(valeurBadge,"0");

	nbEnvois=0;
	while (nbEnvois < 10)
	{
		 /* envoi du message : nom de l'utilisateur */
		   if ((r=sendto(sock,valeurBadge,strlen(valeurBadge),0,(struct sockaddr *)&sin,sizeof(sin))) == -1) {
		   	fprintf(stderr, "Client pb sendto! valeur de retour = %d\n", r);
			exit(1);
		   }
		   fprintf(stdout, "Envoi requête (à %s, sur port %d) / attente réponse\n", argv[1],PORTS); 
		   nbEnvois++;
	
		   /* attente de la reponse du serveur */
		   lg = sizeof(sin);
			
		   /* si la réponse du serveur n'est pas recu on renvoie le message */	
		   if ((r=recvfrom(sock,(char *)&rep,sizeof(rep),0,(struct sockaddr*)&sin,&lg)) == -1) {
			while (i<10000) {
				if ((r=recvfrom(sock,(char *)&rep,sizeof(rep),0,(struct sockaddr*)&sin,&lg)) == -1)
					i++;
				else{
					printf("ACK reçu\n");
					break;
				}
			}
			
		   }else{
		   	printf("ACK reçu\n");
			break;
		}
		   /* exploitation de la reponse */
		
		
	}
	

}
close(sock);
}

	
