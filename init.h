#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define NUMBEROFDATA 4
#define SIZEOFNAMES 100
typedef struct iris iris;
typedef struct neurons neurons;
typedef struct map map;

struct iris{
    int     index;
    double* vector;
    char*   iris_name;
    double  norm;
};

struct neurons{
    char* label;
    double* data;
};

struct map{
    int line;
    int column;
    neurons** map;
}

iris*   allocate_memory(int size);
iris*   reading_file(char* filename,iris* tab);
void    parsing_and_store_data(iris* head,char* data,int number);
void    store_to_struct(double* values,char* name);
void    print_node(iris* node,int size);
void    normalize_vector(iris* node);
int     number_of_line_in_file(char* filename);
double* calculate_average_vector(iris* tab);
double* calculate_max_vector(double* vector,double value);
double* calculate_min_vector(double* vector,double value);
void    print_vector(double* vector);