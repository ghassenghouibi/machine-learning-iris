
double randvalue(double min, double max){
	return (double)((rand() / (double)(RAND_MAX + 1.0)) * (max - min) + min); 
}



map* init_map(int line,int column,double* min_vector,double* max_vector){
    map* new_map=malloc(sizeof(*map));
    map->line=line;
    map->column=column;
    map->map=malloc(line* sizeof(*map->map));
    for(int i=0;i<line;i++){
        map->map[i]=malloc(column* sizeof (*map->[i]));
        for(int j=0;j<column;j++){
            map->[i][j].data=malloc(NUMBEROFDATA * sizeof(*map->map[i][j].data));
            for(int k=0;k<NUMBEROFDATA;k++){
                map->map[i][j].data[k]=random_value(min_vector[k],max_vector[k]);
            }
        }
    }
    return map;
}