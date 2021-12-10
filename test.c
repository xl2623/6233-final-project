#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

unsigned int xorbuf(unsigned char *buffer, int size) {
    unsigned int result = 0;
    for (int i = 0; i < size; i+=4) {
        unsigned int cur;
        cur = buffer[i] + (buffer[i+1] << 8) + (buffer[i+2] << 16) + (buffer[i+3] << 24);
        result ^= cur;
    }
    return result;
}

double now() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int readBlock(int block_size, unsigned char *content, int fd){
	unsigned int xor;
	int bytes;
	bytes = read (fd, content, block_size);
	return bytes;
}

unsigned int readFromFile(char *filename, int block_size){
	int fd;
	int xor;
	int i = 0;
	fd = open (filename, O_RDONLY, S_IRWXU);
	int bytes = block_size;
	if(fd<0){
		printf("Error in opeing file: %s. \n", filename);
		return -1;
	}
	unsigned int currentXor;
	unsigned char *content = malloc (sizeof (unsigned char) * block_size) ;
	if (content == NULL){
		printf("Error in allocating space for buffer. \n");
		return -1;
	}
	while (bytes == block_size){

		bytes = readBlock (block_size, content, fd);
		
	}

	close(fd);
	return xor;
}

int main(int argc, char *argv[]){
    int block_size = 131072;
    char* filename = argv[1];
    double start = 0;
    unsigned int xor = 0;
    double end = 0;
    start = now(); 
    xor = readFromFile(filename, block_size);
    end = now();
    printf("The XOR value of the input file is %08X. Read file in %.2f seconds.\n", xor, end - start);
    return 0;
}
