#include <stdio.h>
#include <stdlib.h>

// ALUNO PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA 668443

// FUNÇÃO PARA ACHAR O FATORIAL DE X
unsigned long long fatorial(int x){

    unsigned long long res=1;
    int i;

    if(x == 0){
        return res;
    }
    if(x == 1){
        return res;
    }

    for(i = 2 ; i<=x ; i++){ //| (1*)
        res = res*i;         //| Dependendo do valor inserido, para calcular o seu fatorial, é necessário realizar outro laço de repetição, que
    }                        //| poderá aumentar o nível de complexidade do programa.
    return res;
}

int main()
{
    int M,N;
    unsigned long long resultado;
    while(scanf("%d %d", &M,&N) != -1){   // |
                                          // |
        resultado = fatorial(M);          // | Complexidade O(n) no melhor caso e Complexidade O(n^2) no pior caso.
        resultado += fatorial(N);         // | Onde N é a quantidade de testes (entradas) que serão executadas.
        printf("%lld\n",resultado);       // | No melhor caso, para N valendo valores baixos, e no pior caso, para N valendo valores altos, graças ao laço de repetição (1*)
    }

    return 0;
}

// FONTES UTILIZADAS PARA REALIZAÇÃO DO EXERCÍCIO: 
// https://stackoverflow.com/questions/3764014/how-do-you-read-scanf-until-eof-in-c