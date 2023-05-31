#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include <string.h>
#include "removerCurso.h"

void removerCurso(Curso **raiz, int codC) {
    if (*raiz) {
        if ((*raiz)->codC == codC) {
            if(!(*raiz)->disciplinas){
                Curso *aux;
                aux = *raiz;
                if (ehfolha(*raiz)) {
                    *raiz = NULL;
                } else if (!((*raiz)->dir) || !((*raiz)->esq)) {
                    Curso *endFilho;
                    endFilho = enderecoFilho(*raiz);
                    *raiz = endFilho;
                }else{ // dois filhos
                    Curso *filho_esq;
                    filho_esq = (*raiz)->esq;
                    esq_filh(&((*raiz)->esq), (*raiz)->dir);
                    *raiz = filho_esq;
                }
                free(aux);
            }
        }else if(codC < (*raiz)->codC)
            removerCurso(&((*raiz)->esq), codC);
        else
            removerCurso(&((*raiz)->dir), codC);
    }
}

void esq_filh(Curso **filho_recebe, Curso *filho_outro){
    if(*filho_recebe){
        esq_filh((&(*filho_recebe)->dir), filho_outro);
    }else{
        *filho_recebe = filho_outro;
    }
}

int ehfolha(Curso *raiz) { 
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

