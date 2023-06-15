#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Avl.h"
#include "inserir.h"
#include "testeDeTempo.h"

#define TAM 100000
double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;

void embaralharVetor(int vet[]) {
    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));
    
    // Embaralha o vet usando o algoritmo de Fisher-Yates
    for (int i = TAM - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}

void lerArquivo(int vetor[]){
    FILE *arquivo;
    int contador = 0;
    int numero;

    // Abrir o arquivo para leitura
    arquivo = fopen("arquivo.txt", "r");

    // Verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL)
        printf("Erro ao abrir o arquivo.\n");
    // Ler cada número do arquivo e armazená-lo no vetor
    while (fscanf(arquivo, "%d", &numero) != EOF) {
        vetor[contador] = numero;
        contador++;
    }
    // Fechar o arquivo
    fclose(arquivo);
}

void inserirValoresTestes(Curso **raiz, int vet[], double *temps){
    clock_t inicio, fim;
    double tempo = 0.0;
    int cont = 0;

    for(int i = 0; i < TAM; i++){
        inicio = clock();
        inserirCurso(raiz, criarNoCurso(vet[i], "Curso", 8, 10));
        fim = clock();
        tempo += ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;
    }
    *temps += tempo;
     
    // printf("Tempo para preencher Cem: %.5lf milissegundos\n\n", tempo);    

}

void tempoDeBusca(Curso **raiz, int vet[], double *temps){
    clock_t inicio, fim;
    double tempo = 0.0;

    inicio = clock();
    existeCurso(*raiz, 10000);
    fim = clock();
    tempo += ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;
    
    *temps += tempo;
     
    // printf("Tempo para preencher Cem: %.5lf milissegundos\n\n", tempo);    
}
