#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include "altura.h"
#include "inserirCurso.h"
#include <string.h>

// ------------------------------- Cursos -------------------------------
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

// ------------------------------- Disciplinas -------------------------------

Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor){
    Disciplina *raiz;
    raiz = (Disciplina *) malloc(sizeof(Disciplina));
    raiz->codD = codC;
    strcpy(raiz->nome, nome);
    raiz->bloco = qtdBDisciplina;
    raiz->cargHor = cargHor;
    raiz->altura = 0;
    raiz->esq = raiz->dir = NULL;
    return raiz;
}

void inserirDisciplina(Curso **curso, int codC, Disciplina **raiz, Disciplina *no){
    //fazer uma flag para saber se inseriu
    Curso *aux;
    aux = existeCurso((*curso), codC);
    if(aux)
        if(aux->qtdBCurso > no->bloco && no->cargHor % (*curso)->semana == 0)
            auxInserirDis(raiz, no);        
}

void auxInserirDis(Disciplina **raiz, Disciplina *no){
    if(!(*raiz)){
        *raiz = no;
    }else if((*no).codD < (**raiz).codD){
        auxInserirDis(&((*raiz)->esq), no);
    }else{
        auxInserirDis(&((*raiz)->dir), no);
    }
    balancearDis(raiz);   
    atualizarAlturaDis((*raiz));
}

int getAlturaDis(Disciplina *raiz){
    int altura = -1;
    if(raiz)
        altura = raiz->altura;
    return altura;
}

void atualizarAlturaDis(Disciplina *raiz){
    int h_esq, h_dir, altura;
    h_esq = getAltura(raiz->esq);
    h_dir = getAltura(raiz->dir);

    raiz->altura = (h_esq > h_dir ? h_esq : h_dir) + 1;
}

int fbDis(Disciplina *raiz){
    int fator = 0;
    if(raiz)
        fator = (getAlturaDis(raiz->esq) - getAlturaDis(raiz->dir));
    return fator;
}

void balancearDis(Disciplina **raiz){
    if(*raiz){
        int fator = fbDis(*raiz);
        if(fator == 2){
            if(fbDis((*raiz)->esq) < 0)
                rotacaoEsqDis(&((*raiz)->esq));
            rotacaoDirDis(raiz);
        }else if(fator == -2){
            if(fbDis((*raiz)->dir) > 0)
                rotacaoDirDis(&((*raiz)->dir));
            rotacaoEsqDis(raiz);
        }
    }
}

void rotacaoEsqDis(Disciplina **raiz){
    Disciplina *aux;

    aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = *raiz;
    (*raiz) = aux;

    atualizarAlturaDis((*raiz)->esq);
    atualizarAlturaDis((*raiz));
}

void rotacaoDirDis(Disciplina **raiz){
    Curso *aux;
    aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    (*raiz) = aux;

    atualizarAlturaDis((*raiz)->esq);
    atualizarAlturaDis((*raiz));
}
