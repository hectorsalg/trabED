#include <stdio.h>
#include <stdlib.h>
#include "curso.h"

int main(){
    Curso *raiz, *aux;
    raiz = criarCurso();

    inserirCurso(&raiz, criarNoCurso(2002, "Sistemas", 8, 10));
    inserirCurso(&raiz, criarNoCurso(2000, "Nutrição", 10, 12));

    aux = existeCurso(raiz,  2002);
    if(aux) printf("Existe curso\n");
    else printf("Não foi curso\n");

    inserirDisciplina(aux, criarNoDisciplina(1, "ED_2", 1, 60));
    imprimirCurso(raiz);


}