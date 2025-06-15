#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_pop;
    float pib_per_capita;
};

void calcularIndicadores(struct Carta *carta) {
    carta->densidade_pop = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

int main() {
    struct Carta carta1, carta2;

    // Entrada da primeira carta
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: "); fgets(carta1.estado, 30, stdin);
    printf("Código da carta: "); fgets(carta1.codigo, 10, stdin);
    printf("Cidade: "); fgets(carta1.cidade, 50, stdin);
    printf("População: "); scanf("%d", &carta1.populacao);
    printf("Área: "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%f", &carta1.pib);
    printf("Nº de pontos turísticos: "); scanf("%d", &carta1.pontos_turisticos);
    getchar(); // limpeza do buffer

    // Entrada da segunda carta
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); fgets(carta2.estado, 30, stdin);
    printf("Código da carta: "); fgets(carta2.codigo, 10, stdin);
    printf("Cidade: "); fgets(carta2.cidade, 50, stdin);
    printf("População: "); scanf("%d", &carta2.populacao);
    printf("Área: "); scanf("%f", &carta2.area);
    printf("PIB: "); scanf("%f", &carta2.pib);
    printf("Nº de pontos turísticos: "); scanf("%d", &carta2.pontos_turisticos);

    // Calcula Densidade Populacional e PIB per capita
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Comparação usando População
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s: %d\n", carta1.cidade, carta1.populacao);
    printf("Carta 2 - %s: %d\n", carta2.cidade, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}