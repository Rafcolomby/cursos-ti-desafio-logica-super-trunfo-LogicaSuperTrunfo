#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados das cartas
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta; //

// Função para calcular a densidade populacional e o PIB per capita
void CalcularIndicadores(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para comparar os atributos e determinar o vencedor
void compararCartas(Carta carta1, Carta carta2, int opcao) {
    printf("\nComparando as cartas...\n");

    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            else if (carta1.populacao < carta2.populacao)
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("Carta 1 - %.2f\n", carta1.area);
            printf("Carta 2 - %.2f\n", carta2.area);
            if (carta1.area > carta2.area)
                printf("Resultado: Carta 1 venceu!\n");
            else if (carta1.area < carta2.area)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Carta 1 - %.2f\n", carta1.pib);
            printf("Carta 2 - %.2f\n", carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Resultado: Carta 1 venceu!\n");
            else if (carta1.pib < carta2.pib)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos turísticos\n");
            printf("Carta 1 - %d\n", carta1.pontos_turisticos);
            printf("Carta 2 - %d\n", carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Resultado: Carta 1 venceu!\n");
            else if (carta1.pontos_turisticos < carta2.pontos_turisticos)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade populacional (menor vence)
            printf("Atributo: Densidade populacional\n");
            printf("Carta 1 - %.2f\n", carta1.densidade_populacional);
            printf("Carta 2 - %.2f\n", carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional)
                printf("Resultado: Carta 1 venceu!\n");
            else if (carta1.densidade_populacional > carta2.densidade_populacional)
                printf("Resultado: Carta 2 venceu!\n");
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    Carta carta1 = {"RS", "4300", "Porto Alegre", 1484941, 496.8, 70000000000, 25};
    Carta carta2 = {"SP", "3550", "São Paulo", 12300000, 1521.11, 699000000000, 40};

    CalcularIndicadores(&carta1);
    CalcularIndicadores(&carta2);

    int escolha;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional (menor vence)\n");
    printf("Digite a opção: ");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}
