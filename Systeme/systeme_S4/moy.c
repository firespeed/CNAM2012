#include <stdlib.h>
#include <stdio.h>

double *tab = NULL;

void creerTab(double tab[],int taille){
    int k=0;
    
    if(tab == NULL){
        exit(EXIT_FAILURE);
    }
    
    for(k=0; k<taille; k++){
        printf("Entrez un nombre!\n:");
        scanf("%lf", &tab[k]);
    }
}

double moyTab(double tab[], int taille, double moy){
    int k;
    for(k=0; k<taille; k++){
        moy += tab[k];
    }
    return moy = (double) moy / taille;
    
}

int main(int argc, char* argv[]){
    if(argc < 2 || argc > 3){
        fprintf(stderr,"\nUSAGE: %s au moins 1 argument\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    fprintf(stdout,"Creation du tableau de taille: %s\n", argv[1]);
    
    if(argv[1] == 0 || argv[1] == NULL){
        printf("Creation du tableau impossible! Taille NULL\n");
        exit(EXIT_FAILURE);
    }
    
    double taille = atof(argv[1]);
    tab = malloc(taille * sizeof(double));
    creerTab(tab,taille);
    double moy=0;
    moy = moyTab(tab,taille,moy);
    fprintf(stdout,"\nLa moyenne du tableau est de: %lg\n", moy);    
    free(tab);
    return 1;
}
