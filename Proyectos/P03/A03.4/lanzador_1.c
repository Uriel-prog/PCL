#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc,char * argv[])
{
   int wstatus;
   pid_t pid;
   pid_t pid1;
   pid_t pid2;
   int x,y,z;

   if(argc != 4){
      fprintf(stderr,"Uso %s nombre_programa\n",argv[0]);
      exit(0);
   }
   printf("\nComienza el programa %s \n",argv[1]);
   for(x=1;x<=1;x++){
      pid=fork(); 
      if(waitpid(pid,&wstatus, WUNTRACED | WCONTINUED) == -1){
         if(execlp(argv[1],argv[1],NULL) == -1){
             fprintf(stderr,"El programa %s no se ha podido ejecutar\n",argv[1]);
         }
         else{
             fprintf(stderr,"El programa %s se ha ejecutado\n",argv[1]);
         }
         sleep(1);
      }else{
         printf("\nComienza el programa %s \n",argv[2]);
         for(y=1;y<=1;y++){
            pid1=fork();
            if(waitpid(pid1,&wstatus, WUNTRACED | WCONTINUED) == -1){
               if(execlp(argv[2],argv[2],NULL) == -1){
                  fprintf(stderr,"El programa %s no se ha podido ejecutar\n",argv[2]);
               }
               else{
                  fprintf(stderr,"El programa %s se ha ejecutado\n",argv[2]);
               }
               sleep(1);   
            }else{
               printf("\nComienza el programa %s \n",argv[3]);
               for(z=1;z<=1;z++){
                  pid2=fork();
                  if(waitpid(pid2,&wstatus, WUNTRACED | WCONTINUED) == -1){
                     if(execlp(argv[3],argv[3],NULL) == -1){
                        fprintf(stderr,"El programa %s no se ha podido ejecutar\n",argv[3]);
                     }else{
                        fprintf(stderr,"El programa %s se ha ejecutado\n",argv[3]);
                     }
                     sleep(1);   
                  }
                  exit(0);
               }
            }
            exit(0);
         }
      }
   return 0;
   }
}
