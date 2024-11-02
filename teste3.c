#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIAS 30


typedef struct {
    int dia;
    float valor;
} Faturamento;


void calcular_faturamento(Faturamento faturamentos[], int dias_validos, float *menor, float *maior, int *dias_acima_media) {
    *menor = faturamentos[0].valor;
    *maior = faturamentos[0].valor;
    float soma = 0;
    *dias_acima_media = 0;

   
    for (int i = 0; i < dias_validos; i++) {
        if (faturamentos[i].valor < *menor) {
            *menor = faturamentos[i].valor;
        }
        if (faturamentos[i].valor > *maior) {
            *maior = faturamentos[i].valor;
        }
        soma += faturamentos[i].valor;
    }

   
    float media = soma / dias_validos;
    for (int i = 0; i < dias_validos; i++) {
        if (faturamentos[i].valor > media) {
            (*dias_acima_media)++;
        }
    }
}


void ler_json(const char *filename, Faturamento faturamentos[], int *dias_validos) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Não foi possível abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int dia;
    float valor;
    *dias_validos = 0;

   
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "\"%d\": %f", &dia, &valor) == 2) {
            if (valor > 0) {
                faturamentos[*dias_validos].dia = dia;
                faturamentos[*dias_validos].valor = valor;
                (*dias_validos)++;
            }
        }
    }
    
    fclose(file);
}

int main() {
    Faturamento faturamentos[MAX_DIAS];
    int dias_validos;


    ler_json("faturamento.json", faturamentos, &dias_validos);

    float menor, maior;
    int dias_acima_media;

    calcular_faturamento(faturamentos, dias_validos, &menor, &maior, &dias_acima_media);


    printf("Menor faturamento: R$ %.2f\n", menor);
    printf("Maior faturamento: R$ %.2f\n", maior);
    printf("Número de dias com faturamento acima da média: %d\n", dias_acima_media);

    return 0;
}
