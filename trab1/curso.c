#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
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
    raiz->qtdBCurso = qtdBCurso;
    raiz->semana = semana;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor){
    Disciplina *raiz;
    raiz = (Disciplina *) malloc(sizeof(Disciplina));
    raiz->codD = codC;
    strcpy(raiz->nome, nome);
    raiz->qtdBDisciplina = qtdBDisciplina;
    raiz->cargHor = cargHor;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirCurso(Curso **raiz, Curso *no){
    if(raiz){
        if(no->codC < (**raiz).codC){
            inserirCurso(&((*raiz)->esq), no);
        }else if(no->codC > (*raiz)->codC){
            inserirCurso(&((*raiz)->dir), no);
        }
    } else *raiz = no;
}

Curso *existeCurso(Curso *raiz, int codC){
    Curso *aux;
    aux = NULL;
    if(raiz){
        if((*raiz).codC == codC){
            aux = raiz;
        }else if(codC < (*raiz).codC) aux = existeCurso((*raiz).esq, codC);
        else aux = existeCurso((*raiz).dir, codC);
    }
    return aux;
}

void inserirDisciplina(Disciplina **raiz, Disciplina *no){
    //fazer uma flag para saber se inseriu
    if(raiz){
        if((*no).codD < (**raiz).codD){
            inserirDisciplina(&((*raiz)->esq), no);
        }else if ((*no).codD > (*raiz)->codD){
            inserirDisciplina(&((*raiz)->dir),  no);
        }
    } else *raiz = no;
}

void imprimirCurso(Curso *raiz){ // InOrder
    if(raiz){
        imprimirCurso(raiz->esq);
        printf("Codigo: %d\nNome: %s\nBlocos do Curso: %d\nSemanas: %d\n\n", raiz->codC, raiz->nome, raiz->qtdBCurso, raiz->semana);
        if(raiz->disciplinas) imprimirDadosDisc(raiz->disciplinas);
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

void imprimirDisciplina(Disciplina *raiz){
    if(raiz){
        printf("CodigoD: %d\nNome Dis: %s\nBlocos da disciplina: %d\nCarga Horaria: %d\n\n", raiz->codD, raiz->nome, raiz->qtdBDisciplina, raiz->cargHor);
    }
}

void imprimirDadosDisc(Disciplina *raiz){
    if(raiz){
        imprimirDadosDisc(raiz->esq);
        imprimirDisciplina(raiz);
        imprimirDadosDisc(raiz->dir);
    }
}

void imprimirDisciplinaCod(Disciplina *raiz, int cod){
    if(raiz){
        if(raiz->codD == cod)
            imprimirDisciplina(raiz);
        else if(cod < raiz->codD)
            imprimirDisciplinaCod(raiz->esq, cod);
        else
            imprimirDisciplinaCod(raiz->dir, cod);
    }
}


void removerCurso(Curso **raiz, int codC) {
    Curso *aux;
    if (*raiz) {
        if ((*raiz)->codC == codC) {
            printf("%d\n", ehfolha(*raiz));
            if (folha(*raiz)) {
                aux = *raiz;
                *raiz = NULL;
            } else if (!((*raiz)->dir) || !((*raiz)->esq)) {
                Curso *endFilho;
                endFilho = enderecoFilho(*raiz);
                aux = *raiz;
                *raiz = endFilho;
            }else{ // dois filhos
                Curso *aux, *filho_esq;
                aux = *raiz;
                filho_esq = (*raiz)->esq;
                esq_filho(&((*raiz)->esq), (*raiz)->dir);
                *raiz = filho_esq;
            }
            free(aux);
        }else if(codC < (*raiz)->codC)
            removerCurso(&((*raiz)->esq), codC);
        else
            removerCurso(&((*raiz)->dir), codC);
    }
}

void esqFilho(Curso **filho_recebe, Curso *filho_outro){
    if(*filho_recebe){
        esqFilho((&(*filho_recebe)->dir), filho_outro);
    }else{
        *filho_recebe = filho_outro;
    }
}

int folha(Curso *raiz) { 
    return !(raiz->esq || raiz->dir);
}

Curso *enderecoFilho(Curso *raiz) {
    Curso *aux;
    if (raiz->dir)
        aux = raiz->dir;
    else 
        aux = raiz->esq;
    return aux;
}

