#include <bits/stdc++.h>

using namespace std;

// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// QUINTA ATIVIDADE: Grafos
// Complexidade O(N) , onde N representa o número queries a ser analisada no texto principal

// Métodos utilizados: Grafo Matriz de Adjacencia, DFS(Deep First Search) e Método de Ordenação Bubble Sort.

typedef struct grafo
{
    int vertices;
    int n_arestas;
    int tam[100];
    int dsu[100];
    bool visitado[100];
    vector <int> matriz[500];

} Grafo;

typedef struct aresta
{
    int a,b;
    int peso;
} Aresta;

vector<Aresta> Lista;

void inicializa(Grafo *gf,int vertices, int arestas)
{

    gf->vertices = vertices;
    gf->n_arestas = arestas;
    int i,j;
    

     for(i = 0 ; i<gf->vertices; i++){
        gf->matriz[i].clear();
        gf->dsu[i] = i;
        gf->tam[i]=1;
        gf->visitado[i]=false;
    }

}


void insere_grafo(Grafo *gf,int x, int y, int z){
    
    gf->matriz[x][y] = z;
    gf->matriz[y][x] = z;

}

bool compare(Aresta aresta1, Aresta aresta2){
    return aresta1.peso < aresta2.peso;
}

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

void dfs(Grafo *gf,int x){
    
    gf->visitado[x] = 1;
    for(int i = 0; i < gf->vertices; i++){
        int u = gf->matriz[x][i];
        if(gf->visitado[u] == 0){
            dfs(gf,u);
        }
    }
}

int main()
{   
    int i,j,aux,peso;
    string aux;
    string origem,destino;
    Aresta aux1;
    while(1){
        Grafo gf;
        int V,A;
        scanf("%d %d",&V,&A);
        
        if(V == 0 && A == 0){
            break;
        }
        inicializa(&gf,V,A);

        
        map<string,int> dicionario;
        int k = 0;

        for(i = 0 ; i< V; i++){
            fflush(stdin);
            scanf("%s",aux);
            dicionario[aux] = k;
            k++;
        }
    
        for(i = 0 ; i< V; i++){
            cin >> origem >> destino >> peso;
            aux1.a = dicionario[origem];
            aux1.b = dicionario[origem];
            aux1.peso = peso;
            Lista.push_back(aux1);
            insere_grafo(&gf,dicionario[origem],dicionario[destino],peso);

        }
        int aux1;
        fflush(stdin);
        sort(Lista.begin(), Lista.end(), compare);
        scanf("%s",origem);
        dfs(&gf,dicionario[origem]);
        for(i = 0 ; i<= k-1 ; i++){
            if(gf.visitados[i]==0){
                aux1 = -1;
            }
        }
        if(aux == -1){
            printf("Impossible\n");
        }
        else{
            for(i = 0; i< )
        }

    }

    

    return 0;

}
