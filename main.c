#include <stdio.h>
#include <stdlib.h>
#include "init.h"


int main(){ 

   
    iris* iris_tab=NULL;
    //iris* iris_shuffled;
    //iris* iris_average;
    iris_tab=reading_file("iris_data.txt",iris_tab);
    double* average_vector=calculate_average_vector(iris_tab);




    return 0;
}