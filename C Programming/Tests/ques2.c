#include <stdio.h>

int main() {
    char str[20], ch;
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    printf("Enter character: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            str[i] = '*';
        }
    }

    printf("New string: %s", str);

    return 0;
}