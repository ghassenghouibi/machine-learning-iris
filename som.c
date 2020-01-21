#include "init.h"

map* init_map(double* min_vector,double* max_vector){
    map* new_map=malloc(sizeof(*new_map));
    new_map->line=LINE;
    new_map->column=COLUMN;
    new_map->table=malloc(LINE * sizeof(*new_map->table));
    for(int i=0;i<LINE;i++){
        new_map->table[i]=malloc(COLUMN* sizeof (*new_map->table[i]));
        for(int j=0;j<COLUMN;j++){
            new_map->table[i][j].data=malloc(NUMBEROFDATA * sizeof(*new_map->table[i][j].data));
            for(int k=0;k<NUMBEROFDATA;k++){
                new_map->table[i][j].data[k]=random_value(min_vector[k],max_vector[k]);
            }
        }
    }
    return new_map;
}

void print_map(map* print_map){
    for(int i=0;i<LINE;i++){
        for(int j=0;j<COLUMN;j++){
            for(int k=0;k<NUMBEROFDATA;k++){
                printf("%lf ",print_map->table[i][j].data[k]);
            }
            printf("\n");
        }
    }
}
