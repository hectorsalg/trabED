void removerDisc(Curso **raiz, int codD, int codC); // remover disciplina do curso por código de ambos
void removerCurso(Curso **raiz, int codC); // remover curso (somente se estiver sem disciplinas)

int ehfolha(Curso *raiz);
Curso *enderecoFilho(Curso *raiz);

void maiorFilhoEsq(Curso **filho_recebe, Curso *filho_outro);
void liberarArvoreCurso(Curso **raiz);

void removerDisc(Curso **raiz, int codC, int codD); // remover disciplina do curso por código de ambos
void auxRemoverDisc(Disciplina **raiz, int codD);
int folhaDis(Disciplina *raiz);
Disciplina *enderecoFilhoDis(Disciplina *raiz);
void maiorFilhoEsqDis(Disciplina **filhoRecebe, Disciplina *outroFilho);
