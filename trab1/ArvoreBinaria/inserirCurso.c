#include <stdio.h>
#include <stdlib.h>
#include "./headers/curso.h"
#include <string.h>

Curso *criarCurso(){
    return NULL;
}

Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana){
    Curso *raiz;
    raiz = (Curso *) malloc(sizeof(Curso));
    raiz->codC = codC;
    raiz->disciplinas = NULL;
    strcpy(raiz->nome, nome);
    // raiz->qtdBCurso = qtdBCurso;
    raiz->semana = semana;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirCurso(Curso **raiz, Curso *no){
    if(raiz){
        if(no->codC < (**raiz).codC)
            inserirCurso(&((**raiz).esq), no);
        else if(no->codC > (**raiz).codC)
            inserirCurso(&((**raiz).dir), no);
    } else *raiz = no;
}