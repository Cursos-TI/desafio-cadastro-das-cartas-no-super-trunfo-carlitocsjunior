
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;


Cidade criarCidade(char estado, int num) {
    Cidade cidade;
    sprintf(cidade.codigo, "%c%02d", estado, num);
    printf("Digite os dados para a cidade %s:\n", cidade.codigo);
    printf("Populacao: ");
    scanf("%d", &cidade.populacao);
    printf("Area (km2): ");
    scanf("%f", &cidade.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &cidade.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &cidade.pontos_turisticos);
    return cidade;
}


void imprimirCidade(Cidade cidade) {
    printf("Cidade: %s\n", cidade.codigo);
    printf("  Populacao: %d\n", cidade.populacao);
    printf("  Area: %.2f km2\n", cidade.area);
    printf("  PIB: %.2f bilhoes\n", cidade.pib);
    printf("  Pontos Turisticos: %d\n", cidade.pontos_turisticos);
    printf("-----------------------------\n");
}

int main() {
    Cidade pais[NUM_ESTADOS][NUM_CIDADES];
    char estados[NUM_ESTADOS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
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

