/*-------------------------------------------------------
             prg1.c : creation, attente terminaison

             compiler avec l'option -lpthread
 --------------------------------------------------------*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// declaration des variables necessaires
int nbVoitures = 0;
char e_s [25];

// declaration des mutex
pthread_mutex_t mutexBadge, mutexLcd, mutexCompteur;

void* fBadge (void* arg) 
{
	while(1){
	 pthread_mutex_lock(&mutexBadge);
	 scanf("%s", e_s);
	 pthread_mutex_unlock(&mutexCompteur);
	}
}

void* fCompteur (void* arg) 
{
	while(1){
	  pthread_mutex_lock(&mutexCompteur);
	  if(e_s[0] == 'e')
		nbVoitures ++;
	  else if(e_s[0] == 's' && nbVoitures > 0)
		nbVoitures --;
	  	else 
		printf("il n'y a pas de voitures à sortir\n");
	  printf("Calcul réalisé par compteur\n");
	  pthread_mutex_unlock(&mutexLcd);
	}
}

void* fLcd (void* arg) 
{

	while(1){
		pthread_mutex_lock(&mutexLcd);
		printf("LCD : Nombre de voitures = %d\n",nbVoitures);
		printf("LCD : Que voulez-vous faire ?\n");
		pthread_mutex_unlock(&mutexBadge);
		
		
	}
}

main(int argc,char* argv[],char* arge[])
{
  pthread_t badge;			 //declaration d'un thread
  pthread_t compteur;
  pthread_t lcd;

  int param[]={0,0,0};
  int codeRetour;

	// initialisation des threads
		
	pthread_mutex_init(&mutexBadge,NULL);
	pthread_mutex_init(&mutexLcd,NULL);
	pthread_mutex_init(&mutexCompteur,NULL);

	if (pthread_create(&badge,NULL,fBadge,param)==-1) { //creation du thread badge
	      printf("pb pthread_create badge\n"); exit(1);
	  }
	sleep(1);
	   if (pthread_create(&lcd,NULL,fLcd,param)==-1) { //creation du thread lcd
	      printf("pb pthread_create lcd\n"); exit(1);
	  }

	 if (pthread_create(&compteur,NULL,fCompteur,param)==-1) { //creation du thread compteur
	      printf("pb pthread_create compteur\n"); exit(1);
	  }
		
 	  
	 // attente de la mort des threads
	 
	  pthread_join(badge,(void**) &codeRetour);
	  pthread_join(compteur,(void**) &codeRetour);
	  pthread_join(lcd,(void**) &codeRetour);	
  
}
  
