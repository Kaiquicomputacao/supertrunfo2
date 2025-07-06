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

// Função para pegar o valor de um atributo
float obterValor(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Comparação de um atributo (retorna 1 se carta1 vence, -1 se carta2 vence, 0 se empate)
int compararAtributo(float v1, float v2, int atributo) {
    if (atributo == 5) { // Regra especial: menor densidade vence
        return (v1 < v2) ? 1 : (v2 < v1) ? -1 : 0;
    }
    return (v1 > v2) ? 1 : (v2 > v1) ? -1 : 0;
}

// Função principal de comparação
void compararCartas(Carta c1, Carta c2, int att1, int att2) {
    printf("\n--- Comparação entre %s e %s ---\n", c1.nome, c2.nome);

    float v1_att1 = obterValor(c1, att1);
    float v2_att1 = obterValor(c2, att1);

    float v1_att2 = obterValor(c1, att2);
    float v2_att2 = obterValor(c2, att2);

    float soma1 = v1_att1 + v1_att2;
    float soma2 = v2_att1 + v2_att2;

    printf("Atributo 1: %s\n", nomeAtributo(att1));
    printf("%s: %.2f | %s: %.2f\n", c1.nome, v1_att1, c2.nome, v2_att1);

    printf("Atributo 2: %s\n", nomeAtributo(att2));
    printf("%s: %.2f | %s: %.2f\n", c1.nome, v1_att2, c2.nome, v2_att2);

    printf("Soma dos atributos:\n");
    printf("%s: %.2f | %s: %.2f\n", c1.nome, soma1, c2.nome, soma2);

    if (soma1 > soma2)
        printf("Resultado: %s venceu!\n", c1.nome);
    else if (soma2 > soma1)
        printf("Resultado: %s venceu!\n", c2.nome);
    else
        printf("Resultado: Empate!\n");
}

int main() {
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.5, 10, 25.0};
    Carta carta2 = {"Japão", 125000000, 377975.0, 5100.8, 8, 330.9};

    int att1, att2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("Escolha dois atributos para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");

    printf("Digite o número do primeiro atributo: ");
    scanf("%d", &att1);

    do {
        printf("Digite o número do segundo atributo (diferente do primeiro): ");
        scanf("%d", &att2);
        if (att1 == att2) printf("Você deve escolher dois atributos diferentes!\n");
    } while (att1 == att2);

    compararCartas(carta1, carta2, att1, att2);

    return 0;
}