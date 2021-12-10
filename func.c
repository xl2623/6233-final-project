#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

unsigned int readBlock(int block_size, unsigned char *content, int fd){
	int bytes;
	bytes = read (fd, content, block_size);
	return bytes;
}

unsigned int writeBlock(int block_size, unsigned char *content, int fd){
	int bytes;
	bytes = write (fd, content, block_size);
}

void readFromFile(char *filename, int block_size, int block_count){
	int fd;
	
	fd = open (filename, O_RDONLY, S_IRWXU);
	
	if(fd<0){
		printf("Error in opeing file: %s. \n", filename);
		return;
	}
	
	unsigned char *content = malloc (sizeof (unsigned char) * block_size) ;
	
	for (int i = 0; i < block_count; i++){
	
		if (content == NULL){
			printf("Error in allocating space for buffer. \n");
			return;
		}
		readBlock(block_size, content, fd);
		
	}
	free(content);
	close(fd);
}

unsigned int writeToFile(char *filename, unsigned char* content, int block_size, int block_count){
	int fd;
	fd = open (filename, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);
	if(fd<0){
		printf("Error in opeing file: %s. \n", filename);
	}
	
	for (int i = 0; i < block_count; i++){
		if (content == NULL){
			printf("Error in allocating space for buffer. \n");
		}
		writeBlock (block_size, content, fd);
	}
	close(fd);
	return block_size * block_count;
}

double now() {
    struct timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}


