#ifndef help_run
#define help_run

unsigned int xorbuf(unsigned int *buffer, int size);

int readBlock(int block_size, unsigned int *content, int fd);

unsigned int writeBlock(int block_size, unsigned char *content, int fd);

unsigned int readFromFile(char *filename, int block_size, int block_count);

int writeToFile(char *filename, unsigned char* content, int block_size, int block_count);

double now();

#endif

