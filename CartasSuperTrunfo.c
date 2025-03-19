
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
    
    //Desafio Novato, Aventureiro e Mestre (Atualizado)

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    typedef struct {
      char nome_cidade[50];
      unsigned long int populacao;
      float area;
      float pib;
      int pontos_turisticos;
      float densidade_populacional;
      float PIB_per_capita;
      float super_poder;
    } Cidade;
    
    // Função para calcular o Super Poder
    float calcularSuperPoder(Cidade cidade) {
      /*Se usa o parâmetro "Cidade" "cidade" porque é a "Cidade" do typer struct e
       "cidade" é o nome do parâmetro*/
      float inversoDensidade = (cidade.densidade_populacional > 0)
                                   ? 1.0 / cidade.densidade_populacional
                                   : 0;
      return cidade.populacao + cidade.area + cidade.pib +
             cidade.pontos_turisticos + cidade.PIB_per_capita + inversoDensidade;
    
      /*Explicação do trecho float inversoDensidade: Se a densidade for maior que 0,
      retorna 1 dividido pela densidade populacional, se não retorna 0. Foi usado
      float inversoDensidade porque é o inverso da densidade populacional. O
      return em seguida representa a soma das variáveis*/
    }
    
    // Função para criar uma cidade (sem parâmetros)
    Cidade criarCidade() {
      Cidade cidade;
    
      printf("Digite o nome da cidade: ");
      fgets(cidade.nome_cidade, 50, stdin); // Leitura do nome da cidade
      cidade.nome_cidade[strcspn(cidade.nome_cidade, "\n")] =
          '\0'; /* Retira o \n do final da string e deixar apenas o \0.*/
    
      printf("População: ");
      scanf("%lu", &cidade.populacao); /*Alterado para lu = long unsigned int por
      causa da alteração em população no typerdef struct.*/
      printf("Área (km²): ");
      scanf("%f", &cidade.area);
      printf("PIB (bilhões): ");
      scanf("%f", &cidade.pib);
      printf("Número de pontos turísticos: ");
      scanf("%d", &cidade.pontos_turisticos);
    
      // Cálculo da densidade populacional e PIB per capita
      cidade.densidade_populacional =
          (cidade.area > 0) ? cidade.populacao / cidade.area : 0;
      cidade.PIB_per_capita =
          (cidade.populacao > 0) ? cidade.pib / cidade.populacao : 0;
    
      /*Explicação cidade.densidade_populacional: Se a area for maior que 0, retorna
       a divisão da população pela area. Se não, retorna 0.*/
      /*Explicação cidade.PIB_per_capita: Se a a população for maior que 0, retorna
       a divisão do PIB pela população. Se não, retorna 0*/
    
      // Calcular Super Poder com base nos atributos númericos da cidade
      cidade.super_poder = calcularSuperPoder(cidade); // Chamada da função
    
      return cidade;
    }
    
    // Função de comparar valores
    int comparar(float valor1, float valor2, int menorVence) {
      return menorVence ? (valor1 < valor2) : (valor1 > valor2);
      /*Se menorVence for verdadeiro, retorna valor1 < valor2. Se não,
       retorna valor1 > valor2 (maior vence)*/
    }
    
    // Função para imprimir os dados de uma cidade
    void imprimirCidade(Cidade cidade) {
      printf("\nCidade: %s\n", cidade.nome_cidade);
      printf("  População: %lu\n", cidade.populacao); /* Alterado para %lu*/
      printf("  Área: %.2f km²\n", cidade.area);
      printf("  PIB: %.2f bilhões\n", cidade.pib);
      printf("  Pontos Turísticos: %d\n", cidade.pontos_turisticos);
      printf("  Densidade Populacional: %.2f pessoas/km²\n",
             cidade.densidade_populacional);
      printf("  PIB per capita: %.2f milhões\n", cidade.PIB_per_capita * 1000);
      printf("  Super Poder: %.2f\n", cidade.super_poder);
      printf("-----------------------------\n");
    }
    
    // Função para comparar as cartas
    void compararCartas(Cidade carta1, Cidade carta2) {
      printf("\nResultados da Comparação de Cartas:\n"); // Título para a seção.
    
      printf("População: %s\n",
             (comparar(carta1.populacao, carta2.populacao, 0) ? "Carta 1 venceu"
                                                              : "Carta 2 venceu"));
      printf("Área: %s\n",
             (comparar(carta1.area, carta2.area, 0) ? "Carta 1 venceu"
                                                    : "Carta 2 venceu"));
    
      printf("PIB: %s\n", (comparar(carta1.pib, carta2.pib, 0) ? "Carta 1 venceu"
                                                               : "Carta 2 venceu"));
      printf("Pontos Turísticos: %s\n",
             (comparar(carta1.pontos_turisticos, carta2.pontos_turisticos, 0)
                  ? "Carta 1 venceu"
                  : "Carta 2 venceu"));
    
      printf(
          "Densidade Populacional: %s\n",
          (comparar(carta1.densidade_populacional, carta2.densidade_populacional, 1)
               ? "Carta 1 venceu"
               : "Carta 2 venceu"));
    
      printf("PIB per Capita: %s\n",
             (comparar(carta1.PIB_per_capita, carta2.PIB_per_capita, 0)
                  ? "Carta 1 venceu"
                  : "Carta 2 venceu"));
    
      // Comparação de Super Poder
      printf("Super Poder: %s\n",
             (comparar(carta1.super_poder, carta2.super_poder, 0)
                  ? "Carta 1 venceu"
                  : "Carta 2 venceu"));
    
      /*Explicação: O 0 significa que o maior valor vence. Se o retorno for 1
    (verdadeiro), seleciona a string "Carta 1 venceu". Se o retorno for 0 (falso),
    seleciona a string "Carta 2 venceu"*/
    }
    
    int main() {
      // Criar duas cidades
      printf("Digite os dados para a primeira cidade:\n");
      Cidade cidade1 = criarCidade();
    
      getchar(); // Limpar buffer antes de ler os dados da próxima cidade
    
      printf("\nDigite os dados para a segunda cidade:\n"); // Título da função.
      Cidade cidade2 = criarCidade();
    
      // Imprimir cidades cadastradas
      printf("\nCidades Cadastradas:\n");
      imprimirCidade(cidade1);
      imprimirCidade(cidade2);
    
      // Comparar as duas cidades
      compararCartas(cidade1, cidade2);
    
      return 0;
    }