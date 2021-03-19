
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "ga.h"
#include "adpcm_operation.c"



/* Display  1d array */

void disp_1d( int a[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void disp_2d(int arr[][100],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}


/*display samples key */

void disp_chrom_key(struct chrom *samples,int n){
    for(int i=0;i<n;i++){
        disp_1d(samples[i].key,key_size);

    }
}

void disp_chrom_data(struct chrom *sample,int n){
    for(int i=0;i<n;i++){
        disp_1d(sample[i].key,key_size);
        printf("fitness : %lf\n",sample[i].fitness);
        printf("error : %lf\n",sample[i].error);
    }
    
}


double bin2int(int arr[],int n){
    double res=0;
    for(int i=n-1;i>=0;i--){
        res += (arr[i]* pow(2,n-1-i));
        // printf("%d ",arr[i]);

    }
    return res;

}


void read_act_output(){
    FILE *csv_file=fopen("actual_output.csv","r");
    char Buff[1024],*line,*token;
    int row=0;
    int col=0;


    while(line=fgets(Buff,1024,csv_file)){
        token=strtok(line,",");
        col=0;
        while(token != NULL){
            actual_output[row][col++]=atoi(token);
            token=strtok(NULL,",");
            
         }
         row++;
    }

}





/* ################## Calculate fitness ####################*/

double square(double a){
    return a*a;
}
double get_error(){

    printf("Before \n");
    double res,temp;
    double norm =0;
    temp,res=0,0;
    for(int i=0;i<output_rows;i++){
        temp=0;
        for(int j=0;j<output_cols;j++){
            temp += square(actual_output[i][j]-curr_output[i][j]);

        }
        norm  += sqrt(temp)/output_cols;

        
    }
    printf("after %lf \n",sqrt(norm));
    return sqrt(norm);

}

/* Calculates the fitness value for each samples*/
void fitness(struct chrom samples[],int n){
    // printf("Before \n");

    double err;
    for(int i=0;i<n;i++){
        // printf("Ran  \n");

        run_main_adpcm(samples[i].key);  //curr_output will be modified

        err =get_error();
        if(err ==0){
            found_flag =1;
            printf("Found exact Key\n");
            // break;
        }
        samples[i].error=err;
        samples[i].fitness =1/err;

    }

}


/* ################## Initialize a chromosome #################### */


/* Initialize a random array */

void init(int *chromosome ){
    // srand(time(NULL));
    for(int i=0;i<key_size;i++){
        chromosome[i]= rand() %2;

    }
    
}



void init_chrom(int n,struct chrom *samples){
    for(int i=0;i<n;i++){
        samples[i].fitness= -1;
        samples[i].error=-1;
        init(samples[i].key);

    }

}


/*  ########################### MUTATION ####################### */


void mutation (struct chrom *sample,struct chrom *child){
    //Takes a single sample ,mutates it and store it in child
    init_chrom(1,child);
    
    for(int i=0;i<key_size;i++){
        child->key[i]=sample->key[i];
        if(rand()/(double) RAND_MAX < mut_prob){
            if(sample->key[i] == 0 ){
                child->key[i]=1;
            }
            else{
                child->key[i]=0;
            }
        }
    }
    

}

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
void custom_mutation(struct chrom sample){
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


/*Multipoint Crossover */

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void generate_random_indexes(int arr[],int n){
    //The generated indexes are stroed in res
    srand(time(NULL));
    // int index=rand()%n;
    // n--;
    int index;
    int i=0;
    while(n!=0){    
        srand(time(NULL));
        index=rand() %n;
        swap(&arr[index],&arr[n-1]);
        n--;
    }
}


void multipoint_crossover(int n,struct chrom *mate1,struct chrom *mate2, struct chrom *child1, struct chrom *child2){
    //n is the number of crossover points
    int ind=0;
    int flag=0;
    int indexes[n];
    for(int i=0;i<n;i++){
        indexes[i]=i;
    }
    generate_random_indexes(indexes,n);
    qsort(indexes,n,sizeof(int),comp);

    for(int i=0 ;i<key_size;i++){
        if(i==indexes[ind]){
            if(flag==1){
                flag=0;
            }
            else{
                flag=1;
            }

            ind++;
        }
        if(flag){
            child1[i]=mate1[i];
            child2[i]=mate2[i];
        }
        
        else{
            child1[i]=mate2[i];
            child2[i]=mate1[i];
            
        }
        

    }
    
}


/* Crossover only for constants*/
void helper_xover_consts(struct chrom *mate1,struct chrom *mate2,int i ,int j,struct chrom *child1,struct chrom *child2){
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
struct chrom* crossover(struct chrom *mate1,struct chrom *mate2,struct chrom* child1,struct chrom* child2) {
    
    //For constants
    helper_xover_consts(mate1,mate2,0,31,child1,child2);
    helper_xover_consts(mate1,mate2,32,63,child1,child2);
    helper_xover_consts(mate1,mate2,64,95,child1,child2);
    helper_xover_consts(mate1,mate2,96,127,child1,child2);
    helper_xover_consts(mate1,mate2,128,159,child1,child2);


    //For remaining bits

    int random_point=rand()%7;
    int temp;
    for(int i=random_point;i<key_size;i++){
        temp=mate2->key[i];
        mate2->key[i]=mate1->key[i];
        mate1->key[i]=temp;

    }
    return mate1;////////not completed #########

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


/* Initialise all elements of an array to -1 */
void initializer(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=-1;
    }

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
       index= rand()%n;
       if( check_if_not_picked(first_set,index,n_sample) ){
           first_set[i]=index;
           count1++;
           i++;   
       }

    }
    int parent1=pick_best(samples,first_set,n_sample);
    
    while (count2!=10 ){
       index= rand()%n;
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

void fill_combined(struct chrom *pop,struct chrom *child,struct chrom *combined){
    int k=0;
    for(int i=0;i<init_pop;i++){
        combined[k++]=pop[i];
    }

    for(int j=0;j<max_offsprings;j++){
        combined[k++]=child[j];
    }
}

void bsort_samples(struct chrom *samples,int n){
    struct chrom temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(samples[j].fitness>samples[j+1].fitness){
                temp =samples[j+1];
                samples[j+1]=samples[j];
                samples[j]=temp;

            }
        }
    }


}
