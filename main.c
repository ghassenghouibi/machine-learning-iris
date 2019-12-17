#include <stdio.h>
#include <stdlib.h>
#include "init.h"

void usage(){
    printf("error incorrect arguments number <usage> iris file.txt\n");
    exit(0);
}

int main(int argc,char *argv[]){ 

    printf("Hello SOM \n");
    if(argc!=2){
        usage();
    }
    reading_file(argv[1]);


    return 0;
}