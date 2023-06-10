#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Avl.h"
#include "balancear.h"
#include "inserir.h"
#include "imprimir.h"
#include "remover.h"


int main(){
    Curso *raiz, *aux;
    raiz = NULL;

    clock_t inicio, fim;

    double tempo;

    inicio = clock();

    inserirCurso(&raiz, criarNoCurso(1, "Matemática", 6, 10));
    inserirCurso(&raiz, criarNoCurso(2, "Física", 8, 10));
    inserirCurso(&raiz, criarNoCurso(3, "Química", 4, 10));
    inserirCurso(&raiz, criarNoCurso(4, "Biologia", 6, 10));
    inserirCurso(&raiz, criarNoCurso(5, "História", 3, 10));
    inserirCurso(&raiz, criarNoCurso(6, "Geografia", 2, 10));
    inserirCurso(&raiz, criarNoCurso(7, "Filosofia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(8, "Sociologia", 3, 10));
    inserirCurso(&raiz, criarNoCurso(9, "Psicologia", 5, 10));
    inserirCurso(&raiz, criarNoCurso(10, "Pedagogia", 4, 10));
    inserirCurso(&raiz, criarNoCurso(11, "Letras", 6, 10));
    inserirCurso(&raiz, criarNoCurso(12, "Direito", 10, 10));
    inserirCurso(&raiz, criarNoCurso(13, "Administração", 8, 10));
    inserirCurso(&raiz, criarNoCurso(14, "Economia", 7, 10));
    inserirCurso(&raiz, criarNoCurso(15, "Contabilidade", 6, 10));
    inserirCurso(&raiz, criarNoCurso(16, "Engenharia Civil", 10, 10));
    inserirCurso(&raiz, criarNoCurso(17, "Engenharia Elétrica", 9 ,10));
    inserirCurso(&raiz, criarNoCurso(18, "Engenharia Mecânica", 9 ,10));
    inserirCurso(&raiz, criarNoCurso(19, "Engenharia Química" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(20, "Engenharia de Produção" ,7 ,10));
    inserirCurso(&raiz, criarNoCurso(21, "Engenharia de Computação" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(22, "Ciência da Computação" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(23, "Sistemas de Informação" ,7 ,10));
    inserirCurso(&raiz, criarNoCurso(24, "Análise e Desenvolvimento de Sistemas" ,6 ,10));
    inserirCurso(&raiz, criarNoCurso(25, "Redes de Computadores" ,5 ,10));
    inserirCurso(&raiz, criarNoCurso(26, "Segurança da Informação" ,4 ,10));
    inserirCurso(&raiz, criarNoCurso(27, "Jogos Digitais", 3 ,10));
    inserirCurso(&raiz, criarNoCurso(28, "Design Gráfico", 4,10));
    inserirCurso(&raiz, criarNoCurso(29, "Design de Interiores" ,3 ,10 ));
    inserirCurso(&raiz, criarNoCurso(30, "Design de Moda" ,2 ,10 ));
    inserirCurso(&raiz, criarNoCurso(31, "Arquitetura e Urbanismo" ,10 ,10));
    inserirCurso(&raiz, criarNoCurso(32, "Artes Visuais" ,4 ,10));
    inserirCurso(&raiz, criarNoCurso(33, "Música" ,3, 10 ));
    inserirCurso(&raiz, criarNoCurso(34, "Teatro" ,2, 10 ));
    inserirCurso(&raiz, criarNoCurso(35, "Dança" , 2, 10));
    inserirCurso(&raiz, criarNoCurso(36, "Educação Física" ,6 ,10));
    inserirCurso(&raiz, criarNoCurso(37, "Fisioterapia" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(38, "Enfermagem" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(39, "Medicina" ,10 ,10));
    inserirCurso(&raiz, criarNoCurso(40, "Odontologia" ,9 ,10));
    inserirCurso(&raiz, criarNoCurso(41, "Farmácia" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(42, "Jornalismo", 5, 10));
    inserirCurso(&raiz, criarNoCurso(43, "Nutrição" ,6 ,10));
    inserirCurso(&raiz, criarNoCurso(44, "Gastronomia" ,4 ,10));
    inserirCurso(&raiz, criarNoCurso(45, "Turismo" ,4 ,10));
    inserirCurso(&raiz, criarNoCurso(46, "Hotelaria" ,3 ,10 ));
    inserirCurso(&raiz, criarNoCurso(47, "Eventos" ,3,10 ));
    inserirCurso(&raiz, criarNoCurso(48, "Relações Internacionais", 6, 10));
    inserirCurso(&raiz, criarNoCurso(49, "Relações Públicas", 5, 10));
    inserirCurso(&raiz, criarNoCurso(50, "Publicidade e Propaganda", 4, 10));
    inserirCurso(&raiz, criarNoCurso(51, "C1", 6, 10));
    inserirCurso(&raiz, criarNoCurso(52, "C2", 8, 10));
    inserirCurso(&raiz, criarNoCurso(53, "C3", 4, 10));
    inserirCurso(&raiz, criarNoCurso(54, "C4", 6, 10));
    inserirCurso(&raiz, criarNoCurso(55, "C5", 3, 10));
    inserirCurso(&raiz, criarNoCurso(56, "C6", 2, 10));
    inserirCurso(&raiz, criarNoCurso(57, "C7", 4, 10));
    inserirCurso(&raiz, criarNoCurso(58, "C8", 3, 10));
    inserirCurso(&raiz, criarNoCurso(59, "C9", 5, 10));
    inserirCurso(&raiz, criarNoCurso(60, "C10", 4, 10));
    inserirCurso(&raiz, criarNoCurso(61, "C11", 6, 10));
    inserirCurso(&raiz, criarNoCurso(62, "C12", 10, 10));
    inserirCurso(&raiz, criarNoCurso(63, "C13", 8, 10));
    inserirCurso(&raiz, criarNoCurso(64, "C14", 7, 10));
    inserirCurso(&raiz, criarNoCurso(65, "C15", 6, 10));
    inserirCurso(&raiz, criarNoCurso(66, "C16", 10, 10));
    inserirCurso(&raiz, criarNoCurso(67, "C17", 9 ,10));
    inserirCurso(&raiz, criarNoCurso(68, "C18", 9 ,10));
    inserirCurso(&raiz ,criarNoCurso(69, "C19" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(70, "C20" ,7 ,10));
    inserirCurso(&raiz ,criarNoCurso(71, "C21" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(72, "C22" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(73, "C23" ,7 ,10));
    inserirCurso(&raiz ,criarNoCurso(74, "C24" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(75, "C25" ,5 ,10));
    inserirCurso(&raiz ,criarNoCurso(76, "C26" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(77, "C27", 3 ,10));
    inserirCurso(&raiz ,criarNoCurso(78, "C28", 4,10));
    inserirCurso(&raiz ,criarNoCurso(79, "C29" ,3 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(80, "C30" ,2 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(81, "C31" ,10 ,10));
    inserirCurso(&raiz ,criarNoCurso(82, "C32" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(83, "C33" ,3, 10 ));
    inserirCurso(&raiz ,criarNoCurso(84, "C34" ,2, 10 ));
    inserirCurso(&raiz ,criarNoCurso(85, "C35" , 2, 10));
    inserirCurso(&raiz ,criarNoCurso(86, "C36" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(87, "C37" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(88, "C38" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(89, "C39" ,10 ,10));
    inserirCurso(&raiz ,criarNoCurso(90, "C40" ,9 ,10));
    inserirCurso(&raiz ,criarNoCurso(91, "C41" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(92, "C42" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(93, "C43" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(94, "C44" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(95, "C45" ,3 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(96, "C46" ,3,10 ));
    inserirCurso(&raiz, criarNoCurso(97, "C47", 6, 10));
    inserirCurso(&raiz, criarNoCurso(98, "C48", 5, 10));
    inserirCurso(&raiz, criarNoCurso(99, "C49", 5, 10));
    inserirCurso(&raiz, criarNoCurso(100, "C50", 6, 10));
    
    inserirCurso(&raiz, criarNoCurso(101, "C51", 8, 10));
    inserirCurso(&raiz, criarNoCurso(102, "C52", 4, 10));
    inserirCurso(&raiz, criarNoCurso(103, "C53", 6, 10));
    inserirCurso(&raiz, criarNoCurso(104, "C54", 3, 10));
    inserirCurso(&raiz, criarNoCurso(105, "C55", 2, 10));
    inserirCurso(&raiz, criarNoCurso(106, "C56", 4, 10));
    inserirCurso(&raiz, criarNoCurso(107, "C57", 3, 10));
    inserirCurso(&raiz, criarNoCurso(108, "C58", 5, 10));
    inserirCurso(&raiz, criarNoCurso(109, "C59", 4, 10));
    inserirCurso(&raiz, criarNoCurso(110, "C60", 6, 10));
    inserirCurso(&raiz, criarNoCurso(111, "C61", 6, 10));
    inserirCurso(&raiz, criarNoCurso(112, "C62", 10, 10));
    inserirCurso(&raiz, criarNoCurso(113, "C63", 8, 10));
    inserirCurso(&raiz, criarNoCurso(114, "C64", 7, 10));
    inserirCurso(&raiz, criarNoCurso(115, "C65", 6, 10));
    inserirCurso(&raiz, criarNoCurso(116, "C66", 10, 10));
    inserirCurso(&raiz, criarNoCurso(117, "C67", 9 ,10));
    inserirCurso(&raiz, criarNoCurso(118, "C68", 9 ,10));
    inserirCurso(&raiz ,criarNoCurso(119, "C69" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(120, "C70" ,7 ,10));
    inserirCurso(&raiz ,criarNoCurso(121, "C71" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(122, "C72" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(123, "C73" ,7 ,10));
    inserirCurso(&raiz ,criarNoCurso(124, "C74" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(125, "C75" ,5 ,10));
    inserirCurso(&raiz ,criarNoCurso(126, "C76" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(127, "C77", 3 ,10));
    inserirCurso(&raiz ,criarNoCurso(128, "C78", 4,10));
    inserirCurso(&raiz ,criarNoCurso(129, "C79" ,3 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(130, "C80" ,2 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(131, "C81" ,10 ,10));
    inserirCurso(&raiz ,criarNoCurso(132, "C82" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(133, "C83" ,3, 10 ));
    inserirCurso(&raiz ,criarNoCurso(134, "C84" ,2, 10 ));
    inserirCurso(&raiz ,criarNoCurso(135, "C85" , 2, 10));
    inserirCurso(&raiz ,criarNoCurso(136, "C86" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(137, "C87" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(138, "C88" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(139, "C89" ,10 ,10));
    inserirCurso(&raiz ,criarNoCurso(140, "C90" ,9 ,10));
    inserirCurso(&raiz ,criarNoCurso(141, "C91" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(142, "C92" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(143, "C93" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(144, "C94" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(145, "C95" ,3 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(146, "C96" ,3,10 ));
    inserirCurso(&raiz, criarNoCurso(147, "C97", 6, 10));
    inserirCurso(&raiz, criarNoCurso(148, "C98", 5, 10));
    inserirCurso(&raiz, criarNoCurso(149, "C99", 5, 10));
    inserirCurso(&raiz, criarNoCurso(150, "C100", 4, 10));
    inserirCurso(&raiz, criarNoCurso(151, "C101", 6, 10));
    inserirCurso(&raiz, criarNoCurso(152, "C102", 10, 10));
    inserirCurso(&raiz, criarNoCurso(153, "C103", 8, 10));
    inserirCurso(&raiz, criarNoCurso(154, "C104", 7, 10));
    inserirCurso(&raiz, criarNoCurso(155, "C105", 6, 10));
    inserirCurso(&raiz, criarNoCurso(156, "C106", 10, 10));
    inserirCurso(&raiz, criarNoCurso(157, "C107", 9 ,10));
    inserirCurso(&raiz, criarNoCurso(158, "C108", 9 ,10));
    inserirCurso(&raiz ,criarNoCurso(159, "C109" ,8 ,10));
    inserirCurso(&raiz, criarNoCurso(160, "C110", 4, 10));
    inserirCurso(&raiz, criarNoCurso(161, "C111", 6, 10));
    inserirCurso(&raiz, criarNoCurso(162, "C112", 10, 10));
    inserirCurso(&raiz, criarNoCurso(163, "C113", 8, 10));
    inserirCurso(&raiz, criarNoCurso(164, "C114", 7, 10));
    inserirCurso(&raiz, criarNoCurso(165, "C115", 6, 10));
    inserirCurso(&raiz, criarNoCurso(166, "C116", 10, 10));
    inserirCurso(&raiz, criarNoCurso(167, "C117", 9 ,10));
    inserirCurso(&raiz, criarNoCurso(168, "C118", 9 ,10));
    inserirCurso(&raiz ,criarNoCurso(169, "C119" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(170, "C120" ,7 ,10));
    inserirCurso(&raiz ,criarNoCurso(171, "C121" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(172, "C122" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(173, "C123" ,7 ,10));
    inserirCurso(&raiz ,criarNoCurso(174, "C124" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(175, "C125" ,5 ,10));
    inserirCurso(&raiz ,criarNoCurso(176, "C126" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(177, "C127", 3 ,10));
    inserirCurso(&raiz ,criarNoCurso(178, "C128", 4,10));
    inserirCurso(&raiz ,criarNoCurso(179, "C129" ,3 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(180, "C130" ,2 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(181, "C131" ,10 ,10));
    inserirCurso(&raiz ,criarNoCurso(182, "C132" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(183, "C133" ,3, 10 ));
    inserirCurso(&raiz ,criarNoCurso(184, "C134" ,2, 10 ));
    inserirCurso(&raiz ,criarNoCurso(185, "C135" , 2, 10));
    inserirCurso(&raiz ,criarNoCurso(186, "C136" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(187, "C137" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(188, "C138" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(189, "C139" ,10 ,10));
    inserirCurso(&raiz ,criarNoCurso(190, "C140" ,9 ,10));
    inserirCurso(&raiz ,criarNoCurso(191, "C141" ,8 ,10));
    inserirCurso(&raiz ,criarNoCurso(192, "C142" ,6 ,10));
    inserirCurso(&raiz ,criarNoCurso(193, "C143" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(194, "C144" ,4 ,10));
    inserirCurso(&raiz ,criarNoCurso(195, "C145" ,3 ,10 ));
    inserirCurso(&raiz ,criarNoCurso(196, "C146" ,3,10 ));
    inserirCurso(&raiz, criarNoCurso(197, "C147", 6, 10));
    inserirCurso(&raiz, criarNoCurso(198, "C148", 5, 10));
    inserirCurso(&raiz, criarNoCurso(199, "C149", 5, 10));
    inserirCurso(&raiz, criarNoCurso(200, "C150", 5, 10));

    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para preencher Arvore: %.5lf milissegundos\n", tempo);


    inicio = clock();

    aux = existeCurso(raiz, 3091);

    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para busca Arvore: %.5lf milissegundos\n", tempo);




    return 0;
}