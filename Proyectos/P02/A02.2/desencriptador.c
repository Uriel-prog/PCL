// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#define  clave 15

void microsegundos(struct timeval ti, struct timeval tf){
    double tiempo;
    tiempo = ((tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0)*1000;
    printf("\n Tiempo %g microsegundos\n",tiempo);
}

int main(int argc, char* argv[])
{
    struct timeval inicio,final;
    FILE* fd;
    int c;
    int salto;

    if ((argc != 2)) {
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }

    if ((fd= fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
        exit(2);
    }
    //obtener el tiempo inicial
    gettimeofday(&inicio,NULL);
    while ((c=getc(stdin)) != EOF) {
	int numero = c;
	numero^=clave;
	putc(numero, stdout);
        putc(numero, fd);
	salto++;
	if(salto == 3){
		putc('\n',stdout);
		salto = 0;
	}
    }
    fclose(fd);
    //obtener el tiempo de fin
    gettimeofday(&final,NULL);
    microsegundos(inicio,final);
}
