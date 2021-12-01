#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ALUNO PEDRO HENRIQUE REIS RODRIGUES
// MATRÍCULA 668443


int main()
{
    int N, qntd, leds;
    char V[10000];

    scanf("%d", &N);
    for (int i = 0; i< N ; i++){
        scanf("%s",V);
        leds = 0;
        qntd = strlen(V); // utilização da biblioteca string.h para pegar o valor do tamanho da string V.
        for(int j = 0; j< qntd ; j++){
            if(V[j] == '0'){
                leds+= 6;
            }
            if(V[j] == '1'){
                leds+= 2;
            }
            if(V[j] == '2'){
                leds+= 5;
            }
            if(V[j] == '3'){
                leds+= 5;
            }
            if(V[j] == '4'){
                leds+= 4;
            }
            if(V[j] == '5'){
                leds+= 5;
            }
            if(V[j] == '6'){
                leds+= 6;
            }
            if(V[j] == '7'){
                leds+= 3;
            }
            if(V[j] == '8'){
                leds+= 7;
            }
            if(V[j] == '9'){
                leds+= 6;
            }
        }
        printf("%d leds\n",leds);
    }
    
    return 0;
}