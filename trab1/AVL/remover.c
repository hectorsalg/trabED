#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include "balancear.h"
#include "remover.h"

// ------------------------------------ Curso ------------------------------------

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
                    maiorFilhoEsq(&((*raiz)->esq), (*raiz)->dir);
                    *raiz = filho_esq;
                }
                free(aux);
            }
        }else if(codC < (*raiz)->codC)
            removerCurso(&((*raiz)->esq), codC);
        else
            removerCurso(&((*raiz)->dir), codC);
        balancear(raiz);
        atualizarAltura((*raiz));
    }
}

void maiorFilhoEsq(Curso **filho_recebe, Curso *filho_outro){
    if(*filho_recebe){
        maiorFilhoEsq((&(*filho_recebe)->dir), filho_outro);
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

void liberarArvoreCurso(Curso **raiz){
    if(*raiz){
        liberarArvoreCurso(&((*raiz)->esq));
        liberarArvoreCurso(&((*raiz)->dir));
        removerCurso(raiz, (*raiz)->codC);
    }
}

// --------------------------------- Disciplinas --------------------------------

void removerDisc(Curso **raiz, int codC, int codD){
    Curso *aux;
    aux = existeCurso((*raiz), codC);
    if(aux)
        auxRemoverDisc(&aux->disciplinas, codD);
}

void auxRemoverDisc(Disciplina **raiz, int codD){

    if(*raiz){
        if((*raiz)->codD == codD){
            Disciplina *aux, *endFilho;
            aux = (*raiz);
            if(folhaDis((*raiz)))
                (*raiz) = NULL;
            else if(endFilho = enderecoFilhoDis((*raiz)))
                (*raiz) = endFilho;
            else{
                endFilho = (*raiz)->esq;
                maiorFilhoEsqDis(&((*raiz)->esq), (*raiz)->dir);
                (*raiz) = endFilho;
            }
            free(aux);
        }else if(codD < (*raiz)->codD)
            auxRemoverDisc(&((*raiz)->esq), codD);
        else if(codD > (*raiz)->codD)
            auxRemoverDisc(&((*raiz)->dir), codD);
        balancearDis(raiz);
        atualizarAlturaDis(*raiz);
    }
}

int folhaDis(Disciplina *raiz) { 
    return !(raiz->esq || raiz->dir);
}

Disciplina *enderecoFilhoDis(Disciplina *raiz) {
    Disciplina *aux;
    if(!(raiz->dir) || !(raiz->esq)){
        if (raiz->dir)
            aux = raiz->dir;
        else if(raiz->esq)
            aux = raiz->esq;
    }else aux = NULL;

    return aux;
}

void maiorFilhoEsqDis(Disciplina **filhoRecebe, Disciplina *outroFilho){
    if(!(*filhoRecebe))
        (*filhoRecebe) = outroFilho;
    maiorFilhoEsqDis(&((*filhoRecebe)->dir), outroFilho);
}