#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "coder.h"
#include "command.h"
int main(int argc, char *argv[])
{
	if (!argv[1] || !argv[2] || !argv[3]) {
        printf("ERROR\n");
        return 0;
    }
    
    if (strcmp(argv[1], "encode") == 0) {
        int j = encode_file(argv[2], argv[3]);
        if(j == -1){
        	printf("Error in file");
   			}
   	} else{ 
		if (strcmp(argv[1], "decode") == 0) {
			int i = decode_file(argv[2], argv[3]);
    		if(i == -1){
    			printf("Error in file");
    			}
    	} else{
        	printf("ERROR\n");        	
       		return 0;
    	}
	}
    return 0;
}
