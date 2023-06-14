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

    double temps = 0, busca = 0;
    lerArquivo(vet);
    // embaralhar_vetor(vet);
    // criaArquivo(vet);

    for(int i = 0; i < 1; i++){
        inserirValoresTestes(&raiz, vet, &temps);
        tempoDeBusca(&raiz, vet, &busca);
        liberarArvoreCurso(&raiz);
    }

    temps /= 30;
    busca /= 30;
    printf("Media de inserir 100: %.5lf milissegundos\n", temps);
    printf("Media de busca 100: %.5lf milissegundos\n", busca);

    imprimirCursos(raiz);
    return 0;
}