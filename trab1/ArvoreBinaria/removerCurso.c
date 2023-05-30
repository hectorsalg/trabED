#include <stdio.h>
#include <stdlib.h>
#include "./headers/curso.h"
#include <string.h>
#include "./headers/removerCurso.h"

void removerCurso(Curso **raiz, int codC) {
    Curso *aux;
    if(raiz) {
        if ((*raiz)->disciplinas != NULL) {
            if ((*raiz)->codC == codC) {
                if (folha(*raiz)) {
                    aux = *raiz;
                    *raiz = NULL;
                } else if (!((*raiz)->dir) || !((*raiz)->esq)) {
                    Curso *endFilho;
                    endFilho = enderecoFilho(*raiz);
                    aux = *raiz;
                    *raiz = endFilho;
                }else{ // dois filhos
                    Curso *aux, *filhoEsq;
                    aux = *raiz;
                    filhoEsq = (*raiz)->esq;
                    maiorFilhoEsq(&((*raiz)->esq), (*raiz)->dir);
                    *raiz = filhoEsq;
                }
                free(aux);
            }
        } else if(codC < (*raiz)->codC)
            removerCurso(&((*raiz)->esq), codC);
        else
            removerCurso(&((*raiz)->dir), codC);
    }
}

void maiorFilhoEsq(Curso **filhoRecebe, Curso *outroFilho){
    if(*filhoRecebe)
        maiorFilhoEsq((&(*filhoRecebe)->dir), outroFilho);
    else
        *filhoRecebe = outroFilho;
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

int alturaArvore(Curso *raiz){
    int he = -1, hd = -1, h;

    if(raiz){
        he = alturaArvore(raiz->esq);
        hd = alturaArvore(raiz->dir);
        if(he > hd)
            h = he + 1;
        else
            h = hd + 1;
        
    } else
        h = -1;
    
    return (h);
}

void removerDisc(Curso **raiz, int codD, int codC) {

}