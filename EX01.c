#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Aluno: Pedro Henrique Reis Rodrigues 

typedef struct bacterias{
    unsigned long long dias;
    unsigned long long valor;
}Bacterias;


unsigned long long adiciona(unsigned long long valor,unsigned long long dias){
    unsigned long long resultado;
    unsigned long long i;
    resultado = 0;
    if(dias == 0){
        resultado = valor;
        return resultado;
    }

    for(i = 1 ; i <= 3 ; i++){
        resultado = resultado + (valor * pow(2,(dias-i)));

    }
    
    return resultado;
}


void analise(Bacterias vet[3],unsigned long long N){
    int j;
    unsigned long long soma;
    j=0;
    unsigned long long i;
    soma = 0;
    for(i = 0 ; i< 4; i++){
        soma+= vet[i].valor;
        vet[i].dias = 0;
    }

    for(i = 4 ; i< N ; i++){
        if(j%4==0){
            j=0;
        }
        soma = soma*2;
        soma = soma - adiciona(vet[j].valor,vet[j].dias);
        printf("%lld ",soma);
        getchar();
        vet[j].dias = vet[j].dias+4;
        j++;
    }
    printf("%lld\n",(soma%13371337));
}

int main(){

    unsigned long long N;
    do{
        scanf("%lld",&N);
        if(N!=0){
            Bacterias vet[4];
            scanf("%d %d %d %d",&vet[0].valor,&vet[1].valor,&vet[2].valor,&vet[3].valor);
            analise(vet,N);
        }
    }while(N!=0);

    return 0;
}