#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>
#include "help_run.h"


int main(int argc, char *argv[]){
	if (argc != 5){
		printf("Please run the program by ./run (filename› [-r] -w] <block_size><block_ count>\n");
		return -1;
	}
	int block_size = atoi (argv[3]);
	int block_count = atoi (argv[4]);
	char* filename = argv[1];
	char* mode = argv[2];
	mode++;
	
	double start;
	double end;
	
	if (*mode =='w'){
		unsigned char *content = malloc(sizeof(unsigned char) * block_size * block_count);

		writeToFile(filename, content, block_size, block_count);

		printf ("write random content of block size: %d, %d times. \n", block_size, block_count);

		free(content);
	}
	else if(*mode == 'r'){
		start = now();
		readFromFile(filename, block_size, block_count);
		end = now();
		printf ("%f sec \n", end-start);
	}
	return 0;

}



