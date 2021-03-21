#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "ga.h"
#include "ga_func.c"



int main(){


    // struct chrom a ={init(&a),-1};
    
    //Initialise population
    struct chrom *pop=(struct chrom*) malloc(init_pop * (sizeof(struct chrom)));
    struct chrom *childs=(struct chrom*) malloc(max_offsprings * (sizeof(struct chrom)));
    struct chrom *combined=(struct chrom*) malloc((init_pop+max_offsprings) * (sizeof(struct chrom)));
    struct Node *hash_map= NULL ;
    init_chrom(init_pop,pop);
    fitness(pop,init_pop);
    int mut_count=0;
    
    int n; //For representing binary keys into integers
    struct custom_struct parents;
    // struct Node *map =NULL;
    int pop_size=init_pop;
    
    
    for( int i=0;i<max_itr;i++){
        average_error[i] =    avg_err(pop,init_pop);

        printf("Itereation : %d . Average error : %lf\n",i,average_error[i]);
        for( int j=0;j<max_offsprings;j++){
        // printf("Offspring : %d \n",j);

            
            parents=selection(pop,max_offsprings);
            // printf("Done selecetion %d,%d \n",parents.first,parents.second);

            mutation(&pop[parents.first],&childs[j]);
            // printf("Done Mutation \n");

            n=bin2int(childs[j].key,key_size); //converting binary key to integer
            disp_chrom_key(&childs[j],1);
            // printf("Bin2int : %d\n",n);

            hash_map=insertNode(hash_map,n);
            // printf("Hashmap \n");

            mut_count=0;
            while(search(n,hash_map)){  //Checks if that key already generated before
                mutation(&pop[j],&childs[j]);
                n=bin2int(childs[j].key,key_size);
                mut_count++;

            }
            printf("Mutation %d\n",mut_count);


        }
        // printf("Reached here \n");

        fitness(childs,max_offsprings);
        fill_combined(pop,childs,combined);
        bsort_samples(combined,max_offsprings+init_pop);
        for(int k=0;k<init_pop;k++){
            pop[k]=combined[k];
        }


    } 
    print_inorder(hash_map);
    
   /* int key[32]={1,1,0,1, 0,0,1,1, 0,1,1,0, 0,1,0,1, 0,0,1,0, 0,0,1,0,  0,1,1,0,  1,1,0,1};
    
    read_act_output();
    for(int i=0;i<key_size;i++){
        pop[1].key[i]=key[i];
    }
    // mutation(&pop[1],&childs[0]);
    fitness(pop,init_pop);
    bsort_samples(pop,init_pop);
    if(found_flag){
        printf("Found \n");
    }
    // disp_chrom_key(&pop[1],1);
    disp_chrom_data(pop,init_pop);

    // disp_chrom_key(&childs[0],1);
    // disp_2d(curr_output,100,100);
    
    */

    return 0;

}

