#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>


double now() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int readBlock(int block_size, unsigned char *content, int fd){
	int bytes;
	bytes = read (fd, content, block_size);
	return bytes;
}

unsigned int readFromFile(char *filename, int block_size){
	int fd;
	int i = 0;
	fd = open (filename, O_RDONLY, S_IRWXU);
	int bytes = block_size;
	if(fd<0){
		printf("Error in opeing file: %s. \n", filename);
		return 0;
	}
	unsigned char *content = malloc (sizeof (unsigned char) * block_size) ;
	if (content == NULL){
		printf("Error in allocating space for buffer. \n");
		return 0;
	}
	while (bytes == block_size){

		bytes = readBlock (block_size, content, fd);
		
	}
	free(content);
	close(fd);
	return 1;
}

int main(int argc, char *argv[]){
    int block_size = 2097152;
    char* filename = argv[1];
    double start = 0;
    unsigned int xor = 0;
    double end = 0;
    start = now(); 
    readFromFile(filename, block_size);
    end = now();
    printf("NO Xor output. Read file in %.2f seconds.\n", end - start);
    return 0;
}
