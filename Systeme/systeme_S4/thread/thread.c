// On inclue les fichiers standard et le header pthread.h
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
 
void* fonction_test(void* data);
  
 
int main()
{
    int i;
    
    pthread_t thread;// On crée un thread
    pthread_create(&thread, NULL, fonction_test, NULL);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread2;// On crée un thread
    pthread_create(&thread2, NULL, fonction_test, NULL);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread3;// On crée un thread
    pthread_create(&thread3, NULL, fonction_test, NULL);// Permet d'exécuter le fonction maFonction en parallèle
     pthread_t thread4;// On crée un thread
    pthread_create(&thread4, NULL, fonction_test, NULL);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread5;// On crée un thread
    pthread_create(&thread5, NULL, fonction_test, NULL);// Permet d'exécuter le fonction maFonction en parallèle
    
     pthread_t thread6;// On crée un thread
    pthread_create(&thread6, NULL, fonction_test, NULL);// Permet d'exécuter le fonction maFonction en parallèle
 
    // Affiche 50 fois 1
   // for(i=0 ; i<100000 ; i++)
    //    printf("1");
 
    // Attend la fin du thread créé
    if(pthread_join(thread, NULL)==0)
     printf ("fin des thread1");
    if(pthread_join(thread2, NULL)==0)
     printf ("fin des thread2");
    if(pthread_join(thread3, NULL)==0)
    printf ("fin des thread3");
    if(pthread_join(thread4, NULL)==0)
     printf ("fin des thread4");
    if(pthread_join(thread5, NULL)==0)
     printf ("fin des thread5");
    if(pthread_join(thread6, NULL)==0)
    printf ("fin des thread6");
    
    return 0;
}
 
 
void* fonction_test(void* data)
{
    int i;
    
    // Affiche 50 fois 2
    for(i=0 ; i<50 ; i++)
        printf("2");

    return NULL;
}
