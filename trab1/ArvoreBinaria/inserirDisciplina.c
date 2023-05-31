#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include "inserirDisciplina.h"
#include <string.h>

Disciplina *criarNoDisciplina(int codD, char nome[], int bloco, int cargHor){
    Disciplina *raiz;
    raiz = (Disciplina *) malloc(sizeof(Disciplina));
    raiz->codD = codD;
    strcpy(raiz->nome, nome);
    raiz->bloco = bloco;
    raiz->cargHor = cargHor;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirDisciplina(Curso **curso, int codC, Disciplina *no){
    //fazer uma flag para saber se inseriu
    Curso *aux;
    aux = existeCurso(*curso, codC);

    if(aux){
        if(aux->qtdBCurso > no->bloco && no->cargHor % (*curso)->semana == 0)
            auxiliarInserirDisc(&(aux->disciplinas), no);
    }
}

void auxiliarInserirDisc(Disciplina **raiz, Disciplina *no){
    if(!*raiz)
        *raiz = no;
    else if(no->codD < (*raiz)->codD)
        auxiliarInserirDisc(&((*raiz)->esq), no);
    else if(no->codD > (*raiz)->codD)
        auxiliarInserirDisc( &((*raiz)->esq), no);
}