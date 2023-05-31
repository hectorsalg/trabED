#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include <string.h>
#include "imprimirDisciplina.h"

void imprimirDisciplina(Disciplina *raiz){
    if(raiz)
        printf("CodigoD: %d\nNome Dis: %s\nBlocos da disciplina: %d\nCarga Horaria: %d\n\n", raiz->codD, raiz->nome, raiz->bloco, raiz->cargHor);
}

void imprimirDisciplinas(Disciplina *raiz){
    if(raiz){
        imprimirDisciplinas(raiz->esq);
        imprimirDisciplina(raiz);
        imprimirDisciplinas(raiz->dir);
    }
}

void imprimirDadosDisciplina(Disciplina *raiz, int codD){
    if(raiz){
        if(raiz->codD == codD)
            imprimirDisciplina(raiz);
        else if(codD < raiz->codD)
            imprimirDadosDisciplina(raiz->esq, codD);
        else
            imprimirDadosDisciplina(raiz->dir, codD);
    }
}