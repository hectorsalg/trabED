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
    double medias[4] = {0}, temps[4] = {0};

    lerArquivo(vet);
    embaralhar_vetor(vet);

    for(int i = 0; i < 30; i++){
        inserirValoresTestes(&raiz, vet, temps);
        medias[0] += temps[0];
        medias[1] += temps[1];
        medias[2] += temps[2];
        medias[3] += temps[3];
    }

    medias[0] /= 30;
    medias[1] /= 30;
    medias[2] /= 30;
    medias[3] /= 30;

    printf("\n\nMedia de 25: %.5lf milissegundos\n", medias[0]);
    printf("Media de 50: %.5lf milissegundos\n", medias[1]);
    printf("Media de 75: %.5lf milissegundos\n", medias[2]);
    printf("Media de 100: %.5lf milissegundos\n", medias[3]);




    return 0;
}