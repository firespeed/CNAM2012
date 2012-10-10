/* tri alpha-numerique en utilisant la fonction qsort */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>

/*-----------------------------------------------------------
                      char*
-------------------------------------------------------------*/    

int ordreAscendantCharEtoile(const char** s1, const char** s2)
  {
  return strcmp(*s1,*s2);
  }

  
void trierChaines(char** t,int nb)   
  {
  qsort(t,nb,sizeof(char*),ordreAscendantCharEtoile);
  }


/*-----------------------------------------------------------
                          int
-------------------------------------------------------------*/    

int ordreAscendantInt(int* v1, int* v2)
  {
  return *v1 - *v2;
  }

  
void trierCroissantInt()   
  {
  int u[] = {7,4,6,8};
  qsort(u,4,sizeof(int),ordreAscendantInt);
{int i;for (i=0;i<4;i++) printf("%d\n",u[i]);}
  }

int main()
{
   trierCroissantInt();
}
