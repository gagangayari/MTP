#ifndef check_if_included
#define check_if_included

#include<time.h>
#include "hash_map.c"
#define output_rows 1000
#define output_cols 100

#define mut_prob 0.3
#define xover_prob 0.3

#define key_size 32
#define max_offsprings 10
#define init_pop 10
#define max_itr 5



int found_flag;
int offsprings_count=0;
int actual_output[output_rows][output_cols];
int actual_input[output_rows][output_cols];
int curr_output[output_rows][output_cols];

double average_error[max_itr];


/* ############# Structures #############*/


struct chrom
{
    int key[key_size];
    double fitness ;    
    double error;
};

struct custom_struct{
    int first,second;
};


#endif




