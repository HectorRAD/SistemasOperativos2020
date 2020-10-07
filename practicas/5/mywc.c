#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    char c;
    unsigned caracteres = 0;
    unsigned palabras = 0;
    unsigned lineas = 0;
    unsigned esEspacio = 1;

    while(read(STDIN_FILENO,&c,1) != 0) {
        if(c == '\n' && esEspacio == 0) {
            caracteres++;
            palabras++;
            lineas++;
        }else if(c == '\n' && esEspacio == 1){
            lineas++;
            caracteres++;
        } else if(c != ' ') {
            caracteres++;
            esEspacio = 0;
        } else {
            if(esEspacio == 0) {
                caracteres++;
                palabras++;
                esEspacio = 1;
            } else {
                caracteres++;
            }
        }
    }

    printf("Total de caracteres: %u\n", caracteres);
    printf("Total de palabras: %u\n", palabras);
    printf("Total de lineas: %u\n", lineas);
    return 0;
}