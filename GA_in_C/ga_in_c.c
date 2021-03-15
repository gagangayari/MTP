#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "ga.h"
#include "ga_func.c"


#define key_size 167
#define init_pop_size 400



int main(){


    // struct chrom a ={init(&a),-1};
    
    //Initialise population
    struct chrom *pop=(struct chrom*) malloc(init_pop_size * (sizeof(struct chrom)));
    generate_pop(init_pop_size,pop);
    struct custom_struct parents;
    int pop_size=init_pop_size;
    for( int i=0;i<max_itr;i++){
        fitness(); //calculates the fitness of each samples
        bsort_samples(pop,init_pop_size); //sort the samples based on fitness

        for( int j=0;j<max_offsprings-1;j+=2){
            parents=selection(pop,pop_size);

            



        }
    }
    

    return 0;

}

