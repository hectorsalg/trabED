Curso *criarCurso();
void inserirCurso(Curso **raiz, Curso *no);
Curso *criarNoCurso(int codC, char nome[], int qtdBCurso, int semana); 
int fb(Curso *no);

void balancear(Curso **raiz);
int fb(Curso *no);
void rotacaoEsquerda(Curso **raiz);
void rotacaoDireita(Curso **raiz);


int getAltura(Curso *raiz);
void atualizarAltura(Curso *raiz);

Disciplina *criarNoDisciplina(int codC, char nome[], int qtdBDisciplina, int cargHor);
void inserirDisciplina(Curso **curso, int codC, Disciplina **raiz, Disciplina *no);
void auxInserirDis(Disciplina **raiz, Disciplina *no);
void balancearDis(Disciplina **raiz);
int fbDis(Disciplina *raiz);
int getAlturaDis(Disciplina *raiz);
void atualizarAlturaDis(Disciplina *raiz);
void rotacaoEsqDis(Disciplina **raiz);
void rotacaoDirDis(Disciplina **raiz);