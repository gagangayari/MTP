
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ga.h"


/* Display  1d array */

void display_arr( int a[],int n){
    printf("/n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("/n");
}


/* ############# Structures #############*/


struct chrom
{
    int key[key_size];
    int fitness ;    
};

struct custom_struct{
    int first,second;
};




/* ################## Calculate fitness ####################*/

double get_error(){
    double res,temp;
    double norm;
    temp,res=0,0;
    for(int i=0;i<output_rows;i++){
        temp=0;
        for(int j=0;j<output_cols;j++){
            temp += pow((actual_output[i][j]-curr_output[i][j]),2);


        }
        norm  += temp;

        
    }
    

    return sqrt(norm);

}

/* Calculates the fitness value for each samples*/
void fitness(struct chrom samples[],int n){
    double err;
    for(int i=0;i<n;i++){
        adpcm(samples[i].key);  //curr_output will be modified
        err =get_error();
        if(err ==0){
            found_flag =1;
            break;
        }

        samples[i].fitness =1/err;

        

    }

}


/* Initialize a random array */

void init(int *chromosome ){
    for(int i=0;i<key_size;i++){
        chromosome[i]= (rand()>RAND_MAX/2);
        // printf("%d ",(rand()>RAND_MAX/2));

    }
    
}



void generate_pop(int n,struct chrom *samples){
    for(int i=0;i<n;i++){
        samples[i].fitness= -1;
        init(samples[i].key);

    }

}


/*  ########################### MUTATION ####################### */

/*Flip bits at some location*/
void flip_bits(struct chrom sample,int i,int j){
    //Exploitation
    for(int k=16;k<32;k++){
        if(rand()/RAND_MAX < mut_prob){
            if(sample.key[i+k]==0){
                sample.key[i+k]=1;
            }
            else{
                sample.key[i+k]=0;
            }
        }
    }

}
void mutation(struct chrom sample){
    //Mutation in Constants
    //const1 k1-k32
    flip_bits(sample,0,31);
    flip_bits(sample,32,63);
    flip_bits(sample,64,95);
    flip_bits(sample,96,127);
    flip_bits(sample,128,159);

    //Mutation for remaining bits



}


/* ################ CROSSOVER ################## */
/* Crossover only for constants*/
void helper_xover_consts(struct chrom *mate1,struct chrom *mate2,int i ,int j){
    /*i and j are the starting and ending indexes of the constants
    E.g For constant 1: i=0,j=31
    */
    int point=rand() % 32;
    int temp;
    for(int k=point;k<=j;k++){
        temp=mate2->key[k];
        mate2->key[k]=mate2->key[k];
        mate1->key[k]=temp;
    }
}



/* Method for one-point crossover*/
void crossover(struct chrom *mate1,struct chrom *mate2) {
    
    //For constants
    helper_xover_consts(mate1,mate2,0,31);
    helper_xover_consts(mate1,mate2,32,63);
    helper_xover_consts(mate1,mate2,64,95);
    helper_xover_consts(mate1,mate2,96,127);
    helper_xover_consts(mate1,mate2,128,159);


    //For remaining bits

    int random_point=rand()%7;
    int temp;
    for(int i=random_point;i<key_size;i++){
        temp=mate2->key[i];
        mate2->key[i]=mate1->key[i];
        mate1->key[i]=temp;

    }
}



/* ################## Parent selection ###############*/

//We select 10 random samples and pick the two fittest samples
int check_if_not_picked(int picked_arr[],int index,int n){
    for(int i=0;i<n;i++){
        if(picked_arr[i]==index){
            return 0;
        }
    }
    return 1;

}

/* Choose the fittest sample from an array of samples8*/
int pick_best(struct chrom samples[],int arr[],int n){
    struct chrom fittest_sample=samples[0];
    int index=0;
    for(int i=0;i<n;i++){
        if(fittest_sample.fitness < samples[i].fitness){
            fittest_sample=samples[i];
        }

    }
    
    return index;

}


struct custom_struct selection (struct chrom samples[],int n){//n is the size of the samples array
    int n_sample=10;
    int first_set[n_sample],second_set[n_sample];
    
    //Initialise array values to -1
    initializer(first_set,n_sample);
    initializer(second_set,n_sample);


    int count1=0,count2=0,i=0,j=0,index;
    //generate  10 random indexes
    while (count1!=10 ){
       index= rand()/n;
       if( check_if_not_picked(first_set,index,n_sample) ){
           first_set[i]=index;
           count1++;
           i++;   
       }

    }
    int parent1=pick_best(samples,first_set,n_sample);
    
    while (count2!=10 ){
       index= rand()/n;
       if( check_if_not_picked(second_set,index,n_sample) ){
           second_set[i]=index;
           count2++;
           j++;   
       }

    }

    int parent2=pick_best(samples,second_set,n_sample);

    struct custom_struct parents;
    parents.first= parent1;
    parents.second= parent2;

    return parents;
    

}

/* ########## Sorting ######### */
//Bubble sort

void bsort_samples(struct chrom *samples,int n){
    struct chrom temp;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-(n-i);j++){
            if(samples[j].fitness>samples[j+1].fitness){
                temp =samples[j+1];
                samples[j+1]=samples[j];
                samples[j]=temp;

            }
        }
    }



}

