/***************************************************************/
/*   EXERCICE 1 : Creation d'un fils avec affichaged'identite  */
/***************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
   pid_t pid;
   int status;

   pid = fork();
   if (pid == -1) {
	printf ("erreur creation de processus");
	exit(2);
   }
   else
	if (pid == 0)
	{
	  printf ("fils : valeur du fork, %d\n", pid);
	  printf ("fils : je suis le fils, mon pid est %d\n", getpid());
	  printf ("fils : le  pid de mon pere est %d\n", getppid());
	  sleep(20);
	  printf ("fils : je me termine ...\n");
	  exit(0);
        }
	else
	{
	  printf ("pere : valeur du fork, %d\n", pid);
	  printf ("pere : je suis le pere, mon pid est %d\n", getpid());
	  printf ("pere : le  pid de mon fils est %d\n", pid);
	  sleep(20);
	  printf ("pere : fin de mon fils\n");
        }
	exit(0);

}


/* execution : 
fils : valeur du fork, 0
fils : je suis le fils, mon pid est 23041
fils : le  pid de mon pere est 23040
fils : je me termine ...
pere : valeur du fork, 23041
pere : je suis le pere, mon pid est 23040
pere : le  pid de mon fils est 23041
pere : fin de mon fils
*/


