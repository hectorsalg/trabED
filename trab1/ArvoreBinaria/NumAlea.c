#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define Tam 5000

int geraNum(){
    return ((rand() % (50000 - 10000 + 1)) + 10000);
}

int comparar(int vetor[], int i, int tam, int numAle){
    int flag = 0;
    for(int j = 0; j < i + 1; j++){
        if(numAle == vetor[j])
            flag = 1;
    }
    return flag;
}

void aleatorio(int vetor[], int i, int tam){
    if(i < tam){
        int numAle = geraNum();
        if(comparar(vetor, i, tam, numAle)){
            aleatorio(vetor, i, tam);
        }else{
            vetor[i] = numAle;
            aleatorio(vetor, ++i, tam);
        }
    }
}

int main() {
    int min = 1000;
    int max = 9999;
    int numero_aleatorio, vetor[Tam] = {0};
   
    srand(time(NULL));

    aleatorio(vetor, 0, Tam);

    for(int i = 0; i < Tam; i++)
        printf("%d ", vetor[i]);

    clock_t inicio, fim;

    double tempo1, tempo2;


    inicio = clock();

    for(int i = 0; i < Tam; i++)
        vetor[i] = i;

    printf("\n");

    fim = clock();

    tempo1 = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    inicio = clock();

    for(int i = 0; i < Tam; i++)
        vetor[i] = i;

    fim = clock();

    tempo2 = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para busca Arvore: %.5lf %.5lf soma: %.5lf milissegundos\n", tempo1, tempo2, tempo1 + tempo2);

    return 0;
}
