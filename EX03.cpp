#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// Terceira PROVA: Grafos
// Complexidade O(|E| + |V|log|V|) , onde E representa número de arestas do 
// grafo e V representa o numero de vertices do grafo

// Métodos utilizados: Grafo Matriz de Adjacencia e Algoritmo de DIJKSTRA


typedef struct grafo
{
    int vertices;
    int n_arestas;
    int matriz[501][501];

} Grafo;

void inicializa(Grafo *gf,int vertices, int arestas)
{

    gf->vertices = vertices;
    gf->n_arestas = arestas;
    int i,j;

    for(i = 1; i<= gf->vertices ; i++){
        for(j = 1; j<= gf->vertices ; j++){
            gf->matriz[i][j] = INF;
        }
    }

}

void insere_grafo(Grafo *gf,int x, int y, int P){
    
    gf->matriz[x][y] = P;

}


int dijkstra(Grafo *gf, int comeco, int fim){
    
    printf("%d %d",comeco,fim);
    int i,j,min,cont;
    int custo[gf->vertices];
    int visitado[gf->vertices];

    for(i = 1; i<= gf->vertices ; i++){
        custo[i]= INF;
        visitado[i] = 0;
    }  
    
    custo[comeco]=0;
    cont = comeco;
    while(cont != fim){
        for(int i = 1; i <= gf->vertices; i++){
            if(custo[i] > custo[cont] + gf->matriz[cont][i]){
                custo[i] = custo[cont]+gf->matriz[cont][i];
            }
        }
        min = INF;
        visitado[cont]=1;
        for(int i = 1; i<= gf->vertices; i++){
            if((custo[i] < min) && visitado[i]==0){
                min = custo[i];
                cont = i;
            }
        }
        if(min == INF){
            return INF;
        }
    }
    return custo[fim];
}


int main(){
    int N,E,X,Y,H,K,O,D;
    scanf("%d %d ",&N,&E);
    while(N!=0 || E!=0){
            Grafo gf;
            inicializa(&gf,N,E);
            for(int i = 0 ; i< E; i++){
                scanf("%d %d %d ",&X,&Y,&H);
                insere_grafo(&gf,X,Y,H);
                if(gf.matriz[Y][X] != INF){
                    gf.matriz[X][Y]=0;
                    gf.matriz[Y][X]=0;
                }
            }
            
            scanf("%d ",&K);
            for(int i = 0 ; i< K ;i++){
                scanf("%d %d",&O,&D);
                int resultado = dijkstra(&gf,O,D);
                if(resultado == INF){
                    printf("Nao e possivel entregar a carta\n");
                }
                else{
                    printf("%d\n",resultado);
                }
            }
        scanf("%d %d ",&N,&E);
        printf("\n");
    }
    
    return 0;
}