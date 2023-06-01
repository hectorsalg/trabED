#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include "altura.h"
#include "inserirCurso.h"
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
    raiz->altura = 0;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}


void inserirCurso(Curso **raiz, Curso *no){
    if (!(*raiz)){
        (*raiz) = no;
    }else if (no->codC < (**raiz).codC){
        inserirCurso(&((**raiz).esq), no);
    }else if (no->codC > (**raiz).codC){
        inserirCurso(&((**raiz).dir), no);
    }
    balancear(raiz);  
    atualizarAltura((*raiz));  
}


void balancear(Curso **raiz){
    if(*raiz){

        if(fb(*raiz) == 2){
            if(fb((*raiz)->esq) < 0)
                rotacaoEsquerda(&((*raiz)->esq));
            rotacaoDireita(raiz);

        }else if(fb(*raiz) == -2){
            if(fb((*raiz)->dir) > 0)
                rotacaoDireita(&((*raiz)->dir));
            rotacaoEsquerda(raiz);
        }
    }
}

int fb(Curso *no){
    int fator = 0;
    if(no)
        fator = (alturaArvore(no->esq) - alturaArvore(no->dir));
    return fator;
}

void rotacaoEsquerda(Curso **raiz){
    Curso *aux;

    if(!(*raiz)->dir)
        printf("Aqui não tem nada\n");

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);
    (*raiz) = aux;

    atualizarAltura((*raiz)->esq);
    atualizarAltura((*raiz));

}

void rotacaoDireita(Curso **raiz){
    Curso *aux;
    
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    (*raiz) = aux;

    atualizarAltura((*raiz)->dir);
    atualizarAltura((*raiz));

}

int getAltura(Curso *raiz){
    int altura = -1;
    if(raiz)
        altura = raiz->altura;
    return altura;
}

void atualizarAltura(Curso *raiz){
    int alturaEsq, alturaDir;

    alturaEsq = getAltura(raiz->esq);
    alturaDir = getAltura(raiz->dir);

    raiz->altura = (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}
