
//Desafio Nível mestre - Tema 3

#include <stdio.h>

// Movimento do Cavalo com loops complexos
void movimentoCavalo() {
  int vertical = 2;   // Duas casas para cima
  int horizontal = 1; // Uma casa para a direita

  for (int v = 0; v < vertical; v++) {
    for (int h = 0; h < horizontal; h++) {
      printf("Cima\n");
      if (v == vertical - 1 &&
          h == horizontal - 1) { /* O if (v e h), verifica o ultimo movimento do
                                    cavalo em L.*/
        printf("Direita\n");
        break;
      }
    }
  }
}

// Função recursiva para o movimento da Torre
void movimentoTorre(int movimentos) {
  if (movimentos == 0)
    return; // Encerra a recursão se for igual a 0.
  printf("Direita\n");
  movimentoTorre(movimentos - 1); // Decremento com movimentos - 1.
}

// Função recursiva para o movimento do Bispo, com loops aninhados
void movimentoBispoRecursivo(int vertical, int horizontal) {
  if (vertical == 0)
    return; // Encerra a recursão se vertical for igual a 0.
  for (int b = 0; b < horizontal; b++) {
    printf("Cima, Direita\n");
  }
  movimentoBispoRecursivo(vertical - 1, horizontal);
}

// Função recursiva para o movimento da Rainha
void movimentoRainha(int movimentos) {
  if (movimentos == 0)
    return; // Encerra a recursão se vertical for igual a 0.
  printf("Esquerda\n");
  movimentoRainha(movimentos - 1);
}

int main() {
  // Movimento do Cavalo (loops complexos)
  printf("Movimento do Cavalo:\n");
  movimentoCavalo();
  printf("\n"); // Separador entre os movimentos

  // Movimento da Torre (recursividade)
  printf("Movimento da Torre:\n");
  movimentoTorre(5);
  printf("\n"); // Separador entre os movimentos

  // Movimento do Bispo (recursividade + loops aninhados)
  printf("Movimento do Bispo:\n");
  movimentoBispoRecursivo(5,
                          1); // 5 movimentos verticais, 1 horizontal por passo
  printf("\n");               // Separador entre os movimentos

  // Movimento da Rainha (recursividade)
  printf("Movimento da Rainha:\n");
  movimentoRainha(8);
  printf("\n"); // Separador entre os movimentos

  return 0;
}

/*Explicação:

  Recursividade (Torre, Rainha e Bispo):
  Foi substituído os loops simples por funções recursivas.
  Para o Bispo, loops aninhados dentro da função recursiva, como especificado.

  Loops Complexos (Cavalo):
  Foi alterado para usar loops aninhados com
   múltiplas variáveis, o movimento duas casas para cima e uma para a
  direita em "L" e utilizado break para finalizar o loop em condições
  específicas.

*/
