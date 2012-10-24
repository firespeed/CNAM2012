// On inclue les fichiers standard et le header pthread.h
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
int* tab;


void* calcul(void* borne_envoi);
typedef struct {
	int a;
	int b;
} StrucBorne;

int max=0;
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
};

int main(int argc, char **argv) {
	int a=0;
	int b=0;
	int n=0;
	if(argc==4){
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	n = atoi(argv[3]);
	}
	else {
	printf("erreur nombre d'argument incorrect!");
	exit(1);
	}
	tab = malloc(sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++) {
		
		tab[i] = rand_a_b(a, b+1);
		
			
	} 
	printf("creation tableau ok\n");

	StrucBorne* borne = malloc(sizeof(StrucBorne));
	borne->a = 0;
	borne->b = n - 1;

	pthread_t thread;
	pthread_create(&thread, NULL, calcul, (void*) borne);
	printf("LANCEMENT DU THREAD\n");
	void *ret = malloc(sizeof(int));
	pthread_join(thread, &ret);
	printf("%d\n", *((int *)ret));

	return 0;
}

void* calcul(void* borne_envoi) {
	StrucBorne *borne = (StrucBorne *) borne_envoi;
	int n = borne->b - borne->a + 1;
	if (n == 2) {
		int *ret=malloc(sizeof(int));
		*ret = tab[borne->a]<tab[borne->b]?tab[borne->b]:tab[borne->a];
		pthread_exit((void*) ret);
		return (void*) ret;
	}
	else if (n < 2) {
		int *ret=malloc(sizeof(int));
		*ret = tab[borne->a];
		pthread_exit((void*) ret);
		return (void*) ret;
	} else {
		
		StrucBorne* borne_test = malloc(sizeof(StrucBorne));
		borne_test->a = borne->a;
		borne_test->b = (borne->b - borne->a) / 2;
		pthread_t thread1;
		pthread_create(&thread1, NULL, calcul, (void*) borne_test);
		StrucBorne* borne_test2 = malloc(sizeof(StrucBorne));
		borne_test2->a = (borne->b - borne->a) / 2 + 1;
		borne_test2->b = borne->b;
		pthread_t thread2;
		pthread_create(&thread2, NULL, calcul, (void*) borne_test2);
		void *ret1=malloc(sizeof(int));
		void *ret2=malloc(sizeof(int));
		pthread_join(thread1, &ret1);
		pthread_join(thread2, &ret2);
		int *ret  =malloc(sizeof(int));
		int max1=*((int *)ret1);
		int max2=*((int *)ret2);
		if(max1>max){
		if(max1>=max2)
			max=max1;
		else
			max=max2;
		}
		*ret=max;
		pthread_exit((void*) ret);
		return (void*) ret;
	}

	return NULL;

}
