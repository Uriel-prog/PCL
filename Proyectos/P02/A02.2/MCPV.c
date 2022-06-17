// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////

//stdout = 1
//stderr = 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    FILE* fdP;
    FILE* fdE;
    int c;
    float calculoProbabilidad;
    char probaChar[4];

    if ((argc > 1)) {
        fprintf(stderr, "Error en argumentos\n");
        exit(1);
    }
    while ((c=getc(stdin)) != EOF) {
        int numero = c - 48;
        if(numero >= 0 && numero <= 5){
            float numeroF=numero;
            calculoProbabilidad = numeroF/5;
            sprintf(probaChar, "%.1f", calculoProbabilidad);
            fdP= fopen(" ", "w");
            for(int i=0; i<3 ; i++){
                putc(probaChar[i], stdout);
            }
            putc('\n',stdout);
       }else{
            if(numero < 0){

            }else{
                fdE= fopen(" ", "w");
                putc(c,stderr);
                putc('\n',stderr);
            }
        }
    }
    fclose(fdP);
}

