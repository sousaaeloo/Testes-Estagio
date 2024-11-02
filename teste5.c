#include <stdio.h>

int main() {
    char str[100];
    char inverted[100];
    int length = 0, i;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }

    for (i = 0; i < length; i++) {
        inverted[i] = str[length - 1 - i];
    }
    inverted[length] = '\0';

    printf("String invertida: %s\n", inverted);

    return 0;
}
