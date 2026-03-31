#include <stdio.h>

int main() {
    int start, end, i, j, sum = 0, Prime;

    printf("Enter start and end: ");
    scanf("%d %d", &start, &end);

    for (i = start; i <= end; i++) {
        Prime = 1;

        if (i <= 1)
            Prime = 0;

        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                Prime = 0;
                break;
            }
        }

        if (Prime == 1) {
            sum = sum + i;
        }
    }

    printf("Sum of prime numbers = %d", sum);

    return 0;
}