#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "curso.h"
#include "inserir.h"
#include "imprimir.h"
#include "remover.h"




int main(){
    
    Curso *raiz, *aux;
    raiz = criarCurso();
    int op, cod, qtdBCurso, semana, bloco, cargaHor, codD;
    char nome[70];

    clock_t inicio, fim;

    double tempo;

    inicio = clock();

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

    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para preencher Arvore: %.5lf milissegundos\n", tempo);
    
    inserirDisciplina(&raiz, 2002, criarNoDisciplina(1, "ED_2", 1, 60));
    inserirDisciplina(&raiz, 2002, criarNoDisciplina(2, "ED_1", 1, 60));
    imprimirDisciplinasCurso(raiz, 2002);
    removerDisc(&raiz, 2002, 1);
    imprimirDisciplinasCurso(raiz, 2002);
    // imprimirCursos(raiz);
    
    do{
        printf("Digite a opcao: ");
        scanf("%d", &op);

        switch (op){
        case 1:
            printf("Digite o nome do curso: ");
            // fgets(nome, sizeof(nome), stdin);
            scanf("%s", nome);
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite a quantidade de blocos do curso: ");
            scanf("%d", &qtdBCurso);
            printf("Digite a quantidade de semanas do curso: ");
            scanf("%d", &semana);

            inserirCurso(&raiz, criarNoCurso(cod, nome, qtdBCurso, semana));
            break;
        case 2:

            printf("Digite o nome da disciplina: ");
            scanf("%s", nome);
            printf("Digite o codigo da disciplina: ");
            scanf("%d", &cod);
            printf("Digite o bloco da disciplina: ");
            scanf("%d", &bloco);
            printf("Digite a carga horaria da disciplina: ");
            scanf("%d", &cargaHor);

            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);

            inserirDisciplina(&raiz, cod, criarNoDisciplina(cod, nome, bloco, cargaHor));
            break;
        case 3:
            // (1) Imprimir a árvore de cursos em ordem crescente pelo código do curso;
            imprimirCursos(raiz);
            break;
        case 4:
            // (2) Imprimir os dados de um curso dado o código do mesmo;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            imprimirDadosCurso(raiz, cod);
            break;
        case 5:
            // (3) Imprimir todos os cursos com a mesma quantidade de blocos, onde o usuário informe a quantidade de blocos;
            printf("Digite a quantidade de bloco do curso: ");
            scanf("%d", &cod);
            imprimirCursosQtdB(raiz, qtdBCurso);
            break;
        case 6:
            // (4) Imprimir a árvore de disciplinas em ordem crescente pelo código das disciplinas dado o código do curso;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            imprimirDisciplinasCurso(raiz, cod);
            break;
        case 7:
            // (5) Imprimir os dados de uma disciplina dado o código dela e do curso ao qual ela pertence;
            
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite o codigo da Disciplina: ");
            scanf("%d", &codD);
            imprimirDiscCurso(raiz, cod, codD);
            break;
        case 8:
            // (6) Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o código do curso;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite o bloco da Disciplina: ");
            scanf("%d", &bloco);
            imprimirDiscBloco(raiz, cod, bloco);
            break;
        case 9:
            // (7) Imprimir todas as disciplinas de um determinado curso com a mesma carga horária, onde o código do curso e a carga horária devem ser informadas pelo usuário;
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite a carga horaria das Disciplinas: ");
            scanf("%d", &cargaHor);
            imprimirDiscCursoHorario(raiz, cod, cargaHor);
            break;
        case 10:
            // (8) Excluir uma disciplina dado o código da disciplina e o código do curso;
            
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            printf("Digite o codigo da Disciplina: ");
            scanf("%d", &codD);

            // aux = existeCurso(raiz, cod);
            // if(aux)
            removerDisc(&raiz, cod, codD);
            break;
        case 11:
            // (9) Excluir um curso dado o código do mesmo, desde que não tenha nenhuma disciplina cadastrada para aquele curso.
            printf("Digite o codigo do curso: ");
            scanf("%d", &cod);
            removerCurso(&raiz, cod);
            break;
        default:
            break;
        }
    }while(op != 0);

    // inserirCurso(&raiz, criarNoCurso(2002, "Sistemas", 8, 10));
    // inserirCurso(&raiz, criarNoCurso(2000, "Nutrição", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(1900, "ADM", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(1950, "Matematica", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(2500, "Medicina", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(2550, "Biologia", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(2400, "Historia", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(2410, "Analise", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(2430, "Direito", 10, 12));
    // inserirCurso(&raiz, criarNoCurso(2450, "Enfermagem", 10, 12));
    imprimirCursos(raiz);
    // Desenho da arvore
    // https://docs.google.com/spreadsheets/d/136U-07lrStLV6qE96hQp1BF0bdz2X90hQRP7Gl8jeCE/edit?usp=sharing

    // aux = existeCurso(raiz,  2002);
    // if(aux) printf("Existe curso\n");
    // else printf("Não foi curso\n");
    // removerCurso(&raiz, 1900);
    // inserirDisciplina(&raiz, 2002,  criarNoDisciplina(1, "ED_2", 1, 60));
    // inserirDisciplina(&raiz, 2002,  criarNoDisciplina(2, "ED_1", 1, 60));
    // inserirDisciplina( &aux->disciplinas, criarNoDisciplina(2, "ED_1", 1, 60));
    // // imprimirCurso(raiz);
    // inserirDisciplina(&aux->disciplinas, criarNoDisciplina(2, "ED_1", 1, 60));
    imprimirCursos(raiz);
    // printf("AAA\n");

    // printf("Altura da arvore: %d\n", alturaArvore(raiz));
    // fim = time(NULL);

    // tempo = difftime(fim, inicio);

    // printf("Tempo: %f\n", tempo);

    return 0;
}