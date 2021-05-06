
#include"variables.h"

/* Display  1d array */

void disp_1d(unsigned int a[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%u ",a[i]);
    }
    printf("\n");
}

void disp_2d(unsigned int arr[][output_cols],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%u ",arr[i][j]);
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

int power(int val,int n){
    int res=1;
    for(int i=0;i<n;i++){
        res=res*val;

    }
    return res;
}

unsigned int bin2int(int arr[],int n){
    unsigned int res=0,count=0;

    for(int i=n-1;i>=0;i--){
        res += (arr[i]* power(2,n-1-i));
        // printf("%d",arr[n-1-i]);
        count++;
    }
    // printf(" \nInt is %lu .Count : %d\n : ",res,count);
    return res;

}


void read_act_output(){
    FILE *csv_file=fopen("act_output_arf.csv","r");
    char Buff[1000000],*line,*token;
    int row=0;
    int col=0;

    
    while(line=fgets(Buff,1000000,csv_file)){
        token=strtok(line,",");
        col=0;
        while(token != NULL){
            actual_output[row][col++]=atoi(token);
            token=strtok(NULL,",");
        }
    row++;
    }
    // disp_2d(actual_output,output_rows,output_cols);

}

void read_input(){
    FILE *csv_file=fopen("act_input_arf.csv","r");
    char Buff[1000000],*line,*token;
    int row=0;
    int col=0;

    
    while(line=fgets(Buff,1000000,csv_file)){
        token=strtok(line,",");
        col=0;
        while(token != NULL){
            actual_input[row][col++]=atoi(token);
            token=strtok(NULL,",");
        }
    row++;
    }

}





/* ################## Calculate fitness ####################*/

double avg_err(struct chrom *samples,int n){
    double avg_error=0;
    for(int i=0;i<n;i++){
        avg_error += samples[i].error;
        // printf("at normal fitnes %lf\n",samples[i].error);
    
    }

// printf("%lf\n",avg_error);
    return avg_error/n;
}


double square(unsigned int a){
    // printf("res(before) %d\n",a);

    double res=a*a;
    // printf("res %lf\n\n",res);
    return res;
}

double get_error(int key[],clock_t t){

    // printf("Before \n");
    double res,temp;
    double norm =0;
    temp,res=0,0;
    // printf("Here\n");
    // disp_2d(actual_input,output_rows,input_cols);

    // disp_1d(actual_output,output_rows);
    for(int i=0;i<output_rows;i++){
        temp=0;
        for(int j=0;j<output_cols;j++){
            temp += square(actual_output[i][j]-curr_output[i][j]);

        }
        norm  += sqrt(temp)/output_cols;

        
    }

    double a=norm/output_rows;
    // printf("err :%lf \n",temp);
    if((fabs(a) > 10e-9)){
        return a;
    }
    else{
        // disp_1d(curr_output,output_rows);
        disp_1d(key,key_size);
        printf("Error : %lf\n",a);
        printf("Exact key found \n");
        t=clock()-t;
        printf("Time taken for iteration : %lf\n",((double) t)/CLOCKS_PER_SEC);
    
        exit(0);
    }

}


/*void* fitness_parallel(void* argsss){

    struct args *args1=(struct args*) argsss;
    struct chrom *samples=args1->sample;
    struct Node *map=args1->node;
    int start= args1->start;
    int end=args1->end;
    double err;
    int k;
    for(int i=start;i<end;i++){
        waka2_cdfg(samples[i].key);
        // printf("Id %d\n",i);
        // disp_1d(samples[i].key,key_size);

        err=get_error();
        // printf("error %lf\n",err);
        if(err ==0){
            found_flag =1;
            printf("Found exact Key\n");
            break;
        }
        samples[i].error=err;
        samples[i].fitness =1/err;
        
        k=bin2int(samples[i].key,key_size);
        // printf("here %lu\n",k);
        // sleep(1);

        map=insert(map,k);

    }
    return NULL;


}


/* Calculates the fitness value for each samples*/
struct Node *fitness(struct chrom samples[],int n,struct Node *map,clock_t t1){

    

    double err;
    unsigned int k;
    for(int i=0;i<n;i++){
        // printf("n : %d\n",i);
        // disp_2d(actual_input,output_rows,output_cols);
        arf_2(samples[i].key);  //curr_output will be modified
        err =get_error(samples[i].key,t1);
        // printf("err %d\n",err);
        

        /*if((err ==0 )){
            found_flag =1;
            printf("Found exact Key\n");
            disp_1d(curr_output,output_rows);
            disp_chrom_key(&samples[i],1);

            break;
        }*/
        samples[i].error=err;
        samples[i].fitness =1/err;
        
        k=bin2int(samples[i].key,key_size);
        map=insert(map,k);


    }
    // printf("Elements in fitness hashmap : %d\n",count_nodes(map));
    return map;
    
}


/*** ########### Delay ############ */

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 


/* ################## Initialize a chromosome #################### */


/* Initialize a random array */

void init(int *chromosome ){
    // srand(time(NULL));
    // delay(1);
    int n;
    for(int i=0;i<key_size;i++){
        n=rand()%2;
        chromosome[i]= n;

    }
    
}



void init_chrom(int n,struct chrom *samples){
    // srand(time(NULL));
    for(int i=0;i<n;i++){
        samples[i].fitness= -1;
        samples[i].error=-1;
        init(samples[i].key);

    }

}


/*  ########################### MUTATION ####################### */


void mutation (struct chrom *sample,struct chrom *child){
    //Takes a single sample ,mutates it and store it in child
    for(int i=0;i<key_size;i++){

        child->key[i]=sample->key[i];

        if((rand()/(double) RAND_MAX) < mut_prob){
            // printf("here %d\n",i);

            if(sample->key[i] == 0 ){
                child->key[i]=1;
            }
            else{
                child->key[i]=0;
            }
        }
        
    }
    // printf("After \n");

    
    // disp_chrom_key(child,1);
    

}

/*Flip bits at some location*/
void flip_bits(struct chrom *sample,int i,int j){
    int mode; //1 for exploit and 2 for explore
    for(int k=i;k<=j;k++){
        if((rand()/(double)RAND_MAX)<mut_prob){
            if(sample->key[k]==0){
                sample->key[k]=1;
            }
            else{
                sample->key[k]=0;
            }
        }
    }
    //Exploitation
    //distribution with LSBs with highere probability
    // double exploit_probs[32]={2.1760605535605863e-14,5.915145860370273e-14,1.6079033504929256e-13,4.3707344595633353e-13,1.1880888058450779e-12,3.229560211524282e-12,8.778854836900806e-12,2.3863401577827254e-11,6.486745087422874e-11,1.763280129698758e-10,4.793092335043042e-10,1.3028975796473835e-09,3.5416428150987542e-09,9.627183307175482e-09,2.6169397443139367e-08,7.113579753140834e-08,1.933671457825691e-07,5.256263986017488e-07,1.4288006878775044e-06,3.883882946347204e-06,1.0557488436917582e-05,2.869822897223955e-05,7.800987432419569e-05,0.00021205282381583498,0.0005764193376520116,0.001566870211111862,0.004259194822419162,0.011577691889648859,0.031471429479130154,0.08554821486874982,0.23254415793483257,0.6321205588285657};
    switch(mode){
        case 1: //Exploitation
            for(int k=i+16;k<=j;k++){
            if( mut_prob > (rand()/(double)(RAND_MAX))){
                if(sample->key[k]==0){
                    sample->key[k]=1;
                }
                else{
                sample->key[k]=0;
                }
            }
            }
        case 2: //Exploration
         for(int k=i;k<=j-16;k++){
            if( mut_prob > (rand()/(double)(RAND_MAX))){

                if(sample->key[k]==0){
                     sample->key[k]=1;
                }   
                else{
                sample->key[k]=0;
                }
            }
    
    
        }
    
    }
    
    //Exploration

    // double explore_probs[32]={0.6321205588285658,0.2325441579348326,0.08554821486874985,0.03147142947913017,0.011577691889648859,0.004259194822419163,0.0015668702111118623,0.0005764193376520117,0.000212052823815835,7.80098743241957e-05,2.869822897223956e-05,1.0557488436917584e-05,3.883882946347205e-06,1.4288006878775046e-06,5.256263986017488e-07,1.9336714578256914e-07,7.113579753140835e-08,2.6169397443139373e-08,9.627183307175484e-09,3.541642815098755e-09,1.3028975796473838e-09,4.793092335043043e-10,1.7632801296987582e-10,6.486745087422875e-11,2.386340157782726e-11,8.778854836900807e-12,3.2295602115242827e-12,1.188088805845078e-12,4.370734459563336e-13,1.6079033504929258e-13,5.915145860370274e-14,2.176060553560587e-14};
    
   

}
void custom_mutation(struct chrom *sample,struct chrom *child){
    //Mutation in Constants
    //const1 k1-k32
    flip_bits(child,0,31);

    //Mutation for remaining bits
    for(int i=32;i<key_size;i++){
        if((rand()/(double)RAND_MAX)<mut_prob){
            if(sample->key[i]==0){
                child->key[i]=1;
            }
            else{
                child->key[i]=0;
            }
        }
    }
    // disp_1d(child->key,key_size);



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
        // srand(time(NULL));
        index=rand() %n;
        swap(&arr[index],&arr[n-1]);
        n--;
    }
}
void uniform_crossover(struct chrom* parent1,struct chrom* parent2,struct chrom* child1,struct chrom* child2){
    // srand(time(NULL));
    // printf("inside \n");
    // disp_1d(parent1->key,32);
    for(int i=0;i<key_size;i++){
        if(rand() %2 ==1){
            child1->key[i]=parent2->key[i];
            child2->key[i]=parent1->key[i];

        }
        else{
            child1->key[i]=parent1->key[i];
            child2->key[i]=parent2->key[i];

        }
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
    // printf("point %d\n",point);
    // disp_1d(mate1->key,key_size);
    // disp_1d(mate2->key,key_size);
    // printf("child1 \n");
    // disp_1d(child1->key,key_size);
    int temp;
    for(int k=i;k<=j;k++){
        if(k<point){
        child1->key[k]=mate1->key[k];
        child2->key[k]=mate2->key[k];
        
        }
        else{
        child1->key[k]=mate2->key[k];
        child2->key[k]=mate1->key[k];
        }

        
    }
    // printf("After\n");
    // disp_1d(child2->key,key_size);
    // printf("Next\n");
    
    


}



/* Method for one-point crossover*/
struct chrom* crossover(struct chrom *mate1,struct chrom *mate2,struct chrom* child1,struct chrom* child2) {
    
    //For constants
    helper_xover_consts(mate1,mate2,0,31,child1,child2);

    //For remaining bits
/*
    int random_point=rand()%7;
    int temp;
    for(int i=random_point;i<key_size;i++){
        temp=mate2->key[i];
        mate2->key[i]=mate1->key[i];
        mate1->key[i]=temp;

    }
    */
//    disp_1d(child1->key,key_size);
    return mate1;////////not completed #########

}



/* ################## Parent selection ###############*/

//if the element index is already present in the array picked_arr 
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
    struct chrom fittest_sample=samples[arr[0]];
    int index=arr[0];
    for(int i=0;i<n;i++){
        if(fittest_sample.fitness < samples[arr[i]].fitness){
            fittest_sample=samples[arr[i]];
            index=arr[i];
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

struct custom_struct selection (struct chrom samples[],int n,struct custom_struct parents){//n is the size of the samples array
    int n_sample=10;
    int first_set[n_sample],second_set[n_sample];
    
    //Initialise array values to -1
    initializer(first_set,n_sample);
    initializer(second_set,n_sample);
    // srand(time(NULL));
    int count1=0,count2=0,i=0,j=0,index;

    //generate  10 random indexes
    while (count1!=n_sample ){
       index= rand()% n;
    //    printf("Debugging1 %d\n",index);

       if( check_if_not_picked(first_set,index,n_sample) ){
        //    printf("Not picked1 %d\n",index);

           first_set[i]=index;
           count1++;
           i++;   
       }

    }
    // disp_1d(first_set,n_sample);
    int parent1=pick_best(samples,first_set,n_sample);
    // disp_chrom_data()
    // printf("\nbest pick %d\n",parent1);
    while (count2 != n_sample ){
       index= rand()%n;
    //    printf("Debugging2 %d\n",index);

       if( check_if_not_picked(second_set,index,n_sample) && check_if_not_picked(first_set,index,n_sample)){
        //    printf("Not picked2 %d\n",index);

           second_set[j]=index;
           count2++;
           j++;   
       }

    }
    // disp_1d(second_set,n_sample);

    int parent2=pick_best(samples,second_set,n_sample);

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
            if(samples[j].error>samples[j+1].error){
                temp =samples[j+1];
                samples[j+1]=samples[j];
                samples[j]=temp;

            }
        }
    }


}

/* ######### comparator ##########*/


//comparator function for qsort
int comparator(const void *p, const void *q)
{
	double l = ((struct chrom *)p)->error;
	double r = ((struct chrom *)q)->error;
    if(l-r<0){
        return -1;
    }
    else if(l-r>0){
        return 1;


    }
    else{
        return 0;
    }
}


void bit_flipper(int arr[],int indexes[],int n){
    //Flip the bits 0 -> 1 and 1->0  in array :-> arr, at indices :-> indexes

    for(int i=0;i<n;i++){
        if(arr[indexes[i]]==0){
            arr[indexes[i]]=1;
        }
        else{
            arr[indexes[i]]=0;
        }
    }
}

/* ############# Random index generator ######## */

/* l : lower index.  u : upper index.  n : number of indexes to be generated*/
void random_index(int picked_arr[],int l,int u,int n){
    //consider l to be 0
    srand(time(NULL));

   if( u-l +1 <n){
       printf( "\nIndex generation not possible....\n");
       return;
   }
   else{
       int i;
       int j=0;
       while(n!=0){
           i=rand() % u ;
           if(check_if_not_picked(picked_arr,i,n)){
               picked_arr[j++]=i;
               n--;
           }
       }

   }
}

/* ############# Introduce variation ########## */
void variation(struct chrom *samples,int n,struct Node *hash_map){
    
    int picked[key_size/2];
    initializer(picked,key_size/2);
    // printf("Init\n");
    // disp_1d(picked,key_size/2);
    for(int i=n/2;i<n;i++){ //vary the last 50% keys
        // printf("\nbefore %d\n",i);

        // disp_1d(samples[i].key,32);


        random_index(picked,0,key_size,key_size/2);
    
        bit_flipper(samples[i].key,picked,key_size/2);
        n=bin2int(samples[i].key,key_size);
    
        while( search(n,hash_map)){
            random_index(picked,0,key_size,key_size/2);
            bit_flipper(samples[i].key,picked,key_size/2);
            n=bin2int(samples[i].key,key_size);

            
        }

    



    }

}

/* ############### Mutation with varying Probability ############### */

void mutate_prob(struct chrom *samples,int n,int  count[]){
    int max=0; //index of the maximum error
    double max_error =0,sum=0;
    double total_error=0;
    double prob[max_offsprings];
    //getting total error and max error
    for(int i=0;i<n;i++){
        // printf("error %lf \n",samples[i].error);

        total_error += samples[i].error;
        if(samples[i].error>max_error){
            max_error=samples[i].error;
            max=i;
        }
    }
    
    sum=0;
    for( int i=0;i<n;i++){
        prob[i]=(max_error-samples[i].error);
        sum +=prob[i];
        // printf("prob %lf \n",prob[i]);

    }
    // printf("sum %lf \n",sum);
    
    for( int i=0;i<n;i++){
        prob[i] = prob[i]/sum;
        count [i]=(int) round(prob[i]*n);
        // printf("%lf ",round(prob[i]*n));
    }

   


}
