#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "curso.h"
#include "inserir.h"
#include "imprimir.h"
#include "remover.h"
#include "testeDeTempo.h"

#define TAM 100000

int main(){
    
    Curso *raiz, *aux;
    raiz = criarCurso();
    int op, cod, qtdBCurso, semana, bloco, cargaHor, codD, vet[TAM];
    char nome[70];

    lerArquivo(vet);
    embaralhar_vetor(vet);
    // inserirVinteCinco(&raiz, vet);
    // inserirCinquenta(&raiz, vet);
    // inserirSetentaCinco(&raiz, vet);
    inserirCem(&raiz, vet);
    // clock_t inicio, fim;

    // double tempo;

    // inicio = clock();
    
    // fim = clock();

    // tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    // printf("Tempo para preencher Arvore: %.5lf milissegundos\n", tempo);



    // inicio = clock();

    // aux = existeCurso(raiz, 1);

    // fim = clock();

    // tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    // printf("Tempo para busca Arvore: %.5lf milissegundos\n", tempo);

    removerCurso(&raiz, 6);
    
    liberarArvoreCurso(&raiz);
    imprimirCursos(raiz);
    return 0;
}