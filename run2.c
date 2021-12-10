#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "help_run.h"


int main(int argc, char *argv[]){
    int block_size = atoi(argv[2]);
    int block_count = 0;
    char* filename = argv[1];
    double start = 0;
    double end = 0;
    int counter = 0;
    while (end - start < 5){
    	counter++;
        if (block_count == 0){
            block_count = 1;
        }else{
            block_count *= 2;
        }
        start = now();
        unsigned int xor = readFromFile(filename, block_size, block_count);
        end = now();
        printf("Block count: %d\n", block_count);
    }
    printf("Block size : %d bytes, block count: %d. time : %.2f seconds.\n", block_size, block_count, end - start);
    return 0;
}
