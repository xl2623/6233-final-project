#include <sys/time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "help_run.h"

int main(int argc, char* argv[]){
    double start = 0;
    double end = 0;
    int times = 0;
    int fd = open(argv[1], O_RDONLY, S_IRWXU);
    if(fd<0){
        printf("Error in opeing file: %s.\n", argv[1]);
        return -1;
    }
    while (end - start < 5){
        if(times == 0){
            times = 1;
        }else{
            times *= 2;
        }
        start = now();
        for(int i = 0; i < times; i++){
            lseek(fd, times, SEEK_CUR);
        }
        end = now();
    }
    close(fd);
    printf("Executed lseek system call %d times in %.2f secondes.\n", times, end - start);
    return 0;
}
