#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função que troca dois elementos de um vetor
void troca(int vetor[], int i, int j) {
  int aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

// Função que embaralha um vetor usando o algoritmo de Fisher-Yates
void embaralhar(int vetor[], int n) {
  // Inicializa o gerador de números aleatórios
  srand(time(NULL));
  // Percorre o vetor de trás para frente
  for (int i = n - 1; i > 0; i--) {
    // Escolhe um índice aleatório entre 0 e i
    int j = rand() % (i + 1);
    // Troca o elemento na posição i com o elemento na posição j
    troca(vetor, i, j);
  }
}

// Função que imprime um vetor na tela
void imprimir(int vetor[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", vetor[i]);
    if (i < n - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main() {
  // Cria um vetor de exemplo
  int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  // Imprime o vetor original
  printf("Vetor original: ");
  imprimir(v, 10);
  
  // Embaralha o vetor
  embaralhar(v, 10);
  
  // Imprime o vetor embaralhado
  printf("Vetor embaralhado: ");
  imprimir(v, 10);
  
  return 0;
}