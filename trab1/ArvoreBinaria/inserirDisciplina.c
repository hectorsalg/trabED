#include <stdio.h>
#include <stdlib.h>
#include "./headers/curso.h"
#include "./headers/inserirDisciplina.h"
#include <string.h>

Disciplina *criarNoDisciplina(int codC, char nome[], int bloco, int cargHor){
    Disciplina *raiz;
    raiz = (Disciplina *) malloc(sizeof(Disciplina));
    raiz->codD = codC;
    strcpy(raiz->nome, nome);
    raiz->bloco = bloco;
    raiz->cargHor = cargHor;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirDisciplina(Disciplina **raiz, Disciplina *no){
    //fazer uma flag para saber se inseriu
    if(raiz){
        if((*no).codD < (**raiz).codD){
            inserirDisciplina(&((*raiz)->esq), no);
        }else{
            inserirDisciplina(&((*raiz)->dir),  no);
        }
    }else if((*raiz)->bloco > no->bloco && no->cargHor % (*raiz).semana == 0)
        *raiz = no;
}