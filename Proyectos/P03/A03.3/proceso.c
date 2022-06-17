#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

//Abuelo con un  hijo
//Papa con un hijo y  hijo tiene 2
main(void)
{

   pid_t pid;
   pid_t pid1;
   int x,y;
 
   for(x=1;x<=1;x++)
   {
      pid1=fork(); 
      if(pid1)
      {
         printf("Soy el proceso Abuelo %d\n",getpid());
         sleep(2);
      }
      else
      {
         printf("soy el Padre %d, mi padre es %d\n",getpid(),getppid());
         sleep(2);

	for(y=1;y<=1;y++)
         {
            pid=fork();
            if(pid)
            {
               printf("Soy el proceso padre otra vez %d\n",getpid());
               sleep(2);
            }
            else
            {
              printf("soy el nieto %d, mi padre es %d, mi abuelito es %d\n",getpid(),getppid(),getppid()-1);
              sleep(2);
              exit(0);
            }
         }
         exit(0);
      }
  
    }
    return 0;
}
