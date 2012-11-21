/*-----------------------------------------------------------
    recouvrement de processus et attente de terminaison du fils
-------------------------------------------------------------*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double frand_a_b(double a, double b);
void create_map();
void create_process(char* nom_process,int nb_process);

int main(int argc,char* argv[],char* arge[]){
  //génération map
  create_map();
	  
  switch (fork()) {
     case (pid_t) -1 :  perror(""),exit(1);// break inutile
     case (pid_t)  0 :   
         /* on est dans le processus fils */
         // exécution du programme fils excl(programme,nom_vituelle_prog,argument)    
        
       create_process("mobile",atoi(argv[1]));
       create_process("vehicule",atoi(argv[2]));
	
		//au programme il fera donc un exit a la fin de l'execution du programme fils
		exit(1);
     default:
       // wait(NULL); // le pere attend que les processus fils soit terminer 
        printf("je suis le pere parent \n");
     }
     return 0;
  }
  
// mise en place gestion process mobile et vehicule  
void create_process(char* nom_process,int nb_process){
	int i;

	for (i = 1; i <= nb_process; i++)
	{
	  
		switch (fork()) {
		 case (pid_t) -1 :  perror(""),exit(1);// break inutile
		 case (pid_t)  0 :{
			char buf[32];
			sprintf(buf, "%d", i);
			char nom_process_vituel[50];
			strcat(nom_process_vituel,nom_process);
			strcat(nom_process_vituel,"_");
			strcat(nom_process_vituel,buf);
			
			 // création des processus mobile 
			// execl(nom_process, nom_process_vituel,NULL);
			 execlp("/usr/bin/xterm",nom_process_vituel, "-e",nom_process,NULL);
			 //TODO: intégration dans un array 
			} 
		default:
		 // wait(NULL); // le pere attend que les processus fils soit terminer 
        /* on est dans le processus pere */
        printf("je suis le pere \n");
				
		}
	}
}
   
   
// mise en place de la carte avec les differentes zone de déplacement 
void create_map(){
// matrice distance et temps 

	int nbPoints = 5;
	int dis=0;
	// Tableau : premier point ; deuxième point ; distance et temps
	int tableau [nbPoints][nbPoints][2];
	
	// Initialisation origine = destination
	int i,y;
	for( i = 0; i < nbPoints; i++)
	{
		for(y=0; y < nbPoints;y++){
			
			if(i!=y)
				dis = frand_a_b(1,20);
			else 
				dis=0;
			tableau[i][y][0] = dis; // Distance
			tableau[y][i][0] = dis; // Distance
			tableau[i][y][1] = (dis/2); // temps
			tableau[y][i][1] = (dis/2); // temps
		}
	}
	// affichage map une fois création
	for( i = 0; i < nbPoints; i++)
	{
		for(y=0; y < nbPoints;y++){
		
			printf("Origine: %d , Destination: %d , distance en m: %d , temps en min: %d \n", i, y, tableau[i][y][0],tableau[i][y][1]);
		}
	}

}

double frand_a_b(double a, double b){
    return ( rand()/(double)RAND_MAX ) * (b-a) + a;
}

