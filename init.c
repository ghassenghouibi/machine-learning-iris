#include "init.h"

void reading_file(char* filename){

    FILE*   fp;
    char *  line = NULL;
    size_t  len = 0;
    ssize_t read;

    fp = fopen(filename,"r");
    if (fp == NULL)
        exit(1);

    while ((read = getline(&line, &len, fp)) != -1) {
        parsing_data(line);
    }

    fclose(fp);

    if (line)
        free(line);
    
    exit(0);

}


void parsing_data(char* data){

    const char * separator = ",";
    char * strToken = strtok ( data, separator );

    while ( strToken != NULL ) {
        printf("%s\n", strToken);
        strToken = strtok ( NULL, separator );
    }
}