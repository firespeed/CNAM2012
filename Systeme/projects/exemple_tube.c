#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TAILLE_MESSAGE 256 /* Correspond à la taille de la chaîne à lire et à écrire */

int main(void)
{
    pid_t pid_fils;
    int descripteurTube[2];
    // descripteur[0]: désigne la sortie du tube ;
	// descripteur[1] : désigne l'entrée du tube.


    unsigned char messageLire[TAILLE_MESSAGE], messageEcrire[TAILLE_MESSAGE];

    printf("Création du tube.\n");
    
    if(pipe(descripteurTube) != 0)
    {
        fprintf(stderr, "Erreur de création du tube.\n");
        return EXIT_FAILURE;
    }

    pid_fils = fork();

    if(pid_fils == -1)    
    {
        fprintf(stderr, "Erreur de création du processus.\n");
        return 1;
    }

    if(pid_fils == 0)
    {
        printf("Fermeture de l'entrée dans le fils.\n\n");
        //fermeture entree
        close(descripteurTube[1]);
        // lecture de la sortie 
        read(descripteurTube[0], messageLire, TAILLE_MESSAGE);
        printf("Nous sommes dans le fils (pid = %d).\nIl a reçu le message suivant du père : \"%s\".\n\n\n", getpid(), messageLire);
    }

    else
    {
        printf("\nFermeture de la sortie dans le père.\n");
        // fermeture sortie
        close(descripteurTube[0]);
		
        sprintf(messageEcrire, "Bonjour, fils. Je suis ton père !");

        printf("Nous sommes dans le père (pid = %d).\nIl envoie le message suivant au fils : \"%s\".\n\n\n", getpid(), messageEcrire);
		// écriture dans entrée
        write(descripteurTube[1], messageEcrire, TAILLE_MESSAGE);

        wait(NULL);
    }

    return 0;
}
