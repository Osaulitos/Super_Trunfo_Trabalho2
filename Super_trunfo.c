#include <stdio.h>

// Estrutura de carta
typedef struct {
    char nome[50];
    int populacao;
    float pib;
    float area;
    int pontosTuristicos;
} Carta;

// Função para exibir uma carta
void mostrarCarta(Carta c) {
    printf("Nome: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("PIB: %.2f\n", c.pib);
    printf("Área: %.2f\n", c.area);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

// Desafio 1 – Comparação simples com if/else
void compararSimples(Carta c1, Carta c2) {
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - PIB\n3 - Área\n4 - Pontos Turísticos\nOpção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        if (c1.populacao > c2.populacao)
            printf("%s vence!\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("%s vence!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else if (opcao == 2) {
        if (c1.pib > c2.pib)
            printf("%s vence!\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("%s vence!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else if (opcao == 3) {
        if (c1.area > c2.area)
            printf("%s vence!\n", c1.nome);
        else if (c2.area > c1.area)
            printf("%s vence!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else if (opcao == 4) {
        if (c1.pontosTuristicos > c2.pontosTuristicos)
            printf("%s vence!\n", c1.nome);
        else if (c2.pontosTuristicos > c1.pontosTuristicos)
            printf("%s vence!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else {
        printf("Opção inválida!\n");
    }
}

// Desafio 2 – Decisões aninhadas com switch e múltiplos atributos
void compararAvancada(Carta c1, Carta c2) {
    int opcao;
    printf("\nEscolha o atributo para comparação avançada:\n");
    printf("1 - População E PIB\n2 - Área E Pontos Turísticos\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (c1.populacao > c2.populacao) {
                if (c1.pib > c2.pib)
                    printf("%s vence!\n", c1.nome);
                else
                    printf("População maior, mas PIB menor. Empate técnico!\n");
            } else if (c2.populacao > c1.populacao) {
                if (c2.pib > c1.pib)
                    printf("%s vence!\n", c2.nome);
                else
                    printf("População maior, mas PIB menor. Empate técnico!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            if (c1.area > c2.area && c1.pontosTuristicos > c2.pontosTuristicos)
                printf("%s vence!\n", c1.nome);
            else if (c2.area > c1.area && c2.pontosTuristicos > c1.pontosTuristicos)
                printf("%s vence!\n", c2.nome);
            else
                printf("Empate técnico ou misto!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// Desafio 3 – Comparação com operador ternário
void compararComTernario(Carta c1, Carta c2) {
    int atributo1, atributo2;

    printf("\nEscolha dois atributos para comparar:\n");
    printf("1 - População\n2 - PIB\n3 - Área\n4 - Pontos Turísticos\n");

    printf("Atributo 1: ");
    scanf("%d", &atributo1);
    printf("Atributo 2: ");
    scanf("%d", &atributo2);

    float valor1_c1 = (atributo1 == 1) ? c1.populacao : (atributo1 == 2) ? c1.pib : (atributo1 == 3) ? c1.area : c1.pontosTuristicos;
    float valor2_c1 = (atributo2 == 1) ? c1.populacao : (atributo2 == 2) ? c1.pib : (atributo2 == 3) ? c1.area : c1.pontosTuristicos;

    float valor1_c2 = (atributo1 == 1) ? c2.populacao : (atributo1 == 2) ? c2.pib : (atributo1 == 3) ? c2.area : c2.pontosTuristicos;
    float valor2_c2 = (atributo2 == 1) ? c2.populacao : (atributo2 == 2) ? c2.pib : (atributo2 == 3) ? c2.area : c2.pontosTuristicos;

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nResultado: %s\n", (soma1 > soma2) ? c1.nome : (soma2 > soma1) ? c2.nome : "Empate!");
}

// Menu principal
void menu(Carta c1, Carta c2) {
    int opcao;

    do {
        printf("\n=== Super Trunfo: TechNova Edition ===\n");
        printf("1 - Mostrar Cartas\n");
        printf("2 - Comparar (Simples)\n");
        printf("3 - Comparar (Avançado)\n");
        printf("4 - Comparar (Ternário)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Carta 1 ---\n");
                mostrarCarta(c1);
                printf("\n--- Carta 2 ---\n");
                mostrarCarta(c2);
                break;
            case 2:
                compararSimples(c1, c2);
                break;
            case 3:
                compararAvancada(c1, c2);
                break;
            case 4:
                compararComTernario(c1, c2);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);
}

int main() {
    // Cartas de exemplo
    Carta carta1 = { "São Paulo", 12300000, 2200.5, 1521.11, 30 };
    Carta carta2 = { "Rio de Janeiro", 6748000, 400.7, 1182.3, 50 };

    menu(carta1, carta2);
    return 0;
}
