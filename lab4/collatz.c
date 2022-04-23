#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("NO INPUT PASSED \n");
        return 0;
    }

    if(atoi(argv[1]) <= 0)
    {
        printf("NON-POSITIVE NUMBER ENTERED \n");
        return 0;
    }

    int n = atoi(argv[1]);
    
    pid_t id;
    id = fork();

    if(id==0)
    {
        printf("child process: \n\n");
      while(n!=1)
        {
            printf("%d ",n);

            if(n%2==0)
            n/=2;
            else 
            n=(3*n)+1;

        }

        printf("%d\n",n);

    }
    else if(id > 0)
    { 
      printf("parent process waits for chaild to finish\n");
      wait(NULL);
      printf("parent process ended");
      printf("\n");
    }

    else
    {
        printf("! ! FORK ERROR ! ! \n");
    }

    return 0;
}
















































// #include<stdio.h>
// #include<unistd.h>
// #include <sys/wait.h> 




// int main(int args, int argv[])
// {
//     int n;
//     printf("n: ");
//     scanf("%d",&n);


//     if(n<1)
//         {
//             printf("n must be greater than or equal to 1 \n n: ");
//             scanf("%d",&n);
//         }

//     pid_t id;
//     id = fork();

//     if(id==0)
//     {
//       while(n!=1)
//         {
//             printf("%d ",n);

//             if(n%2==0)
//             n/=2;
//             else 
//             n=(3*n)+1;

//         }

//         printf("%d",n);

//     }
//     else 
//     {
//       wait(NULL);
//       printf("\n");
//     }
  



//     return 0;
// }

