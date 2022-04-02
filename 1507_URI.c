
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ALUNO: PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA: 668443
// PROFESSOR: WLADMIR CARDOSO BRANDAO
// TERCEIRA ATIVIDADE: Subsequências
// Complexidade O(N) , onde N representa o número queries a ser analisada no texto principal

// Métodos utilizados da fila estática

typedef struct{
    char item[101];
    int head,tail;
}Fila;

void Fila_inicia(Fila *f){
    f->head = 0;
    f->tail = 0;
}

void enqueue(Fila *f, char A){
    f->item[f->tail]=A;
    f->tail++;
}

void dequeue(Fila *f){
    f->head++;
}

bool Fila_vazia(Fila *f){
    if(f->head == f->tail){
        return true;
    }
    else{
        return false;
    }
}

/*
    Esta função cria uma fila estática para ajudar na solução do exercicio.
    A fila recebe a cada interação de enqueue, os caracteres de R, auxiliando assim na procura de subsequencia na sequencial principal
    onde será percorrido, e a cada vez que o primeiro da fila é encontrado na sequencia, ele é retirado da fila, e ao final, se tivermos uma fila
    completamente vazia, significa que R é subsequência de S
*/

void busca_subsequencia(char S[100001], char R[101]){
    
    int i;
    int l=0;

    for(i = 0 ; i < strlen(S); i++){
        if(R[l]==S[i]){
            l++;
        }
    }  

    if(l == strlen(R)){
        printf("Yes\n");
    }
    else{
       printf("No\n");
    }
}


int main()
{
    int N,Q,i,j;
    scanf("%d", &N);
    char S[100001], R[101];
    for(i = 0 ; i < N ; i++){
        scanf("%s",S);
        scanf("%d",&Q);
        for(j = 0 ; j < Q ; j++){
            scanf("%s",R);
            busca_subsequencia(S,R);
        }
    }

    return 0;
}
