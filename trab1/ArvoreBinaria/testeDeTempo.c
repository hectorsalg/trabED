#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "curso.h"
#include "inserir.h"
#include "testeDeTempo.h"

#define TAM 100000
double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;

void embaralhar_vetor(int vet[]) {
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

void inserirValoresTestes(Curso **raiz, int vet[]){
    clock_t inicio, fim;
    double temps[4], tempo = 0.0;
    int cont = 0;

    for(int i = 0; i < TAM; i++){
        inicio = clock();
        inserirCurso(raiz, criarNoCurso(vet[i], "Curso", 8, 10));
        fim = clock();
        tempo += ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

        if(i == 24999)
            temps[cont] = tempo;
        else if(i == 49999){
            ++cont;
            temps[cont] = tempo;
        }else if(i == 74999){
            ++cont;
            temps[cont] = tempo;
        }

    }
    // tempo += t3;
    printf("Tempo para preencher Vinte Cinco: %.5lf milissegundos\n", temps[0]);
    printf("Tempo para preencher Cinquenta: %.5lf milissegundos\n", temps[1]);
    printf("Tempo para preencher Setenta e cinco: %.5lf milissegundos\n", temps[2]); 
    printf("Tempo para preencher Cem: %.5lf milissegundos\n", tempo);    

}
