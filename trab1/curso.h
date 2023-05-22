typedef struct Disciplina {
    int codD;
    char nome[50];
    int qtdBDisciplina;
    int cargHor;
    struct Disciplina *esq, *dir;
} Disciplina;

typedef struct Curso {
    int codC;
    char nome[70];
    int qtdBCurso;
    int semana;
    Disciplina *disciplinas;
    struct Curso *esq, *dir;
} Curso;

Curso *criarCurso();
void inserirCurso(Curso **raiz, Curso *no);
Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana); 

Curso* existeCurso(Curso *raiz, int codC);
Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor);
void inserirDisciplina(Curso *raiz, Disciplina *no);
void imprimirDisciplina(Disciplina *raiz);

void imprimirCurso(Curso *raiz); // imprimir todos os dados do curso
void imprimirCodCurso(Curso *raiz, int cod); // imprimir somente os códigos
void imprimirCursosQtdB(Curso *raiz, int qtdB); // imprimir quantidade de cursos com mesma quantidade de blocos
void imprimirArvDisc(Curso *raiz); // imprimir árvore da disciplina em ordem crescente (In-ordem)
void imprimirDadosDisc(Disciplina *raiz); // imprimir todos os dados da disciplina
void imprimirDiscBloco(Curso *raiz, int codC, int bloco); // imprimir as disciplinas de um curso de um dado bloco
void imprimirDiscCurso(Curso *raiz, int codC, int cargaHor); // imprimir todas as disciplinas com a mesma carga horária
void removerDisc(Curso **raiz, int codD, int codC); // remover disciplina do curso por código de ambos
void removerCurso(Curso **raiz, int codC); // remover curso (somente se estiver sem disciplinas)

int ehfolha(Curso *raiz);
Curso *enderecoFilho(Curso *raiz);

void esq_filh(Curso **filho_recebe, Curso *filho_outro);