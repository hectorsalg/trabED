Curso *criarCurso();
void inserirCurso(Curso **raiz, Curso *no);
Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana); 

Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor);
void inserirDisciplina(Curso **curso, int codC, Disciplina *no);

void auxiliarInserirDisc(Disciplina **raiz, Disciplina *no);