
void removerCurso(Curso **raiz, int codC); // remover curso (somente se estiver sem disciplinas)
int folha(Curso *raiz);
Curso *enderecoFilho(Curso *raiz);
void maiorFilhoEsq(Curso **filhoRecebe, Curso *outroFilho);
int alturaArvore(Curso *raiz);



void removerDisc(Disciplina **raiz, int codD); // remover disciplina do curso por código de ambos
int folhaDis(Disciplina *raiz);
Disciplina *enderecoFilhoDis(Disciplina *raiz);
void maiorFilhoEsqDis(Disciplina **filhoRecebe, Disciplina *outroFilho);