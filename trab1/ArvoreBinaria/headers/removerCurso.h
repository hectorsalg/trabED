void removerDisc(Curso **raiz, int codD, int codC); // remover disciplina do curso por código de ambos
void removerCurso(Curso **raiz, int codC); // remover curso (somente se estiver sem disciplinas)

int folha(Curso *raiz);
Curso *enderecoFilho(Curso *raiz);

void maiorFilhoEsq(Curso **filhoRecebe, Curso *outroFilho);

int alturaArvore(Curso *raiz);