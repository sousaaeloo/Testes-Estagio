#include <stdio.h>

int main() {
    
    float faturamento_sp = 67836.43;
    float faturamento_rj = 36678.66;
    float faturamento_mg = 29229.88;
    float faturamento_es = 27165.48;
    float faturamento_outros = 19849.53;

 
    float faturamento_total = faturamento_sp + faturamento_rj + faturamento_mg + faturamento_es + faturamento_outros;

    float percentual_sp = (faturamento_sp / faturamento_total) * 100;
    float percentual_rj = (faturamento_rj / faturamento_total) * 100;
    float percentual_mg = (faturamento_mg / faturamento_total) * 100;
    float percentual_es = (faturamento_es / faturamento_total) * 100;
    float percentual_outros = (faturamento_outros / faturamento_total) * 100;

   
    printf("Faturamento total: R$ %.2f\n", faturamento_total);
    printf("Percentual de faturamento por estado:\n");
    printf("SP: %.2f%%\n", percentual_sp);
    printf("RJ: %.2f%%\n", percentual_rj);
    printf("MG: %.2f%%\n", percentual_mg);
    printf("ES: %.2f%%\n", percentual_es);
    printf("Outros: %.2f%%\n", percentual_outros);

    return 0;
}
