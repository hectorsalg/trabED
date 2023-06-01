#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include <string.h>
#include "imprimirCurso.h"
#include "imprimirDisciplina.h"

void imprimirCurso(Curso *raiz){ // InOrder
    if(raiz){
        
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
        if(raiz->disciplinas) imprimirDadosDisc(raiz->disciplinas);
        imprimirCurso(raiz->esq);
        imprimirCurso(raiz->dir);
    }
}

void imprimirCodCurso(Curso *raiz, int cod){
    if(raiz){
        if(cod == raiz->codC){
            imprimirCurso(raiz->esq);
            printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
            if(raiz->disciplinas) imprimirDadosDisc(raiz->disciplinas);
        }
        else if(cod < raiz->codC) 
            imprimirCodCurso(raiz->esq, cod);
        else 
            imprimirCodCurso(raiz->dir, cod);
    }
}

void imprimirCursosQtdB(Curso *raiz, int qtdB){
    if(raiz){
        imprimirCursosQtdB(raiz->esq, qtdB); 
        if(qtdB == raiz->qtdBCurso){
            imprimirCurso(raiz->esq);
            printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
            if(raiz->disciplinas) imprimirDisciplina(raiz->disciplinas);
        }
        imprimirCursosQtdB(raiz->dir, qtdB);
    }
}