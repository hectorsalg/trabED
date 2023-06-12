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

    {
    inserirCurso(&raiz, criarNoCurso(200, "Ciência da Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(199, "Sistemas de Informação", 7, 10));
    inserirCurso(&raiz, criarNoCurso(198, "Análise e Desenvolvimento de Sistemas", 6, 10));
    inserirCurso(&raiz, criarNoCurso(197, "Redes de Computadores", 5, 10));
    inserirCurso(&raiz, criarNoCurso(196, "Segurança da Informação", 4, 10));
    inserirCurso(&raiz, criarNoCurso(195, "Jogos Digitais", 3, 10));
    inserirCurso(&raiz, criarNoCurso(194, "Design Gráfico", 4, 10));
    inserirCurso(&raiz, criarNoCurso(193, "Design de Interiores", 3, 10));
    inserirCurso(&raiz, criarNoCurso(192, "Design de Moda", 2, 10));
    inserirCurso(&raiz, criarNoCurso(191, "Matemática", 6, 10));
    inserirCurso(&raiz, criarNoCurso(190, "Física", 8, 10));
    inserirCurso(&raiz, criarNoCurso(189, "Química", 4, 10));
    inserirCurso(&raiz, criarNoCurso(188, "Biologia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(187, "História", 3, 10));
    inserirCurso(&raiz, criarNoCurso(186, "Geografia", 2, 10));
    inserirCurso(&raiz, criarNoCurso(185, "Filosofia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(184, "Sociologia", 3, 10));
    inserirCurso(&raiz, criarNoCurso(183, "Psicologia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(182, "Pedagogia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(181, "Letras", 6, 10));
    inserirCurso(&raiz, criarNoCurso(180, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(179, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(178, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(177, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(176, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(175, "Engenharia Elétrica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(174, "Engenharia Mecânica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(173, "Engenharia Química", 8, 10));
    inserirCurso(&raiz, criarNoCurso(172, "Engenharia de Produção", 7, 10));
    inserirCurso(&raiz, criarNoCurso(171, "Engenharia de Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(170, "Ciência da Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(169, "Sistemas de Informação", 7, 10));
    inserirCurso(&raiz, criarNoCurso(168, "Análise e Desenvolvimento de Sistemas", 6, 10));
    inserirCurso(&raiz, criarNoCurso(167, "Redes de Computadores", 5, 10));
    inserirCurso(&raiz, criarNoCurso(166, "Segurança da Informação", 4, 10));
    inserirCurso(&raiz, criarNoCurso(165, "Jogos Digitais", 3, 10));
    inserirCurso(&raiz, criarNoCurso(164, "Design Gráfico", 4, 10));
    inserirCurso(&raiz, criarNoCurso(163, "Design de Interiores", 3, 10));
    inserirCurso(&raiz, criarNoCurso(162, "Design de Moda", 2, 10));

    inserirCurso(&raiz, criarNoCurso(161, "Matemática", 6, 10));
    inserirCurso(&raiz, criarNoCurso(160, "Física", 8, 10));
    inserirCurso(&raiz, criarNoCurso(159, "Química", 4, 10));
    inserirCurso(&raiz, criarNoCurso(158, "Biologia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(157, "História", 3, 10));
    inserirCurso(&raiz, criarNoCurso(156, "Geografia", 2, 10));
    inserirCurso(&raiz, criarNoCurso(155, "Filosofia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(154, "Sociologia", 3, 10));
    inserirCurso(&raiz, criarNoCurso(153, "Psicologia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(152, "Pedagogia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(151, "Letras", 6, 10));
    inserirCurso(&raiz, criarNoCurso(150, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(149, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(148, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(147, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(146, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(145, "Engenharia Elétrica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(144, "Engenharia Mecânica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(143, "Engenharia Química", 8, 10));
    inserirCurso(&raiz, criarNoCurso(142, "Engenharia de Produção", 7, 10));
    inserirCurso(&raiz, criarNoCurso(141, "Engenharia de Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(140, "Ciência da Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(139, "Sistemas de Informação", 7, 10));
    inserirCurso(&raiz, criarNoCurso(138, "Análise e Desenvolvimento de Sistemas", 6, 10));
    inserirCurso(&raiz, criarNoCurso(137, "Redes de Computadores", 5, 10));
    inserirCurso(&raiz, criarNoCurso(136, "Segurança da Informação", 4, 10));
    inserirCurso(&raiz, criarNoCurso(135, "Jogos Digitais", 3, 10));
    inserirCurso(&raiz, criarNoCurso(134, "Design Gráfico", 4, 10));
    inserirCurso(&raiz, criarNoCurso(133, "Design de Interiores", 3, 10));
    inserirCurso(&raiz, criarNoCurso(132, "Design de Moda", 2, 10));


    inserirCurso(&raiz, criarNoCurso(131, "Matemática", 6, 10));
    inserirCurso(&raiz, criarNoCurso(130, "Física", 8, 10));
    inserirCurso(&raiz, criarNoCurso(129, "Química", 4, 10));
    inserirCurso(&raiz, criarNoCurso(128, "Biologia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(127, "História", 3, 10));
    inserirCurso(&raiz, criarNoCurso(126, "Geografia", 2, 10));
    inserirCurso(&raiz, criarNoCurso(125, "Filosofia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(124, "Sociologia", 3, 10));
    inserirCurso(&raiz, criarNoCurso(123, "Psicologia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(122, "Pedagogia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(121, "Letras", 6, 10));
    inserirCurso(&raiz, criarNoCurso(120, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(119, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(118, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(117, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(116, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(115, "Engenharia Elétrica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(114, "Engenharia Mecânica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(113, "Engenharia Química", 8, 10));
    inserirCurso(&raiz, criarNoCurso(112, "Engenharia de Produção", 7, 10));
    inserirCurso(&raiz, criarNoCurso(111, "Engenharia de Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(110, "Ciência da Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(109, "Sistemas de Informação", 7, 10));
    inserirCurso(&raiz, criarNoCurso(108, "Análise e Desenvolvimento de Sistemas", 6, 10));
    inserirCurso(&raiz, criarNoCurso(107, "Redes de Computadores", 5, 10));
    inserirCurso(&raiz, criarNoCurso(106, "Segurança da Informação", 4, 10));
    inserirCurso(&raiz, criarNoCurso(105, "Jogos Digitais", 3, 10));
    inserirCurso(&raiz, criarNoCurso(104, "Design Gráfico", 4, 10));
    inserirCurso(&raiz, criarNoCurso(103, "Design de Interiores", 3, 10));
    inserirCurso(&raiz, criarNoCurso(102, "Design de Moda", 2, 10));

    inserirCurso(&raiz, criarNoCurso(101, "Arquitetura", 8, 10));
    inserirCurso(&raiz, criarNoCurso(100, "Engenharia Ambiental", 7, 10));
    inserirCurso(&raiz, criarNoCurso(99, "Engenharia de Alimentos", 6, 10));
    inserirCurso(&raiz, criarNoCurso(98, "Medicina", 10, 10));
    inserirCurso(&raiz, criarNoCurso(97, "Enfermagem", 9, 10));
    inserirCurso(&raiz, criarNoCurso(96, "Farmácia", 8, 10));
    inserirCurso(&raiz, criarNoCurso(95, "Nutrição", 7, 10));
    inserirCurso(&raiz, criarNoCurso(94, "Odontologia", 9, 10));
    inserirCurso(&raiz, criarNoCurso(93, "Fisioterapia", 8, 10));
    inserirCurso(&raiz, criarNoCurso(92, "Psicologia", 8, 10));
    inserirCurso(&raiz, criarNoCurso(91, "Terapia Ocupacional", 7, 10));
    inserirCurso(&raiz, criarNoCurso(90, "Educação Física", 6, 10));
    inserirCurso(&raiz, criarNoCurso(89, "Artes Cênicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(88, "Música", 6, 10));
    inserirCurso(&raiz, criarNoCurso(87, "Dança", 4, 10));
    inserirCurso(&raiz, criarNoCurso(86, "Publicidade e Propaganda", 7, 10));
    inserirCurso(&raiz, criarNoCurso(85, "Jornalismo", 6, 10));
    inserirCurso(&raiz, criarNoCurso(84, "Relações Públicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(83, "Design", 6, 10));
    inserirCurso(&raiz, criarNoCurso(82, "Comunicação Social", 6, 10));
    inserirCurso(&raiz, criarNoCurso(81, "Ciências Sociais", 5, 10));
    inserirCurso(&raiz, criarNoCurso(80, "Serviço Social", 5, 10));
    inserirCurso(&raiz, criarNoCurso(79, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(78, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(77, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(76, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(75, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(74, "Engenharia Elétrica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(73, "Engenharia Mecânica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(72, "Engenharia Química", 8, 10));
    inserirCurso(&raiz, criarNoCurso(71, "Engenharia de Produção", 8, 10));
    inserirCurso(&raiz, criarNoCurso(70, "Engenharia de Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(69, "Ciência da Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(68, "Sistemas de Informação", 7, 10));
    inserirCurso(&raiz, criarNoCurso(67, "Matemática", 7, 10));
    inserirCurso(&raiz, criarNoCurso(66, "Física", 7, 10));
    inserirCurso(&raiz, criarNoCurso(65, "Química", 7, 10));
    inserirCurso(&raiz, criarNoCurso(64, "Biologia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(63, "Geografia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(62, "História", 6, 10));
    inserirCurso(&raiz, criarNoCurso(61, "Filosofia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(60, "Letras", 5, 10));
    inserirCurso(&raiz, criarNoCurso(59, "Pedagogia", 5, 10));


    inserirCurso(&raiz, criarNoCurso(58, "Psicologia", 8, 10));
    inserirCurso(&raiz, criarNoCurso(57, "Terapia Ocupacional", 7, 10));
    inserirCurso(&raiz, criarNoCurso(56, "Educação Física", 6, 10));
    inserirCurso(&raiz, criarNoCurso(55, "Artes Cênicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(54, "Música", 6, 10));
    inserirCurso(&raiz, criarNoCurso(53, "Dança", 4, 10));
    inserirCurso(&raiz, criarNoCurso(52, "Publicidade e Propaganda", 7, 10));
    inserirCurso(&raiz, criarNoCurso(51, "Jornalismo", 6, 10));
    inserirCurso(&raiz, criarNoCurso(50, "Relações Públicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(49, "Design", 6, 10));
    inserirCurso(&raiz, criarNoCurso(48, "Comunicação Social", 6, 10));
    inserirCurso(&raiz, criarNoCurso(47, "Ciências Sociais", 5, 10));
    inserirCurso(&raiz, criarNoCurso(46, "Serviço Social", 5, 10));
    inserirCurso(&raiz, criarNoCurso(45, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(44, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(43, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(42, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(41, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(40, "Engenharia Elétrica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(39, "Engenharia Mecânica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(38, "Engenharia Química", 8, 10));
    inserirCurso(&raiz, criarNoCurso(37, "Engenharia de Produção", 8, 10));
    inserirCurso(&raiz, criarNoCurso(36, "Engenharia de Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(35, "Ciência da Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(34, "Sistemas de Informação", 7, 10));
    inserirCurso(&raiz, criarNoCurso(33, "Matemática", 7, 10));
    inserirCurso(&raiz, criarNoCurso(32, "Física", 7, 10));
    inserirCurso(&raiz, criarNoCurso(31, "Química", 7, 10));
    inserirCurso(&raiz, criarNoCurso(30, "Biologia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(29, "Geografia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(28, "História", 6, 10));
    inserirCurso(&raiz, criarNoCurso(27, "Filosofia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(26, "Letras", 5, 10));
    inserirCurso(&raiz, criarNoCurso(25, "Pedagogia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(24, "Psicologia", 8, 10));
    inserirCurso(&raiz, criarNoCurso(23, "Terapia Ocupacional", 7, 10));
    inserirCurso(&raiz, criarNoCurso(22, "Educação Física", 6, 10));
    inserirCurso(&raiz, criarNoCurso(21, "Artes Cênicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(20, "Música", 6, 10));
    inserirCurso(&raiz, criarNoCurso(19, "Dança", 4, 10));
    inserirCurso(&raiz, criarNoCurso(18, "Publicidade e Propaganda", 7, 10));
    inserirCurso(&raiz, criarNoCurso(17, "Jornalismo", 6, 10));
    inserirCurso(&raiz, criarNoCurso(16, "Relações Públicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(15, "Design", 6, 10));
    inserirCurso(&raiz, criarNoCurso(14, "Comunicação Social", 6, 10));
    inserirCurso(&raiz, criarNoCurso(13, "Ciências Sociais", 5, 10));
    inserirCurso(&raiz, criarNoCurso(12, "Serviço Social", 5, 10));
    inserirCurso(&raiz, criarNoCurso(11, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(10, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(9, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(8, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(7, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(6, "Engenharia Elétrica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(5, "Engenharia Mecânica", 9, 10));
    inserirCurso(&raiz, criarNoCurso(4, "Engenharia Química", 8, 10));
    inserirCurso(&raiz, criarNoCurso(3, "Engenharia de Produção", 8, 10));
    inserirCurso(&raiz, criarNoCurso(2, "Engenharia de Computação", 8, 10));
    inserirCurso(&raiz, criarNoCurso(1, "Ciência da Computação", 8, 10));
}
    
    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para preencher Arvore: %.5lf milissegundos\n", tempo);



    inicio = clock();

    aux = existeCurso(raiz, 1);

    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para busca Arvore: %.5lf milissegundos\n", tempo);

    removerCurso(&raiz, 6);
    
    liberarArvoreCurso(&raiz);
    imprimirCursos(raiz);
    return 0;
}