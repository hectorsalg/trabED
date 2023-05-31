#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"
#include "imprimirCurso.h"
#include "imprimirDisciplina.h"

void imprimirCurso(Curso *raiz){
    if(raiz)
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
}

// 1
void imprimirCursos(Curso *raiz){
    if(raiz){
        imprimirCursos(raiz->esq);
        imprimirCurso(raiz);
        // if(raiz->disciplinas) imprimirDisciplinas(raiz->disciplinas); // falta codigo de disciplina
        imprimirCursos(raiz->dir);
    }
}

// 2
void imprimirDadosCurso(Curso *raiz, int cod){
    Curso *aux;
    aux = existeCurso(raiz, cod);
    if(aux){
        imprimirCurso(raiz);
            // if(raiz->disciplinas) imprimirDisciplinas(raiz->disciplinas);
    }
}

// 3
void imprimirCursosQtdB(Curso *raiz, int qtdB){
    if(raiz){
        imprimirCursosQtdB(raiz->esq, qtdB); 
        if(qtdB == raiz->qtdBCurso){
            imprimirCurso(raiz);
            // if(raiz->disciplinas) imprimirDisciplina(raiz->disciplinas);
        }
        imprimirCursosQtdB(raiz->dir, qtdB);
    }
}

// 4
void imprimirDisciplinasCurso(Curso *raiz, int codC){
    Curso *aux;
    aux = existeCurso(raiz, codC);
    if(aux)
        imprimirDisciplinas(raiz->disciplinas);
}

// 5
void imprimirDiscCurso(Curso *raiz, int codC, int codD){
    Curso *aux;
    aux = existeCurso(raiz, codC);
    if(aux)
        imprimirDisciplinaCod(aux->disciplinas, codD);
}


// 6
void imprimirDiscBloco(Curso *raiz, int codC, int bloco){
    Curso *aux;
    aux = existeCurso(raiz, codC);

    if(aux){
        if(codC == raiz->codC)
            DiscBloco(raiz->disciplinas, bloco);
    }
}

// 6
void DiscBloco(Disciplina *raiz, int bloco){
    if(raiz){
        DiscBloco(raiz->esq, bloco);
        if(raiz->bloco == bloco)
            imprimirDisciplina(raiz);
        DiscBloco(raiz->dir, bloco);
    }
}

// (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código
// do curso e a carga horária devem ser informadas pelo usuário;
void imprimirDiscCursoHorario(Curso *raiz, int codC, int cargaeHor){
    Curso *aux;
    aux = existeCurso(raiz, codC);
    if(aux)
        cargaHorDis(raiz->disciplinas, cargaeHor); 
}

// (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código
// do curso e a carga horária devem ser informadas pelo usuário;
void cargaHorDis(Disciplina *dis, int CargaHor){
    if(dis){
        cargaHorDis(dis->esq, CargaHor);
        if(dis->cargHor == CargaHor)
            imprimirDisciplina(dis);
        cargaHorDis(dis->dir, CargaHor);
    }
}
