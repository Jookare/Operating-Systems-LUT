#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define SIZE 10

void unzipFile(char *fName){
	FILE* file;
	int read;
	char ch;

	// Opening file
	if((file = fopen(fName, "r")) == NULL){
		printf("Can't open file\n");
		exit(1);
	}
	// 
	int c = 1;
	while (c == 1){
		// reading 4 bytes and transforming them to integer
		if (fread(&(read), sizeof(int) , 1, file) == 1){
			printf("%d", read);
			// reading 1 byte and printing it out as a character
			if (fread(&(ch), sizeof(char), 1, file) == 1){
				printf("%c", ch);
			}
		// File read so we change c to zero
		}else{
			c = 0;
		}
	}
	fclose(file);
}


int main( int argc, char *argv[] ){
	switch(argc){
		// Error message
		case 1:
			printf("my-zip: file1 [file2 ...]\n");
			exit(1);
		default:
			for (int i = 1; i < argc; i++){
				unzipFile(argv[i]);
			}
		break;	
	}
	return (0);	
}