#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 0x3f3f3f3f


void forca_bruta(double X[10000], double Y[10000],int N){
    int i,j;
    double resultado = INF;
    if(N == 1){
        printf("INFINITY\n");
    }
    else{
        for(i = 0 ; i < N ; i++){
            for(j = i ; j< N-1 ; j++){
                if(resultado > sqrt((pow(X[i]-X[j+1],2)+pow(Y[i]-Y[j+1],2)))){
                    resultado = sqrt((pow(X[i]-X[j+1],2)+pow(Y[i]-Y[j+1],2)));
                }
            }
        }
        if(resultado >= 10000){
            printf("INFINITY\n");
        }
        else{
            printf("%.4lf\n",resultado);
        }
    }
    
}

int main(){
    int N,i,j;

    do{
        scanf("%d",&N);
        if(N != 0){
        
            double X[10000],Y[10000];
            for(i = 0 ; i < N ; i++){
                scanf("%lf %lf",&X[i],&Y[i]);
            }
            forca_bruta(X,Y,N);
            
        }else{
            break;
        }
    }while(N !=0);
    
    return 0;

}