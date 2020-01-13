#include "init.h"
/**
* function to count number of lines in file
* @arg filename
**/
int number_of_line_in_file(char* filename){
    FILE*   fp;
    char *  line = NULL;
    
    fp = fopen(filename,"r");
    if (fp == NULL)
        exit(1);

    int lines=1;
    while(!feof(fp)){
    line = fgetc(fp);
        if(line == '\n'){
            lines++;
        }
    }

    return lines;
}
/**
* function allocate memory to iris data struct
**/
iris* allocate_memory(int size){

    iris* tmp;
	tmp = malloc(size * sizeof(iris));
	for(int i = 0; i < size; i++) {
		tmp[i].vector = malloc(NUMBEROFDATA * sizeof(double));
	}

    tmp->iris_name = (char*)malloc(128 * sizeof(char));
    

	return tmp;
}


