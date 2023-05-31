void imprimirCurso(Curso *raiz);
void imprimirCursos(Curso *raiz); // imprimir todos os dados do curso
void imprimirDadosCurso(Curso *raiz, int cod); // imprimir somente os códigos
void imprimirCursosQtdB(Curso *raiz, int qtdB); // imprimir quantidade de cursos com mesma quantidade de blocos
void imprimirDiscCurso(Curso *raiz, int codD, int codC);
void imprimirDiscCursoHorario(Curso *raiz, int codC, int cargaHor); // imprimir todas as disciplinas com a mesma carga 
void imprimirDiscBloco(Curso *raiz, int codC, int bloco); // imprimir as disciplinas de um curso de um dado bloco

void DiscBloco(Disciplina *raiz, int bloco);