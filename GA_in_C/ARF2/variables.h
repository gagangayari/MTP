
#ifndef check_if_included
#define check_if_included

#define input_cols 20

#define output_rows 10000
#define output_cols 4

#define mut_prob 0.2
#define xover_prob 0.3

#define key_size 35
#define max_offsprings 300
#define init_pop 300
#define max_itr 5000


int vary_flag=0;
int count_repeat;
int found_flag=0;
int offsprings_count=0;

int actual_output[output_rows][output_cols];
int actual_input[output_rows][input_cols];
int curr_output[output_rows][output_cols];

//Output for IO generation pairs
int input[output_cols];



double average_error[max_itr];


struct chrom
{
    int key[key_size];
    double fitness ;    
    double error;
};

struct custom_struct{
    int first,second;
};


struct args{
    int start;
    int end;
    struct Node *node;
    struct chrom *sample;
};



#endif