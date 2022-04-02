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
// NONA ATIVIDADE: Algoritmos Guloso 
// Complexidade O(log n) em que n representa o número de repetições de cédulas à serem utilizadas

// Métodos utilizados: Algoritmos Gulosos


void alg_guloso(double N){

    double notas[6]={100,50,20,10,5,2};
    double moedas[6]={1,0.5,0.25,0.10,0.05,0.010000};
    int contadorN[6];
    int contadorM[6];
    N += 1e-9;
    for(int i = 0 ; i< 6 ; i++){
        contadorN[i]=0;
        contadorM[i]=0;
    }
    
    int i = 0;
    int j = 0;

    while(N >= 0.000000){
        
        if(i > 5 || j > 5 || N == 0.000000){
            break;
        }
        
        if(N < 2){
            
            if(N - moedas[j] >= 0){
                
                contadorM[j]++;
                N = N - moedas[j];    
            }
            else{
                j++;
            }
        }
        else{
            if(N - notas[i] >= 0.000000){
                N = N - notas[i];
                contadorN[i]++;
            }
            else{
                i++;
            }
        }
    }

    printf("NOTAS:\n");
    for(int i = 0 ; i < 6; i++){
        printf("%d nota(s) de R$ %0.2lf\n",contadorN[i],notas[i]);
    }
    printf("MOEDAS:\n");
    for(int i = 0 ; i < 6; i++){
        printf("%d moeda(s) de R$ %0.2lf\n",contadorM[i],moedas[i]);
    }
    

}

int main(){
    
    double N;

    scanf("%lf",&N);
    alg_guloso(N);

    return 0;

}
