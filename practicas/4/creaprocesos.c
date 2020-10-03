#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


int status;

void signalHandler(int signum){
    printf("Limpiando hijo\n");
    wait(&status);
    printf("termina hijo con estatus %d\n",status);
}


int main(int argc, char **argv){
    signal(17,signalHandler);
    unsigned pid = fork();
    if(pid==0){
        sleep(5);
        printf("Soy el proceso hijo\n");


    } else {

        sleep(2);
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        while(1){
            sleep(2);
            printf("trabajando\n");
        }

    }
    printf("Hola mundo \n");


    return 0;
} 