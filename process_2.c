#include <stdio.h>
#include <time.h>


int main(void)
{
    int x, y, i;
  printf("P2 : Multiplication\n\n");
    for (i = 1; i < 4; i++){
        for (y = 1; y < 10; y++){
            for (x = 3 * i - 2; x < 3 * i + 1; x++){
                printf("%d * %d = %2d  ", x, y, x*y);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


