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
    raiz = (Curso *)malloc(sizeof(Curso));
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
}

void balancear(Curso **raiz){
    if(*raiz){

        if(fb(*raiz) == 2){
            if(fb((*raiz)->esq) < 0)
                rotacaoEsqueda(&((*raiz)->dir));
            rotacaoDireita(raiz);

        }else if(fb(*raiz) == -2){
            if(fb((*raiz)->dir) > 0)
                rotacaoDireita(&((*raiz)->esq));
            rotacaoEsqueda(raiz);
        }
    }

}

int fb(Curso *no){
    return (alturaArvore(no->esq) - alturaArvore(no->dir));
}

void rotacaoEsqueda(Curso **raiz){
    Curso *filhoDireito, *filhoDofilho_direito;
    
    filhoDireito = (*raiz)->dir;
    filhoDofilho_direito = filhoDireito->esq;

    filhoDireito->esq = (*raiz);
    (*raiz)->dir = filhoDofilho_direito;

    (*raiz) = filhoDireito;

    (*raiz)->altura = alturaArvore(*raiz);
    if(filhoDofilho_direito)
        filhoDofilho_direito->altura = alturaArvore(filhoDofilho_direito); 
}

void rotacaoDireita(Curso **raiz){
    Curso *filhoEsquerdo, *filhoDofilho_Esquerdo;
    
    filhoEsquerdo = (*raiz)->esq;
    filhoDofilho_Esquerdo = filhoEsquerdo->esq;

    filhoEsquerdo->dir = (*raiz);
    (*raiz)->esq = filhoDofilho_Esquerdo;

    (*raiz) = filhoEsquerdo;

    (*raiz)->altura = alturaArvore(*raiz);
    
    if (filhoDofilho_Esquerdo)
        filhoDofilho_Esquerdo->altura = alturaArvore(filhoDofilho_Esquerdo); 
}
