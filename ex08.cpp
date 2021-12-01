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
// OITAVA ATIVIDADE: Divisão e Conquista
// Complexidade O(n logn) , onde N representa a quantidade de elementos no vetor

// Métodos utilizados: Divisão e Conquista

/*
    Algoritmo Merge Sort
*/

int cont;
vector<int> X;

vector<int> merge_sort(vector<int> a, vector<int> b)
{
    int i=0, j=0, N = a.size(), M = b.size();
    vector<int> resultado;
    while(i < N && j< M){
        if(a[i] < b[j]){
            resultado.push_back(a[i]); // Não precisa de swap
            i++;
        }
        else{
            resultado.push_back(b[j]); // precisa de swap, logo 1 jogada
            cont+= (a.size())-i;
            j++;
        }
    }

    while(i< N){
        resultado.push_back(a[i]); // atualiza os restantes dos dados no vet resultado
        i++;
    }

    while(j< M){
        resultado.push_back(b[j]); // atualiza os restantes dos dados no vet resultado
        j++;
    }

    return resultado;
}

vector<int> merge(int esquerda, int direita){
    vector<int> ans;
    int meio = (esquerda+direita)/2;
    if(esquerda+1 >= direita){
        ans.push_back(X[esquerda]);
        return ans;
    }

    vector<int> aux1 = merge(esquerda,meio);
    vector<int> aux2 = merge(meio,direita);

    ans = merge_sort(aux1,aux2);
    return ans;
}

void divisao_conquista(int N){
    
    merge(0,N);
    if(cont%2 != 0){
        printf("Marcelo\n"); // terminou com um numero impar de jogadas
    }
    else{
        printf("Carlos\n"); // terminou com um numero par de jogadas
    }
}

int main(){
    int N,i,j;

    do{
        scanf("%d",&N);
        if(N != 0){
            cont=0;
            X.clear();

            for(i = 0 ; i < N ; i++){
                scanf("%d",&j);
                X.push_back(j);
            }

            divisao_conquista(N);
            
        }else{
            break;
        }
    }while(N !=0);
    
    return 0;

}