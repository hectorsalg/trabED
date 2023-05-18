#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include <string.h>

Curso *criarCurso(){
    return NULL;
}

Curso *criarNo(int codC, char nome[], int qtdBCurso, int semana){
    Curso *raiz = (Curso *) malloc(sizeof(Curso));
    raiz->codC = codC;
    strcpy(raiz->nome, nome);
    raiz->qtdBCurso = qtdBCurso;
    raiz->semana = semana;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirCurso(Curso **raiz, Curso *no){
    if(!(*raiz)){
        (*raiz) = no;
    }else if(no->codC < (*raiz)->codC){
        inserirCurso(&((*raiz)->esq), no);
    }else if(no->codC > (*raiz)->codC){
        inserirCurso(&((*raiz)->dir), no);
    }
}

void imprimirCurso(Curso *raiz){ // InOrder
    if(raiz){
        imprimirCurso(raiz->esq);
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
        imprimirCurso(raiz->dir);
    }
}