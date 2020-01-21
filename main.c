#include <stdio.h>
#include <stdlib.h>
#include "init.h"


int main(){ 

   
    iris* iris_tab=NULL;
    iris_tab=reading_file("iris_data.txt",iris_tab);

    double* average_vector=calculate_average_vector(iris_tab);
    double* max_vector=calculate_max_vector(average_vector,0.05);
    double* min_vector=calculate_min_vector(average_vector,0.02);

    print_vector(average_vector);
    print_vector(max_vector);
    print_vector(min_vector);




    return 0;
}