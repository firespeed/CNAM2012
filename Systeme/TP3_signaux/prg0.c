/*----------------------------------------------------
	Pere et Fils s'envoient le signal 16
	ce qui provoque l'affichage de leur PID
-----------------------------------------------------*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void erreur(char * s) {
   fprintf(stderr, "%s\n", s);
   exit(1);
}


int idPere, idFils;

void pere() {
   printf("pid : \n pere %d \n fils %d\n", idPere, idFils);
   sleep(1);
   /* envoi du signal 16 */
   if (kill(idFils, 16)) {
	erreur("kill du pere");
   }

   /* tempo pour attente signal du fils */
   sleep(2);
   exit(0);
}

void fils() {
   printf("pid : \n pere %d \n fils %d\n", getppid(), getpid());
   /* envoi du signal 16 */
   if (kill(idPere, 16)) {
	erreur("kill du fils");
   }

   /* tempo pour attente signal du pere */
   sleep(4);
   exit(0);
}

/* handler pour le signal 16 */
void sig16(int num) {
   printf("Signal (%d) recu par le processus %d\n", num, getpid());
}

main () {
   idPere = getpid();
   /* déclaration du traitement du signal 16 */
   signal(16, sig16);
   /* création du processus fils */
   if ((idFils = fork()) == -1) {
	erreur("fork");
   }
   if (idFils) pere();
   else fils();
}

