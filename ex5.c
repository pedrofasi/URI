#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// QUARTA ATIVIDADE: Grafos
// Complexidade O(N) , onde N representa o número queries a ser analisada no texto principal

// Métodos utilizados: Grafo Matriz de Adjacencia e Árvore Geradora Mínima (PRIM)

typedef struct grafo
{
    int vertices;
    int n_arestas;
    bool visitado[26];
    int matriz[26][26];

} Grafo;

void inicializa(Grafo *gf,int vertices, int arestas)
{

    gf->vertices = vertices;
    gf->n_arestas = arestas;
    int i,j;
    for(i = 0 ; i < vertices; i++){
        for(j=0; j< vertices;j++){
            gf->matriz[i][j]=0;
        }
    }

     for(i = 0 ; i<gf->vertices; i++){
        gf->visitado[i]=false;
    }

}


void insere_grafo(Grafo *gf,int x, int y){
    
    gf->matriz[x][y] = 1;
    gf->matriz[y][x] = 1;

}

int dfs(Grafo *gf,int origem, char A[26]){
    if(!gf->visitado[origem]){
        
        int i;
        
        A[strlen(A)]= origem+97;
        gf->visitado[origem]=true;

        for(i = 0 ; i< gf->vertices; i++){
            if(!gf->visitado[i] && gf->matriz[origem][i]==1){
                dfs(gf,i,A);
                
            }
        }

        return 1;
    }
    return 0;
}

void bubble_sort (char vetor[26]) {
    int i,k; 
    char aux;
    
    for(k = strlen(vetor)-1; k>0 ; k--){
        for (i = 0; i < k; i++) {
            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
    }
    }

    for(i = 0 ; i< strlen(vetor);i++){
        printf("%c,",vetor[i]);
    }

}

int main()
{   
    int i,N,j;
    scanf("%d",&N);
    
    for(j = 0 ; j< N ; j++){
        Grafo gf;
        int V,E;
        
        scanf("%d %d",&V,&E);
         
        inicializa(&gf,V,E); // funcão pra inicializar o grafo
        for(i = 0 ; i<E; i++){
            char A1,A2;
            scanf(" %c %c",&A1,&A2);
            int destino,origem;
            destino = A1%97;
            origem = A2%97;
            
            insere_grafo(&gf,destino,origem);// funcao para inserir o peso nas vertices V e W do grafo
        }
        
        printf("Case #%d:\n",j+1);
        int cont=0,aux;
        
        for(i = 0 ; i< V; i++){
            char A[26]="";
            aux = dfs(&gf,i,A);
            cont+= aux;
            if(aux==1){
                bubble_sort(A);
                printf("\n");
            }
        }
        printf("%d connected components\n\n",cont);
    }

    return 0;

}