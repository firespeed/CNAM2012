#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

double * tab=NULL;
int nb;
printf("entrer N nombre de flottants \n");
scanf("%d",&nb);

tab = malloc (nb * sizeof(double));

if( tab == NULL )
{
		     fprintf(stderr,"Allocation impossible");
			      exit(EXIT_FAILURE);
}
int i=0;

for(i=0;i<nb;i++){
printf("entrer un nombre \n");
scanf("%lf",&tab[i]);
}

for(i=0;i<nb;i++){
printf("tab %d %g \n",i,tab[i]);

}

return 0;
}
