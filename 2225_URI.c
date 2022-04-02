#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// QUARTA ATIVIDADE: Grafos
// Complexidade O(N) , onde N representa o número queries a ser analisada no texto principal

// Métodos utilizados: Grafo Matriz de Adjacencia e Árvore Geradora Mínima (PRIM)

typedef struct cidade{
    int distancia;
    int v;
    int k;
    int flags;
    int visitado;
    int hid;
} Cidade;

typedef struct grafo
{
    int vertices;
    int n_arestas;
    bool visitado[16];
    int matriz[16][16];

} Grafo;

Cidade *cidades[15][6][32768];
int K;

void inicializa(Grafo *gf,int vertices, int arestas)
{

    gf->vertices = vertices;
    gf->n_arestas = arestas;
    int i,j;

    for(i = 0; i< gf->vertices ; i++){
        for(j = 0; j<gf->vertices; j++){
            gf->matriz[i][j] = 900000;
        }
    }

    for(i = 0; i< gf->vertices ; i++){
        for(j = 0 ; j<gf->vertices; j++){
            gf->visitado[i] = false;
        }
    }
}


void insere_grafo(Grafo *gf,int x, int y, int P){
    
    gf->matriz[x][y] = P;
    gf->matriz[y][x] = P;

}


int main(){

    int T,i,j;

    scanf("%d",&T);

    for(i = 0 ; i< T; i++){
        int N,M;
        Grafo gf;
        scanf("%d %d %d",&N,&M,&K);
        inicializa(&gf,N,M);
        for(j=0; j< M ;j++){
            int A,B,C;
            scanf("%d %d %d",&A,&B,&C);
            A--;
            B--;
            if(gf.matriz[A][B]> C){
                insere_grafo(&gf,A,B,C);
            }
        }
        
    }    

    return 0;
}
