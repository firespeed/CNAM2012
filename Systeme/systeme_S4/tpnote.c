// On inclue les fichiers standard et le header pthread.h
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
int* tab;


void* somme(void* infSup);
typedef struct {
	int inf;
	int sup;
} StrucSomme;

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	printf("Atoi OK\n");
	tab = malloc(sizeof(int) * n);
	printf("malloc tab OK\n");
	int i;
	for (i = 0; i < n; ++i) {
		tab[i] = i;
	}

	StrucSomme* supInf = malloc(sizeof(StrucSomme));
	supInf->inf = 0;
	supInf->sup = n - 1;

	pthread_t thread;
	printf("struct OK\n");
	pthread_create(&thread, NULL, somme, (void*) supInf);
	void *ret = malloc(sizeof(int));
	pthread_join(thread, &ret);
	printf("%d\n", *((int *)ret));

	return 0;
}

void* somme(void* infSup) {
	StrucSomme *supInf = (StrucSomme *) infSup;
	int n = supInf->sup - supInf->inf + 1;
	if (n == 2) {
		int *ret=malloc(sizeof(int));
		*ret = tab[supInf->inf] + tab[supInf->sup];
		printf("%d + %d = %d\n",tab[supInf->inf],tab[supInf->sup],*ret);
		pthread_exit((void*) ret);
		return (void*) ret;
	}else if (n < 2) {
		int *ret=malloc(sizeof(int));
		*ret = tab[supInf->inf];
		printf("%d = %d\n",tab[supInf->inf],tab[supInf->sup],*ret);
		pthread_exit((void*) ret);
		return (void*) ret;
	} else {
		printf("thread Démaré\n");
		StrucSomme* supInf1 = malloc(sizeof(StrucSomme));
		supInf1->inf = supInf->inf;
		supInf1->sup = (supInf->sup - supInf->inf) / 2;
		pthread_t thread1;
		pthread_create(&thread1, NULL, somme, (void*) supInf1);
		StrucSomme* supInf2 = malloc(sizeof(StrucSomme));
		supInf2->inf = (supInf->sup - supInf->inf) / 2 + 1;
		supInf2->sup = supInf->sup;
		pthread_t thread2;
		pthread_create(&thread2, NULL, somme, (void*) supInf2);
		void *ret1=malloc(sizeof(int));
		void *ret2=malloc(sizeof(int));
		pthread_join(thread1, &ret1);
		pthread_join(thread2, &ret2);
		int *ret  =malloc(sizeof(int));
		printf("retour : %d et %d\n",*((int *)ret1),*((int *)ret2));
		*ret= *((int *)ret1) + *((int *)ret2);
		printf("revoi : %d\n",*ret);
		pthread_exit((void*) ret);
		return (void*) ret;
	}

	return NULL;

}
