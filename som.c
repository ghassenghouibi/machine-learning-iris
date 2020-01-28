#include "utils.h"

map* init_map(double* min_vector,double* max_vector){
    map* new_map=malloc(sizeof(*new_map));
    new_map->line=LINE;
    new_map->column=COLUMN;
    new_map->neighborhood_radius=NEIGHBORHOOD;
    new_map->alpha=ALPHA;
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
        printf("\n");
    }
}


void shuffle_vector(int* tab){
    int tmp,indice=0;
    for(int i=0;i<NUMBEROFLINE;i++){
        indice=random_int_value(i,NUMBEROFLINE);
        tmp=tab[indice];
        tab[indice]=tab[i];
        tab[i]=tmp;
    }
}

int* allocate_tab(){
    int* tab=calloc(NUMBEROFLINE,sizeof *tab);
    for(int i=0;i<NUMBEROFLINE;i++){
        tab[i]=i;
    }
    return tab;
}

void print_tab(int* tab){
    for(int i=0;i<NUMBEROFLINE;i++){
        printf("%d ",tab[i]);
    }
}

void neurons_learning(map* neurons_map,iris* iris_tab,int neighbor,double alpha,int iteration){
    neurons **map=neurons_map->table;
    double initial_alpha=alpha;
    int neighbor_=neighbor;
    int *index=allocate_tab();
    int dec = iteration / neighbor, lbmu,cbmu=-1;
    double dmin = 1000.0,dtmp=0.0;
    double* ptr=NULL;
    for(int i=1;i<=iteration;i++){
        shuffle_vector(index);
        alpha=initial_alpha * (1.0 - (i / (double) iteration));
        for(int j=0;j<NUMBEROFLINE;j++){
            lbmu=-1;
            cbmu=-1;
            ptr=iris_tab[index[j]].vector;
            dmin=1000.0;
            dtmp=0.0;
            for(int k =0;k<LINE;k++){
                for(int l =0;l<COLUMN;l++){
                    dtmp=euclidean_distance(ptr,map[k][l].data);
                    if(dmin > dtmp){
                        dmin=dtmp;
                        lbmu=k;
                        cbmu=l;
                    }
                }
            }
            int ii_start = (lbmu - neighbor >= 0)? lbmu - neighbor :0;
            int ii_finish = (lbmu + neighbor < neurons_map->line )? lbmu + neighbor : neurons_map->line - 1;
            int jj_start = (cbmu - neighbor >= 0)? cbmu - neighbor : 0;
            int jj_finish = (cbmu + neighbor < neurons_map->column)? cbmu + neighbor : neurons_map->column -1;
            for(int ii=ii_start;ii<=ii_finish;ii++){
                for(int jj=jj_start ; jj <jj_finish ; jj++){
                    for(int kk =0; kk<NUMBEROFDATA ;kk++){
                        map[ii][jj].data[kk] += (double)alpha * (ptr[kk] - map[ii][jj].data[kk]);
                    }
                }
            }
        }
        neighbor_ +=(i % dec == 0 && neighbor_ >1)? -1 :0;
    }
    free(index);
    index=NULL;
}

void detect(map* neurons_map,iris* iris_tab){
    neurons **map=neurons_map->table;
	double dtemp = 0.0;
	double dmin = 1000.0; 
	int indice_iris = -1000;
	for(int l = 0; l < LINE; l++){
		for(int c = 0; c < COLUMN ; c++){
			dmin = 1000.0;
			indice_iris = -1000;
			for(int i = 0; i < NUMBEROFLINE ; i++){
				dtemp = euclidean_distance(map[l][c].data, iris_tab[i].vector);
                if(dmin > dtemp){
					dmin = dtemp;
					indice_iris = i;
				}

			}
			map[l][c].label = iris_tab[indice_iris].iris_name;
		}
	}
}

void show_map(map* neurons_map){
    neurons **map=neurons_map->table;
	
	for(int l = 0; l < LINE; l++){
		for(int c = 0; c < COLUMN ; c++){
			if (strncmp(map[l][c].label, "Iris-setosa", 11) == 0)
				printf("\033[0;34m * ");
			else if (strncmp(map[l][c].label, "Iris-versicolor", 15) == 0)
				printf("\033[0;31m - ");
			else if (strncmp(map[l][c].label, "Iris-virginica", 14) == 0)
				printf("\033[0;37m ^ ");
		}
		printf("\n");

	}
		printf("\033[0;34m Iris-setosa     -> * \n");
		printf("\033[0;31m Iris-versicolor -> - \n");
		printf("\033[0;37m Iris-virginica  -> ^ \n");
}