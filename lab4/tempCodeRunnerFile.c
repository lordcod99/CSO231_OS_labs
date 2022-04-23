#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h> 




int main()
{
    int n;
    printf("n: ");
    scanf("%d",&n);


    if(n<1)
        {
            printf("n must be greater than or equal to 1 \n n: ");
            scanf("%d",&n);
        }

    pid_t id;
    id = fork();

    if(id==0)
    {
      while(n!=1)
        {
            printf("%d ",n);

            if(n%2==0)
            n/=2;
            else 
            n=(3*n)+1;

        }

        printf("%d",n);

    }
    else 
    {
      wait(NULL);
      printf("\n");
    }
  



    return 0;
}
