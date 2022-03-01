#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include <sys/wait.h> 


int main()
{
  int n;
  printf("level of tree : ");
  scanf("%d",&n);
  pid_t p = getpid();
  printf("parent id is : %d\n", p);
  int level =1;
  for(int i=0;i<n;++i)
  {
    pid_t child = fork();
    if(child == 0)
    {
       pid_t c=getpid(),parent = getppid();
       if(p == parent)
          level =1;
        else ++level;
        printf("processs : %d of parent : %d in level : %d\n", c, parent,level);
    }
    else if(child > 0)
      wait(NULL);
    else 
     printf("fork() error \n");

  }

  return 0;

}









// int main()
// {
//     pid_t p,c1,c2,c11,c12,c21,c22;
//     // printf("startd with parent : %d\n",getpid());
//     p=getpid();
//     c1=fork(); // whill create c1 child for p 
//     if(c1==0)
//     {
//       c11 = fork(); // creates a c11 child for c1
//       if(c11==0)
//       {
//         printf("child c11 :%d of parent %d",getpid(),getppid());  
//       }
//       else 
//       {
//           c12=fork(); // creates a c12 child for c1
//           if(c12==0)
//           printf("child c12 :%d of parent %d",getpid(),getppid());  
//           else 
//           {wait(NULL); printf("child c1 :%d of parent %d",getpid(),getppid());}
//       }
//     }
//     else // now parent is nunning 
//     {
//        c2=fork(); // create  c2 child for parent  p
//        if(c2==0)
//        {
//          c21=fork();//creates c21 child for c2 
//          if(c21==0)
//          {
//             printf("child c21 :%d of parent %d",getpid(),getppid());  
//          }
//          else 
//          {
//             c22=fork(); //creates c22 child for c2 
//             if(c22==0)
//             printf("child c22 :%d of parent %d",getpid(),getppid());  
//             else 
//           {  wait(NULL); printf("child c2 :%d of parent %d",getpid(),getppid());}
//          }
//        }
//        else 
//          {wait(NULL);printf("parent is : %d",p);}
//     }

//   //  printf(" ==> current running process %d\n",getpid());

//    printf("\n");
   
//   return 0;
// }




            //         p
            //        / \
            //       /   \
            //     c1     c2
            //    / \     /  \
            // c11  c12  c21  c22














// int main()
// {
//   int n;
//   printf("level of tree : ");
//   scanf("%d",&n);
//   pid_t p = getpid();
//   printf("parent id is : %d\n", p);
//   int level =1;
//   for(int i=0;i<n;++i)
//   {
//     pid_t child = fork();
//     if(child == 0)
//     {
//        pid_t c=getpid(),parent = getppid();
//        if(p == parent)
//           level =1;
//         else ++level;
//         printf("processs : %d of parent : %d in level : %d\n", c, parent,level);
//     }
//     else if(child > 0)
//       wait(NULL);
//     else 
//      printf("fork() error \n");

//   }

//   return 0;

// }
