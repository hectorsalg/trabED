#include <stdio.h>
#include <stdlib.h>
#include "./headers/curso.h"
#include <string.h>
#include "./headers/imprimirCurso.h"
#include "./headers/imprimirDisciplina.h"

void imprimirCurso(Curso *raiz){
    if(raiz)
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->blocos, raiz->semana);
}

void imprimirCursos(Curso *raiz){
    if(raiz){
        imprimirCursos(raiz->esq);
        imprimirCurso(raiz);
        if(raiz->disciplinas) imprimirDisciplinas(raiz->disciplinas); // falta codigo de disciplina
        imprimirCursos(raiz->dir);
    }
}

void imprimirDadosCurso(Curso *raiz, int cod){
    if(raiz){
        if(cod == raiz->codC){
            imprimirCurso(raiz);
            if(raiz->disciplinas) imprimirDisciplinas(raiz->disciplinas);
        }
        else if(cod < raiz->codC) 
            imprimirDadosCurso(raiz->esq, cod);
        else 
            imprimirDadosCurso(raiz->dir, cod);
    }
}

void imprimirCursosQtdB(Curso *raiz, int qtdB){
    if(raiz){
        imprimirCursosQtdB(raiz->esq, qtdB); 
        if(qtdB == raiz->blocos[0] || qtdB == raiz->blocos[1]){
            imprimirCurso(raiz->esq);
            printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->blocos, raiz->semana);
            if(raiz->disciplinas) imprimirDisciplina(raiz->disciplinas);
        }
        imprimirCursosQtdB(raiz->dir, qtdB);
    }
}

void imprimirDiscCurso(Curso *raiz, int codD, int codC){
    if(raiz){
        if(codC == raiz->codC) {
            imprimirDadosDisciplina(raiz->disciplinas, codD);
        } else if(codC < raiz->codC) 
            imprimirDiscCurso(raiz->esq, codD, codC);
        else if(codC > raiz->codC) 
            imprimirDiscCurso(raiz->dir, codD, codC);
    }
}

void imprimirDiscBloco(Curso *raiz, int codC, int bloco){
    if(raiz){
        if(codC == raiz->codC){
            if(raiz->disciplinas->bloco == raiz->blocos[bloco])
                imprimirDisciplina(raiz->disciplinas);
        } else if(codC < raiz->codC)
            imprimirDiscBloco(raiz->esq, codC, bloco);
        else if(codC > raiz->codC)
            imprimirDiscBloco(raiz->dir, codC, bloco);
    }
}

void imprimirDiscCursoHorario(Curso *raiz, int codC, int cargaHor){
    if(raiz){
        if(codC == raiz->codC){
                imprimirDisciplina(raiz->disciplinas);
        } else if(codC < raiz->codC)
            imprimirDiscCursoHorario(raiz->esq, codC, cargaHor);
        else if(codC > raiz->codC)
            imprimirDiscCursoHorario(raiz->dir, codC, cargaHor);
    }
}