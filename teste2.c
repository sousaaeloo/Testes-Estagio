#include <stdio.h>

int pertenceFibonacci(int num) {
    int a = 0, b = 1, c;

   
    if (num == a || num == b) {
        return 1; 
    }

   
    while (b <= num) {
        c = a + b;  
        a = b;      
        b = c;      

        if (b == num) {
            return 1;
        }
    }
    
    return 0; 
}

int main() {
    int numero;

  
    printf("Informe um número: ");
    scanf("%d", &numero);

    
    if (pertenceFibonacci(numero)) {
        printf("O número %d pertence à sequência de Fibonacci.\n", numero);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.\n", numero);
    }

    return 0;
}
