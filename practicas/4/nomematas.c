#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum){
    printf("I LIVED \n");
}

int main(){
    signal(2, signalHandler);
    while(1){
       sleep(2);
       printf("Workiando \n") ;
    }
    return(0);
}
