#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define INF 0x3f3f3f3f

// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// NONA ATIVIDADE: Dynamic Programming 
// Complexidade O(n log n) , onde N representa a quantidade de elementos no vetor

// Métodos utilizados: PD (Dynamic Programming)
int memo[21][21][2001];
int area[21][21][2001];
int N,M,K,X,Y,T;

int pd(int X, int Y, int t){
    if(X>0 && X<=N && Y>0 && Y<=M && t<=T){
        if(memo[X][Y][t]!= -1){
            return memo[X][Y][t]; // pd retorna já o resultado q foi calculado anteriormente
        }
        int soma=0;
        int aux =0;
        if(area[X][Y][t] == 1){ // ou seja tem maça la
            soma=1;
        }
        aux = max(aux,pd(X+1,Y,t+1)); //anda p/ cima
        aux = max(aux,pd(X,Y+1,t+1)); // p/ direita
        aux = max(aux,pd(X+1,Y+1,t+1)); // p/ diagonal direita encima
        aux = max(aux,pd(X-1,Y,t+1)); // p/ baixo
        aux = max(aux,pd(X,Y-1,t+1)); // p/ esquerda
        aux = max(aux,pd(X-1,Y-1,t+1)); // p/ diagonal esquerda embaixo
        aux = max(aux,pd(X-1,Y+1,t+1)); // p/ diagonal direita embaixo
        aux = max(aux,pd(X+1,Y-1,t+1)); // p/ diagonal esquerda encima
        aux = max(aux,pd(X,Y,t+1)); // mantem a posiçao

        return memo[X][Y][t] = aux+soma;

    }else{
        return 0;
    }

}

int main(){

    do{
        scanf("%d %d %d",&N,&M,&K);
        if(N != 0){
            memset(area,0,sizeof(area)); // limpando o vetor para a prox interaçao
            for(int i = 0 ; i< K; i++){
                scanf("%d %d %d",&X,&Y,&T);
                area[X][Y][T]=1; // insere nesta posiçao que tem uma maça lá
            }
            scanf("%d %d",&X,&Y);
            memset(memo,-1,sizeof(memo));
            int resultado = pd(X,Y,0);
            printf("%d\n",resultado);
        }
        else{
            break;
        }
    }while(N!=0);
    
    
    return 0;

}
