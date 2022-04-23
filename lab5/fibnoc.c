#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long fib[100];

void *threadFibo(void *arg)
{
	long n = (long)arg;

	for(int i=0; i<n; i++)
	{
		if(i == 0)
			fib[i] = 0;

		else if(i == 1)
			fib[i] = 1;

		else
			fib[i] = fib[i-1] + fib[i-2];
	}
}

int main(int argc, char const *argv[])
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

    long n = atoi(argv[1]);
	pthread_t tid;

	pthread_create(&tid, NULL, threadFibo, (void *)n);
    pthread_join(tid, NULL);

    for(int i=0; i<n; i++)
    	printf("%ld ", fib[i]);
    printf("\n");
 
	pthread_exit(NULL);
	return 0;
}




































































// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

// #define MAX_N 100

// // this data is shared by the threads.
// long int fib[MAX_N];

// // thread func to compute fibonacci.
// void *runner(void *param) {
// 	int n = atoi(param);
// 	fib[0] = 0;
// 	fib[1] = 1;
// 	for (int i = 2; i < n; i++) {
// 		fib[i] = fib[i - 1] + fib[i - 2];
// 	}
// 	pthread_exit(0);
// }

// int main(int argc, char *argv[]) {

// 	pthread_t tid;
// 	// pthread_attr_t attr;

// 	if (argc != 2 || atoi(argv[1]) <= 0 || atoi(argv[1]) > 100) {
// 		fprintf(stderr, "Usage : ./a.out <Positive Integer Value <= 100>\n");
// 		return -1;
// 	}
	
// 	// init thread with default attributes.
// 	// pthread_attr_init(&attr);

// 	// create the thread.
// 	pthread_create(&tid, NULL, runner, argv[1]);
	
// 	// parent thread will wait for the child thread to exit.
// 	pthread_join(tid, NULL);
	
// 	// parent thread will output the fib sequence computed by the child thread.
// 	printf("Fibonacci sequence : ");
// 	for (int i = 0; i < atoi(argv[1]); i++) {
// 		printf("%ld ", fib[i]);
// 	}
// 	printf("\n");

// 	return 0;
// }