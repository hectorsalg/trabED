#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include <string.h>

Curso *criarCurso(){
    return NULL;
}

Curso *criarNo(int codC, char nome[], int qtdBCurso, int semana){
    Curso *raiz;
    raiz = (Curso *) malloc(sizeof(Curso));
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
    }else if(no->codC < (**raiz).codC){
        inserirCurso(&((**raiz).esq), no);
    }else if(no->codC > (**raiz).codC){
        inserirCurso(&((**raiz).dir), no);
    }
}

void imprimirCurso(Curso *raiz){ // InOrder
    if(raiz){
        imprimirCurso(raiz->esq);
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
        imprimirCurso(raiz->dir);
    }
}

void removerCurso(Curso **raiz, int codC) {
    Curso *aux;
    if (*raiz) {
        if ((*raiz)->codC == codC) {
            if (ehfolha(*raiz)) {
                aux = *raiz;
                *raiz = NULL;
                free(aux);
            } else if (!((*raiz)->dir) || !((*raiz)->esq)) {
                Curso *endFilho;
                endFilho = enderecoFilho(*raiz);
                aux = *raiz;
                *raiz = endFilho;
                free(aux);
            }
        }
    }
}

int ehfolha(Curso *raiz) {
    return !(raiz->esq || raiz->esq);    
}

Curso *enderecoFilho(Curso *raiz) {
    Curso *aux;
    if (raiz->dir)
        aux = raiz->dir;
    else 
        aux = raiz->esq;
    return aux;
}