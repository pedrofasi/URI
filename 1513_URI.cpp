#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f

// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// DÉCIMA PRIMEIRA ATIVIDADE: Backtracking 
// Complexidade O(N*M) Em que N é o número de  linhas e M o número de colunas
// Métodos utilizados: BackTracking

vector<pair<int,int>> lista[101][101];
vector<pair<int,int>> peoes;

int K;
int pd[18][1<<17];
int dist[101][101];
int armazena[18][18];
char tabuleiro[101][101];

int tsp(int pos, int bitmask){
    
    if(bitmask == (1<<K+1)-1){
        
        return armazena[pos][K];
    }
    if(pd[pos][bitmask]!=-1){
        return pd[pos][bitmask];
    }
    int res = INF;
    for(int i = 0 ; i<K; i++){
        if(i!=pos && !(bitmask&(1<<i))){
            res = min(res,armazena[pos][i] + tsp(i,bitmask | (1<<i)));
           
        }
    }
    return pd[pos][bitmask] = res;
}

void bfs(pair<int,int> &inicio,int peao, pair<int,int> &inicio1){

    int x1,y1,x2,y2;
    queue<pair<int,int>> fila;

    int x3 = inicio.first;
    int y3 = inicio.second;
    
    memset(dist,INF,sizeof dist);
    dist[x3][y3] = 0;
    fila.push(inicio);

    while(!fila.empty()){
        pair<int,int> aux = fila.front();
        fila.pop();
        x1 = aux.first;
        y1 = aux.second;
        for(auto v: lista[x1][y1]){
            x2 = v.first;
            y2 = v.second;
            if(dist[x2][y2] == INF){
                dist[x2][y2] = dist[x1][y1]+1;
                fila.push(v);
            }
        }
    }

    for(int i = 0 ; i< K ; i++){
        armazena[peao][i] = dist[peoes[i].first][peoes[i].second];
    }
    armazena[peao][K] = dist[inicio1.first][inicio1.second];
    
}

int main(){
    int N,M;
    int dirx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int diry[] = {2, -2, 2, -2, 1, -1, 1, -1};

    do{
        cin >> N >> M >> K;
        if(N!=0){
            pair<int,int> inicio;
            peoes.clear();
            
            for(int i = 0; i<N; i++){
                for(int j = 0; j< M; j++){
                    lista[i][j].clear();
                    cin >> tabuleiro[i][j];
                    if(tabuleiro[i][j] == 'P'){
                        peoes.push_back({i,j});
                    }
                    if(tabuleiro[i][j] == 'C'){
                        inicio = {i,j};
                    }
                }
            }
            
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(i >= 0 && i < N && j >= 0 && j < M && tabuleiro[i][j] != '#'){
                        for(int l = 0; l<8; l++){
                            int tab_x = i+dirx[l];
                            int tab_y = j+diry[l];
                            if(tab_x >= 0 && tab_x < N && tab_y >= 0 && tab_y < M && tabuleiro[tab_x][tab_y] != '#'){
                                lista[i][j].push_back({tab_x,tab_y});
                                lista[tab_x][tab_y].push_back({i,j});
                            }
                        }
                    }
                }
            }
            

            memset(armazena,INF,sizeof armazena);
            for(int i = 0; i<K+1; i++){
                armazena[i][i]=0;
            }

            bfs(inicio,K,inicio);

            for(int i = 0 ; i< K; i++){
                bfs(peoes[i],i,inicio);
            }
            
            for(int i = 0 ; i< K+1; i++){
                for(int j = 0; j<(1<<K+1); j++){
                    pd[i][j]=-1;
                }
            }

            int res = tsp(K,1<<K);
            printf("%d\n",res);
        }
        else{
            break;
        }

    }while(N!=0);

    return 0;

}
