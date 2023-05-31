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
    (*raiz)->altura = alturaArvore(*raiz);   
}


void balancear(Curso **raiz){
    if(*raiz){

        if(fb(*raiz) == 2){
            if(fb((*raiz)->esq) < 0)
                rotacaoEsquerda(&((*raiz)->dir));
            rotacaoDireita(raiz);

        }else if(fb(*raiz) == -2){
            if(fb((*raiz)->dir) > 0)
                rotacaoDireita(&((*raiz)->esq));
            rotacaoEsquerda(raiz);
        }
    }

}

int fb(Curso *no){
    return (alturaArvore(no->esq) - alturaArvore(no->dir));
}

void rotacaoEsquerda(Curso **raiz){
    Curso *aux;
    

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);
    (*raiz) = aux;

    (*raiz)->altura = alturaArvore(raiz);
    (*raiz)->esq->altura = alturaArvore((*raiz)->esq);

}

void rotacaoDireita(Curso **raiz){
    Curso *aux;
    
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    (*raiz) = aux;

    (*raiz)->altura = alturaArvore(raiz);
    (*raiz)->dir->altura = alturaArvore((*raiz)->dir);
}
