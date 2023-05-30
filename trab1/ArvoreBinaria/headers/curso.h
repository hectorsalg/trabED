typedef struct Disciplina {
    int codD;
    char nome[50];
    int bloco;
    int cargHor;
    struct Disciplina *esq, *dir;
} Disciplina;

typedef struct Curso {
    int codC;
    char nome[70];
    int qtdBlocos;
    int blocos[2];
    int semana;
    Disciplina *disciplinas;
    struct Curso *esq, *dir;
} Curso;



Curso* existeCurso(Curso *raiz, int codC);



// horária
