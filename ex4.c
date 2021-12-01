#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int matriz[100][100];

} Grafo;

void inicializa(Grafo *gf,int vertices, int arestas)
{

    gf->vertices = vertices;
    gf->n_arestas = arestas;
    
}


void insere_grafo(Grafo *gf,int x, int y,int z){
    
    gf->matriz[x][y] = z;
    gf->matriz[y][x] = z;

}

/*

Foi utilizado um algoritmo de árvore geradora mínima PRIM para calcular
o menor custo d a empresa para conectar os roteadores

*/
void prim(Grafo *gf){
    int arvore[gf->vertices]; // vetor que construirá a árvore geradora minima
    int peso[gf->vertices]; // vetor que armazena o valor de cada peso dessa arvore geradora minima
    bool incluido[gf->vertices]; // vetor para representar se tal vertice está incluido na arvore
    int i,j, comeco,min;
    
    for(i = 1 ; i< gf->vertices+1; i++){
        peso[i]=10001; // setando de começo os mínimos com valor alto, para no futuro serem substituidos pelos valores reais
        incluido[i]=false; // setando falso pois até o momento nenhum vetor está na árvore geradora minima
    }
    peso[1]=0; // primeiro vértice, seu peso para ir até ele é 0, pois ele é a origem
    arvore[1]=-1; // primeiro vértice = origem
    
    // for para achar o vértice com o menor peso dentro dos vértices não incluídos na AGM

    for(i = 1 ; i< gf->vertices+1; i++){
        min = 10001;
        int aux;
        for(j = 1 ; j<gf->vertices+1; j++){
            if(incluido[j]==false && peso[j]<min){
                min = peso[j];
                aux = j; // auxiliar que indica onde está o vértice com menor peso
            }
        }
        
        incluido[aux]= true; // indica que ele será incluido na arvore

        for(j = 1; j<gf->vertices+1; j++){
            if(gf->matriz[aux][j] !=0 && incluido[j]==false && gf->matriz[aux][j]<peso[j]){ // Só vai entrar se existir uma aresta entre (aux e j) e j não estiver incluida na AGM e o peso dela ser menor que o peso antigo feito na interação anterior 
                arvore[j] = aux; // adiciona na arvore 
                peso[j]=gf->matriz[aux][j]; // adiciona o novo peso para servir de parametro para as proximas interaçoes
            }
        }
    
    }

    long int custo=0;
    for(i = 2; i<gf->vertices+1; i++){
        custo += gf->matriz[i][arvore[i]]; // soma o custo total de todos os pesos das arestas na AGM
    }
    
    printf("%ld\n",custo);

}


int main()
{   
    Grafo gf;
    int R,C,i;
    scanf("%d %d",&R,&C); 
    inicializa(&gf,R,C); // funcão pra inicializar o grafo
    int V,W,P;
    
    for(i = 0 ; i<C; i++){
        scanf("%d %d %d",&V,&W,&P);
        insere_grafo(&gf,V,W,P);// funcao para inserir o peso nas vertices V e W do grafo
    }
    
    prim(&gf);
    
    return 0;

}