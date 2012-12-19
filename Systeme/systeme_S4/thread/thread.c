// On inclue les fichiers standard et le header pthread.h
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
 // la valeur retourner n'est pa correct puisque les threads utilise la meme variable en même temps 
void* fonction_test(void* carac);
 typedef struct  {
    	int *address;
    	int n;
		int i;

} MaStructure;
  
  static pthread_mutex_t verrou; /* creation du verrou */
 
int main()
{
    int i;
    int v=0;
   
MaStructure carac;
carac.address=&v;
carac.n=500000;
carac.i=50; 
    
    pthread_t thread;// On crée un thread
    pthread_create(&thread, NULL, fonction_test, &carac);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread2;// On crée un thread
    pthread_create(&thread2, NULL, fonction_test, &carac);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread3;// On crée un thread
    pthread_create(&thread3, NULL, fonction_test, &carac);// Permet d'exécuter le fonction maFonction en parallèle
     pthread_t thread4;// On crée un thread
    pthread_create(&thread4, NULL, fonction_test, &carac);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread5;// On crée un thread
    pthread_create(&thread5, NULL, fonction_test, &carac);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread6;// On crée un thread
    pthread_create(&thread6, NULL, fonction_test, &carac);// Permet d'exécuter le fonction maFonction en parallèle
 
    // Affiche 50 fois 1
   // for(i=0 ; i<100000 ; i++)
    //    printf("1");
 
    // Attend la fin du thread créé
    if(pthread_join(thread, NULL)==0)
     printf ("fin des thread1\n");
    if(pthread_join(thread2, NULL)==0)
     printf ("fin des thread2\n");
    if(pthread_join(thread3, NULL)==0)
    printf ("fin des thread3\n");
    if(pthread_join(thread4, NULL)==0)
     printf ("fin des thread4\n");
    if(pthread_join(thread5, NULL)==0)
     printf ("fin des thread5\n");
    if(pthread_join(thread6, NULL)==0)
    printf ("fin des thread6\n");
    
    printf ("valeur de v: %d\n",v);
    
  
    if(pthread_mutex_destroy(&verrou)==0)
    printf("mutex destroy\n");
    return 0;
}
 
 
void* fonction_test(void* carac)
{ 
	/* Debut de la zone protegee. */
    pthread_mutex_lock (&verrou); /* on attent de pouvoir ouvrir le verrou , le thread d'écriture est lancé avant la lecture */
	
	MaStructure* test=(MaStructure*) carac;
     int i;   
    // Affiche 50 fois 2
    for(i=0 ; i<test->n ; i++)
        *test->address+=test->i;
        //  carac->address+=carac.i;
        
    /* Fin de la zone protegee. */
    pthread_mutex_unlock (&verrou); /* on rend le verrou */

    return NULL;
}
