#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para comparar os atributos
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\nComparando os países: %s vs %s\n", c1.nome, c2.nome);

    float valor1, valor2;
    char nomeAtributo[30];

    switch (atributo) {
        case 1:
            strcpy(nomeAtributo, "População");
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2:
            strcpy(nomeAtributo, "Área");
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3:
            strcpy(nomeAtributo, "PIB");
            valor1 = c1.pib;
            valor2 = c2.pib;
            break;
        case 4:
            strcpy(nomeAtributo, "Pontos Turísticos");
            valor1 = c1.pontosTuristicos;
            valor2 = c2.pontosTuristicos;
            break;
        case 5:
            strcpy(nomeAtributo, "Densidade Demográfica");
            valor1 = c1.densidadeDemografica;
            valor2 = c2.densidadeDemografica;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("Atributo escolhido: %s\n", nomeAtributo);
    printf("Valor de %s: %.2f\n", c1.nome, valor1);
    printf("Valor de %s: %.2f\n", c2.nome, valor2);

    if (atributo == 5) {
        // Regra especial: menor densidade vence
        if (valor1 < valor2)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (valor2 < valor1)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");
    } else {
        // Regra geral: maior valor vence
        if (valor1 > valor2)
            printf("Resultado: %s venceu!\n", c1.nome);
        else if (valor2 > valor1)
            printf("Resultado: %s venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");
    }
}

int main() {
    // Cartas exemplo
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.5, 10, 25.0};
    Carta carta2 = {"Japão", 125000000, 377975.0, 5100.8, 8, 330.9};

    int escolha;

    printf("=== SUPER TRUNFO - COMPARADOR DE CARTAS ===\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}