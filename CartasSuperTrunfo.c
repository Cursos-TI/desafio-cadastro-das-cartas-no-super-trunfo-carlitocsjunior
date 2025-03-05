
// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa


// Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    
    //Desafio Novato e Aventureiro (Atualizado)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTADOS 2
#define NUM_CIDADES 2

typedef struct {
    char estado;
    char codigo[4];
    char nome_cidade[50]; //Ajustar tamanho adequado ao nome da cidade
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float PIB_per_capita;
} Cidade;

Cidade criarCidade(char estado, int num) {
    Cidade cidade;
    sprintf(cidade.codigo, "%c%02d", estado, num);
    printf("Digite os dados para a cidade %s:\n", cidade.codigo);

    printf("Nome da cidade: ");
    fgets(cidade.nome_cidade, 50, stdin); // Leitura do nome da cidade
    cidade.nome_cidade[strcspn(cidade.nome_cidade, "\n")] = '\0';

     // Limpar buffer de entrada após leitura de números
     int c;
     while ((c = getchar()) != '\n' && c != EOF);

    printf("Populacao: ");
    scanf("%d", &cidade.populacao);
    printf("Area (km2): ");
    scanf("%f", &cidade.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &cidade.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &cidade.pontos_turisticos);
    
    // Cálculos de Densidade Populacional e PIB per Capita
    if (cidade.area > 0) {
        cidade.densidade_populacional = cidade.populacao / cidade.area;
    } else {
        cidade.densidade_populacional = 0;
    }

    if (cidade.populacao > 0) {
        cidade.PIB_per_capita = cidade.pib / cidade.populacao;
    } else {
        cidade.PIB_per_capita = 0;
    }

    return cidade;
}

void imprimirCidade(Cidade cidade) {
    printf("Cidade: %s\n", cidade.codigo);
    printf("  Populacao: %d\n", cidade.populacao);
    printf("  Area: %.2f km2\n", cidade.area);
    printf("  PIB: %.2f bilhoes\n", cidade.pib);
    printf("  Pontos Turisticos: %d\n", cidade.pontos_turisticos);
    printf("  Densidade Populacional: %.2f pessoas/km2\n", cidade.densidade_populacional);
    printf("  PIB per capita: %.2f milhoes\n", cidade.PIB_per_capita * 1000);
    printf("-----------------------------\n");
}

int main() {
    Cidade pais[NUM_ESTADOS][NUM_CIDADES];
    char estados[NUM_ESTADOS] = {'A', 'B'};
    
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            pais[i][j] = criarCidade(estados[i], j + 1);
        }
    }
    
    // Imprimindo as cidades
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            imprimirCidade(pais[i][j]);
        }
    }

    return 0;
}