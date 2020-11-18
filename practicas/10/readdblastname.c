#include <stdio.h>
#include <stdlib.h>
#include "./student.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    unsigned index;
    Student myStudent;
    char lastName[20];
    printf("lastName: ");
    scanf("%s", lastName);
    int fd = open(dbName, O_RDONLY, 0);

    while(read(fd, &myStudent, sizeof(Student))){
        if (strcmp(myStudent.lastName, lastName)==0){
            printf("id %d, firstname %s, lastName %s, semester %c\n", myStudent.id, myStudent.firstName, myStudent.lastName, myStudent.semester);
        }
    }
    close(fd);

    return 0;
}