#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[20];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular atributos derivados
void calcularDerivados(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir uma carta
void exibirCarta(struct Carta c) {
    printf("%s (%s): %d\n", c.cidade, c.estado, c.populacao);
}

int main() {
    struct Carta carta1, carta2;

    // Entrada de dados para a carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código da carta: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf("%s", carta1.cidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Entrada de dados para a carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código da carta: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf("%s", carta2.cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculo de densidade populacional e PIB per capita
    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    // Comparação (Atributo: População)
    printf("\nComparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - ");
    exibirCarta(carta1);
    printf("Carta 2 - ");
    exibirCarta(carta2);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
