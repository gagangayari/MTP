
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<pthread.h>

#include"variables.h"
#include "hash_map.c"
#include "waka_cdfg1.c"
#include"ga_func1.c"

// #include"train_data_gen3.c"




int main(){

    srand(time(NULL));
    clock_t t;
    // threads
    /*
    pthread_t t1,t2,t3,t4;
    struct args *arg1=(struct args*)malloc(sizeof(struct args));
    struct args *arg2=(struct args*)malloc(sizeof(struct args));
    arg1->start=0;
    arg1->end=init_pop/2;

    arg2->start=init_pop/2;
    arg2->end=init_pop;
    
*/

    //Initialise population
    struct chrom *pop=(struct chrom*) malloc(init_pop * (sizeof(struct chrom)));

    struct chrom *childs=(struct chrom*) malloc(max_offsprings * (sizeof(struct chrom)));

    struct chrom *combined=(struct chrom*) malloc((init_pop+max_offsprings) * (sizeof(struct chrom)));

    struct Node *hash_map=NULL ;


    init_chrom(init_pop,pop);


    /*int key[key_size]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    
    for(int i=0;i<key_size;i++){
        pop[0].key[i]=key[i];
    }*/
    // gen_io_pairs();
    // printf("here\n");

    
    read_input();  //stores input values in "actual_input"
    // printf("here\n");

    read_act_output(); //stores output values in "actual_output"
    // printf("here\n");
    // disp_1d(curr_output,output_rows);
    

    hash_map=fitness(pop,init_pop,hash_map);
    // printf("Nodes %d\n",count_nodes(hash_map));
    
    // disp_1d(curr_output,output_rows);
    if(found_flag == 1){
        // printf("Found Exact Key \n");
        exit(0);
    }
    // exit(0);

   /* arg1->node=hash_map;
    arg2->node=hash_map;
    arg1->sample=pop;
    arg2->sample=pop; */
/*
    pthread_create(&t1,NULL,&fitness_parallel,(void*) arg1);
    pthread_create(&t2,NULL,&fitness_parallel,(void*) arg2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    

    */

    // disp_chrom_data(pop,init_pop);

    
    FILE *file=fopen("avg_values.csv","w");


    
    int mut_count=0;


    
    unsigned int n1,n2,n; //For representing binary keys into integers
    struct custom_struct parents;
    // struct Node *map =NULL;
    int pop_size=init_pop;
    int continuity_count=0,prev=0;
    int count[max_offsprings];
    // mutate_prob(pop,init_pop,count);

    t=clock();

    
    for( int itr=0;itr<max_itr;itr++){
        t=clock();


        average_error[itr] =    avg_err(pop,init_pop);

        //Checks if the error is stucked
       /* if(i>0 && average_error[i-1]-average_error[i]<0.01){
            // printf("err here : %lf",average_error[i]-average_error[i-1]);
            if(prev==i-1){
                if(continuity_count ==7){
                    printf("Variation done ..! \n");
                    vary_flag=1;
                    variation(pop,init_pop,hash_map);
                    average_error[i]=avg_err(pop,init_pop);
                    continuity_count=0;
                }
                else{
                    continuity_count++;
                    prev=i;
                }
            }
            else{
                prev=i;
            }
        }
        */

        //Write the average errors into a csv file
       /* if(i<max_itr-1){
            fprintf(file,"%lf,",average_error[i]);

        }
        else{
            fprintf(file,"%lf\n",average_error[i]);

        // }*/
        variation(pop,init_pop,hash_map);
        average_error[itr]=avg_err(pop,init_pop);
        printf("Iteration : %d . Average error : %lf\n",itr,average_error[itr]);

        
        
        //Mutation using probabilities.Parents with less error will have more childs
        mutate_prob(pop,max_offsprings,count);
        // disp_1d(count,max_offsprings);
        int y=0,j=0,a,x=0;
        while( y< max_offsprings){
            a=0;
            while(a<= count [j] ){
                // printf("a %d\n",a);

                parents=selection(pop,max_offsprings,parents);
                crossover(&pop[parents.first],&pop[parents.second ],&childs[y],&childs[y+1]);

                n1=bin2int(childs[y].key,key_size);
                n2=bin2int(childs[y+1].key,key_size);   
                while(search(n1,hash_map) || search(n2,hash_map)){
                    parents=selection(pop,max_offsprings,parents);
                    //   printf("parenst %d : %d \n",parents.first,parents.second);

                    crossover(&pop[parents.first],&pop[parents.second],&childs[y],&childs[y+1]);
                    // disp_1d(childs[y].key,key_size);
                    n1=bin2int(childs[y].key,key_size);
                    // printf("         here n1 :%u \n",n1);

                    // disp_1d(childs[y+1].key,key_size);
                    n2=bin2int(childs[y+1].key,key_size); 
                    // printf("here n2 :%u\n",n2);


                } 
                                                                                                                                                               
                custom_mutation(&childs[y],&childs[y]);
                custom_mutation(&childs[y+1],&childs[y+1]);
                
                n1=bin2int(childs[y].key,key_size);
                n2=bin2int(childs[y+1].key,key_size);
                // printf("a %d\n",a);

                while(search(n1,hash_map)){
                    custom_mutation(&childs[y],&childs[y]);
                    n1=bin2int(childs[y].key,key_size);
                }
                while(search(n2,hash_map)){
                    custom_mutation(&childs[y+1],&childs[y+1]);
                    n2=bin2int(childs[y+1].key,key_size);

                }
                y+=2;
                a+=2;
                
            }
            x+=2;
            j++;

            if(j==max_offsprings-1 && y<max_offsprings ){
                j=0;
            }
        }

        

   

        hash_map=fitness(childs,max_offsprings,hash_map);
        if(found_flag==1){
            printf(("Found exact key \n"));
            
            t=clock()-t;
            printf("Time taken for iteration : %lf\n",((double) t)/CLOCKS_PER_SEC);
            fclose(file);
            exit(0);
        }
        fill_combined(pop,childs,combined);
        qsort(combined,max_offsprings+init_pop,sizeof(struct chrom),comparator);
        for(int k=0;k<max_offsprings;k++){
            pop[k]=combined[k];
        }
        
        // printf("Elements in hashmap : %d\n",count_nodes(hash_map));


    
    
    } 
        
  t=clock()-t;
    printf("Time taken for iteration : %lf\n",((double) t)/CLOCKS_PER_SEC);
   
    

    printf("Elements in hashmap : %d\n",count_nodes(hash_map));
    
   
    fclose(file);
   free(pop);
   free(childs);

   free(combined);
   free (hash_map);

    return 0;

}

