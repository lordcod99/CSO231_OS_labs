#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>


char *file;// file name 
FILE *hf; // pointer to history file 

void savehistory(char *args)  // to save the commands to file 
{
    char *cmd;
    strcpy(cmd, args);
    char *token = strtok(cmd, " \t");
    if (strcmp(token, "\n"))
    {
        hf = fopen(file, "a");
        fputs(args, hf);
        fclose(hf);
    }

    return;
}


char **extract(char *line)  // to extarct the commands 
{
    int pos = 0;
    char **tokens = malloc(101 * sizeof(char *));
    char *token = NULL;
    token = strtok(line, " \n\t");
    while (token != NULL)
    {
        tokens[pos] = token;
        pos++;
        token = strtok(NULL, " \n\t");
    }
    tokens[pos] = NULL;
    return tokens;
}
void showHistory() // to print rencetly used commands 
{
    char *line;
    int i = 1;
    hf = fopen(file, "r");
    while (fgets(line, 100, hf))
    {
        printf("%d : %s\n", i++, line);
    }
    fclose(hf);
}

void help()
{
    printf("\n------ welcome to my shell ------\n commands you can play with:\n\n");
    printf("history: to get recently used commands \n");
    printf("\ncd [Path]: to change directory\n");
    printf("\nexit : to exit from  cutrrent shell\n");
    printf("\n----you can also use some linux commands ---\n");

    return;
}

int findcmd(char *args) // check for some default commands 
{
    if (!strcmp(args, "exit"))
    {  
        printf("terminating shell \ngood bye :) \n");
        exit(EXIT_FAILURE);
        return -1;
    }
    else if (!strcmp(args, "history"))
    {   
        showHistory();
        return 1;
    }
    else if (!strcmp(args, "help"))
    {   
        help();
        return 1;
    }
    
    return 0;
}


int run(char **args)   // to execute ohter than exit,history help 
{
    if (!strcmp(args[0], "cd") && args[1] != NULL) // we canot use cd by excvp
    {
        if (chdir(args[1]) != 0)                    // so using chdir
        {
            printf("Enter Valid Path ! !");
            exit(EXIT_FAILURE);
        }
        return 1;
    }

    pid_t child = fork();
    
    if (child == 0)
    {
        if (execvp(args[0], args) == -1)  // excvp returns -1 if not executed 
        {
            printf("!! Invalid command :( !!! \n");
            exit(EXIT_FAILURE);
        }
        exit(0);
       
    }
    else if (child < 0)
    {
        printf("! ! cant create a procees to run command ! !");
    }
    else  // if parent wait for child == linux command excution 
    {
        wait(NULL);
    }

    return 1;
}
void startshell()
{
    printf("\033[H\033[J");
    printf("\n-----------------------------------------------------\n");
    printf("              hello %s\n",getenv("USER"));
    printf("             your shell is ready\n");
    printf("-----------------------------------------------------\n");
    printf("\n");

    file = strcat(getenv("HOME"), "/Desktop/work/sem4/os/labs/lab2/history.txt");
    hf = fopen(file, "w");
    fclose(hf);
    // printf("%s\n",file);
    char cmd[150];
    char **phrasedcmd;
    int check;
    while(1)
    {
         printf("\n@%s ~># ",getenv("USER"));
        //  break;
         fgets(cmd,150,stdin);
         if(cmd[strlen(cmd)-1]!='\n')
         {  if(strlen(cmd)==150)
            printf("!! ----command length exceed ---- !!\n");
            else 
            while(getchar() != '\n');
             continue;
            continue;
         }
         else 
         {
            savehistory(cmd);
            phrasedcmd=extract(cmd);
            check=findcmd(cmd);
            if(!check)
              run(phrasedcmd);
         }


    }
 
   return;
}

int main()
{
    startshell();
    return 0;
}
