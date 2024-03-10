#include <stdio.h>
#include <time.h>

int fibo(int num);

int main(void) {

	int num = 20;
	int i;
	printf("P1 : Fibonacci Sequence until 20\n\n");

	for (i = 0; i < num; i++)
	{
		printf("%d ", fibo(i));
	}

	printf("\n");
    
	return 0;
}

int fibo(int num) {

	if (num == 0) return 0;
	else if (num == 1) return 1;
	else return fibo(num - 1) + fibo(num - 2);
}
