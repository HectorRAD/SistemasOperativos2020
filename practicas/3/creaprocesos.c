#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    unsigned pid = fork();
    if(pid==0){

        char *newenviron[] = {NULL};

        printf("Zoy el chicuelo \n");

        execv(argv[1],&argv[1]);
        
    }else{

        int status;
        printf("Zoy el padre, mi chicuelo es %u \n",pid);
        wait(&status);
        printf("Terminando despues del hijo y estatus %d\n", status);
        
    }

    printf("Kiubole chicuelos \n");
    return 0;

}
