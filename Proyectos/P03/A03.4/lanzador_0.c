#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc,char * argv[])
{
   pid_t pid;
   pid_t pid1;
   int x,y;
   if(argc != 4){
      fprintf(stderr,"Uso %s nombre_programa\n",argv[0]);
   }
 
   for(x=1;x<=1;x++){
      pid1=fork(); 
      if(pid1){
         if(execlp(argv[1],argv[1],NULL) == -1){
		       fprintf(stderr,"El programa %s no se ha podido ejecutar\n",argv[1]);
         }
         else{
		       fprintf(stderr,"El programa %s se ha ejecutado\n",argv[1]);
         }
         sleep(2);
      }else{
	      for(y=1;y<=1;y++){
            pid=fork();
            if(pid){
               if(execlp(argv[2],argv[2],NULL) == -1){
                  fprintf(stderr,"El programa %s no se ha podido ejecutar\n",argv[2]);
               }else{
                  fprintf(stderr,"El programa %s se ha ejecutado\n",argv[2]);
               }
               sleep(2);   
            }else{
               if(execlp(argv[3],argv[3],NULL) == -1){
                  fprintf(stderr,"El programa %s no se ha podido ejecutar\n",argv[3]);
               }else{
                  fprintf(stderr,"El programa %s se ha ejecutado\n",argv[3]);
               }
               sleep(2);
               exit(0);
            }

         }
         exit(0);
      }
   }
   return 0;
}
