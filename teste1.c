#include <stdio.h>

int main() {
    int INDICE = 13, SOMA = 0, K = 0;

    while (K < INDICE) {
        K = K + 1;   
        SOMA = SOMA + K;  
    }

    printf("A soma dos números de 1 a %d é: %d\n", INDICE, SOMA);
    
    return 0;
}
