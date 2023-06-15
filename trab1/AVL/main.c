#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Avl.h"
#include "balancear.h"
#include "inserir.h"
#include "imprimir.h"
#include "remover.h"
#include "testeDeTempo.h"


int main(){
    Curso *raiz, *aux;
    raiz = NULL;
    int vet[100000];
    double temps = 0, busca = 0;

    lerArquivo(vet);
    // embaralharVetor(vet);

    for(int i = 0; i < 30; i++){
        inserirValoresTestes(&raiz, vet, &temps);
        tempoBusca(&raiz, vet, &busca);
        liberarArvoreCurso(&raiz);
    }
    imprimirCursos(raiz);

    temps /= 30;
    busca /= 30;
    printf("Media de inserir 100: %.5lf milissegundos\n", temps);
    printf("Media de busca 100: %.5lf milissegundos\n", busca);
    
    // temps = 0;
    // for(int i = 0; i < 30; i++){
    //     tempoDeBusca(&raiz, vet, &temps);
    // }
    // temps /= 30;
    // printf("Media de busca 100: %.5lf milissegundos\n", temps);

    return 0;
}