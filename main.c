//Main Function
#include "assign2funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIELD_MAX 100
#define BUFFERSIZE 1000
int main(int argc, char *argv[]){
	

	//ERROR CHECKING

        if ( argc < 4 || argc > 104 ) {
                fprintf(stderr, "%s: specify input_delimiter output_delimiter and 1-%d fields in order\n",argv[0], FIELD_MAX);
                exit(1);
        }

        else if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1) {
                fprintf(stderr, "%s: specifiy input_delimiter output_delimiter and 1-%d fields in order\n", argv[0], FIELD_MAX);
                exit(1);
        }

        else{
                for (int i = 3; i < argc-1; i++) {
                        if (argv[i] > argv[i+1]) {
                                fprintf(stderr, "%s: specifiy input_delimiter output_delimiter and 1-%d fields in order\n", argv[0], FIELD_MAX);
                                exit(1);
                        }
                }
        }


	char buffer[BUFFERSIZE];
	
	while(fgets(buffer, BUFFERSIZE , stdin) != NULL){
		const char* tmp =cut(argv, buffer, argc);
		printf("%s\n", tmp);
		free( (void*)tmp );
	}
	return 0;
}	
