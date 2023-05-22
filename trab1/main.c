#include <stdio.h>
#include <stdlib.h>
#include "curso.h"

int main(){
    Curso *raiz, *aux;
    raiz = criarCurso();

    inserirCurso(&raiz, criarNoCurso(2002, "Sistemas", 8, 10));
    inserirCurso(&raiz, criarNoCurso(2000, "Nutrição", 10, 12));
    inserirCurso(&raiz, criarNoCurso(1900, "ADM", 10, 12));
    inserirCurso(&raiz, criarNoCurso(1950, "Matematica", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2500, "Medicina", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2550, "Biologia", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2400, "Historia", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2410, "Analise", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2430, "Direito", 10, 12));
    inserirCurso(&raiz, criarNoCurso(2450, "Enfermagem", 10, 12));

    // Desenho da arvore
    // https://docs.google.com/spreadsheets/d/136U-07lrStLV6qE96hQp1BF0bdz2X90hQRP7Gl8jeCE/edit?usp=sharing

    aux = existeCurso(raiz,  2002);
    if(aux) printf("Existe curso\n");
    else printf("Não foi curso\n");
    removerCurso(&raiz, 2002);
    //inserirDisciplina(aux, criarNoDisciplina(1, "ED_2", 1, 60));
    imprimirCurso(raiz);
    printf("AAA\n");


}