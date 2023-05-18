#include <stdio.h>
#include <stdlib.h>
#include "curso.h"

int main(){
    Curso *raiz = criarCurso();

    inserirCurso(&raiz, criarNo(2002, "Sistemas", 8, 10));
    inserirCurso(&raiz, criarNo(2000, "Nutrição", 10, 12));
    imprimirCurso(raiz);
}