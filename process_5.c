#include <stdio.h>
#include <time.h>
// factorial

int factorial(int n)
{
	if (n == 1)      // n�� 1�� ��
		return 1;    // 1�� ��ȯ�ϰ� ���ȣ���� ����

	return n * factorial(n - 1);    // n�� factorial �Լ��� n - 1�� �־ ��ȯ�� ���� ����
}

int main(void) {
	printf("P5 : Factorial\n");
	int result = factorial(30);
	printf("Process result : %d \n", result);
	return 0;
}
