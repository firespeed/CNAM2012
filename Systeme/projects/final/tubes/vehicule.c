#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define LGMAX 100
//~ 
//~ struct chaine_caract{
//~ char pid_mobile[50];
//~ char emplacement[50];
//~ char dest[50];
//~ 
//~ };
//~ 
//~ chaine_caract construct_table_space(char *orig){
	//~ int i=0;
	//~ chaine_caract table_space;
	//~ unsigned short position = 0;
	 //~ while(orig[position] != '\0'){
		//~ if(orig[position] != '_')
		//~ {
			//~ if(i==0){
			//~ strcat(table_space.pid_mobile,'\0');
		//~ }
		//~ else if(i==1){
			//~ strcat(table_space.emplacement,'\0');
		//~ }
					//~ 
			//~ i++;
		//~ }
		//~ else if(i==0){
			//~ strcat(table_space.pid_mobile,orig[position]);
		//~ }
		//~ else if(i==1){
			//~ strcat(table_space.emplacement,orig[position]);
		//~ }
		//~ else if(i==2){
			//~ strcat(table_space.dest,orig[position]);
		//~ }
		//~ 
			//~ position++;
	//~ 
	//~ }
	//~ strcat(table_space.dest,'\0');
//~ return table_space ;
//~ };

struct compo_struct {
  char pid[50];
   char local[50];
   char dest[50];
};

struct compo_struct split (char* str_split){
	struct compo_struct split_struct;
  char str[60];
  strcat(str,str_split);
  char * pch;
  pch = strtok (str,"_");
  int i= 0;
  while (pch != NULL)
  {
	  if(i==0)
	  strcpy(split_struct.pid,pch);
	   if(i==1)
	  strcpy(split_struct.local,pch);
	   if(i==3)
	  strcpy(split_struct.dest,pch);
    pch = strtok (NULL, "_");
    i++;
  }
  return split_struct;
}


   
   
//~ 
//~ void split (char* str_split){
  //~ char str[60];
  //~ strcat(str,str_split);
  //~ char * pch;
  //~ pch = strtok (str,"_");
  //~ while (pch != NULL)
  //~ {
    //~ printf ("%s\n",pch);
    //~ pch = strtok (NULL, "_");
  //~ }
//~ }



int main(int argc,char* argv[])
{
	int descw = atoi(argv[1]);
	int descr = atoi(argv[2]);
split("test_ok_ok");



	char tampon[LGMAX];
	char tampon_lecture[LGMAX];
   char message[LGMAX];
	char carte[4];
printf("vehicule :\n");
	while(1)
	{
	
	
printf("repondre message :\n");
	if(read(descr,message,sizeof(message))==0)
	printf ("erreur");
	if(strncmp(message,"mobile",4)==0){
	printf("Message mobile:  %s\n",message);
	struct compo_struct x = split(message);
	printf("pid %s\n",x.pid);
	printf("local %s\n",x.local);
	printf("dest %s\n",x.dest);
	//~ struct chaine_caract table_space;
	//~ prinf("pid_mobile %s\n",table_space.pid_mobile);
printf("repondre message :\n");
	scanf("%s",message);
		
	write(descw,message,sizeof(message));
}
} 
 exit(0);  

}
