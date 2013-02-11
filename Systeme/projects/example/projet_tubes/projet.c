/*-----------------------------------------------------------
               Les tubes ordinaires
               le pere lit, le fils ecrit
-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void erreur(const char* msg)      {perror(msg);exit(1);}

#define LGMAX 100
  
main(){
	  int B_CPT[2];
	  int CPT_B[2];

	  int LCD_CPT[2];
 
  
	if (pipe(B_CPT) == -1) erreur("pipe");
	if (pipe(CPT_B) == -1) erreur("pipe");

	if (pipe(LCD_CPT) == -1) erreur("pipe");
  

  //création du processus badge1
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : badge1 */
		char desc1[4]; char desc2[4];

		//Fermeture des descripteurs de tubes inutiles pour badge1
		close(B_CPT[0]); close(CPT_B[1]); close(LCD_CPT[0]) ; close(LCD_CPT[1]) ;

		sprintf(desc1,"%d",B_CPT[1]); /* communique num B_CPT[1] ecrire */
		sprintf(desc2,"%d",CPT_B[0]); /* communique num CPT_B[0] lire */

		if (execlp("xterm","xterm","-e","./BADGE1",desc1, desc2,NULL)==-1)
		erreur("execlp - Badge1");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Badge 1\n");
		}
	}

//creation du processus compteur
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : compteur */
		char desc1[4]; char desc2[4]; char desc3[4];

		//Fermeture des descripteurs de tubes inutiles pour compteur
		close(B_CPT[1]); close(CPT_B[0]); close(LCD_CPT[0]);

		sprintf(desc1,"%d",B_CPT[0]); /* communique num B_CPT[1] ecrire */
		sprintf(desc2,"%d",CPT_B[1]); /* communique num CPT_B[0] lire */
		sprintf(desc3,"%d",LCD_CPT[1]);

		if (execlp("xterm","xterm","-e","./COMPTEUR",desc1,desc2,desc3,NULL)==-1)
		erreur("execlp - Compteur");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Compteur\n");
		}
	}
	

//création du processus badge2
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : badge2 */
		char desc1[4]; char desc2[4];

		//Fermeture des descripteurs de tubes inutiles pour badge2
		close(B_CPT[0]); close(CPT_B[1]); close(LCD_CPT[0]) ; close(LCD_CPT[1]) ;

		sprintf(desc1,"%d",B_CPT[1]); /* communique num B_CPT[1] ecrire */
		sprintf(desc2,"%d",CPT_B[0]); /* communique num CPT_B[0] lire */

		if (execlp("xterm","xterm","-e","./BADGE2",desc1, desc2,NULL)==-1)
		erreur("execlp - Badge2");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation Badge 2\n");
		}
	}

//création du processus LCD
	switch (fork()) {
		case -1 : erreur("fork");

		case 0 : {
			/* fils : lcd */
		char desc1[4]; char desc2[4]; 

		//Fermeture des descripteurs de tubes inutiles pour lcd
		close(LCD_CPT[1]); close(B_CPT[0]); close(CPT_B[1]); close(B_CPT[1]); close(CPT_B[0]);

		sprintf(desc1,"%d",LCD_CPT[0]); /* communique num LCD_CPT[0] lire */

		if (execlp("xterm","xterm","-e","./LCD",desc1,NULL)==-1)
		erreur("execlp - Compteur");
		exit(1);
		}

		default :
			/* pere */
		{
		printf("Creation LCD\n");
		}
	}
  }
               
               
