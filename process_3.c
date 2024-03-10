#include <stdio.h>
#include <time.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("No.1 disk moves from %c to %c\n", from, to);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("No.%d disk moves from %c to %c\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main() {
	
	printf("P3 : Hanoi Top\n\n");
	hanoi_tower(3,'A','B','C');
	return 0;
}
