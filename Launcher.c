#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pour le rand
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(void){
  pid_t fils;
    srand(time(NULL));
    int status;
    int nbgen=rand()%1+1;    //entre 1-3
    printf("%d\n",nbgen);    //test affichage
    int father;
    int system(const char *command);
    //system("clear");
    switch (nbgen)
    {
    case 1:

      fils = fork();
      printf("%d",fils);
      father = getppid();
      if(fils == 0)
      {
        system("./termsaver1");
      }
      else
      {
          father = wait(NULL);
      }
    
      break;
    case 2:
      system("./termsaver2");

      break;
    case 3:
      system("termsaver3");



      break;
}
}
