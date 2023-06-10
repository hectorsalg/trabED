#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"
#include "remover.h"

// --------------------------------Cursos --------------------------------

void removerCurso(Curso **raiz, int codC) {
    if(*raiz) {
        if (!(*raiz)->disciplinas) {
            if ((*raiz)->codC == codC) {
                Curso *aux, *endFilho;
                aux = *raiz;
                if (folha(*raiz)) {
                    *raiz = NULL;
                } else if (!((*raiz)->dir) || !((*raiz)->esq)) {
                    endFilho = enderecoFilho(*raiz);
                    *raiz = endFilho;
                }else{ // dois filhos
                    endFilho = (*raiz)->esq;
                    maiorFilhoEsq(&((*raiz)->esq), (*raiz)->dir);
                    *raiz = endFilho;
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

void liberarArvoreCurso(Curso **raiz){
    if(*raiz){
        liberarArvoreCurso(&((*raiz)->esq));
        liberarArvoreCurso(&((*raiz)->dir));
        removerCurso(raiz, (*raiz)->codC);
    }
}

// --------------------------------Disciplinas --------------------------------

void removerDisc(Curso **raiz, int codC, int codD){
    Curso *aux;
    aux = existeCurso((*raiz), codC);
    if(aux)
        auxRemoverDisc(&aux->disciplinas, codD);
}

void auxRemoverDisc(Disciplina **raiz, int codD){

    if(raiz){
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