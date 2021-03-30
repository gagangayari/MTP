#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "ga.h"
#include "ga_func.c"



int main(){

    srand(time(NULL));
    clock_t t;

    //threads
    pthread_t t1,t2,t3,t4;
    struct args *arg1=(struct args*)malloc(sizeof(struct args));
    struct args *arg2=(struct args*)malloc(sizeof(struct args));
    arg1->start=0;
    arg1->end=200;

    arg2->start=201;
    arg2->end=400;
    read_act_output(); //reads the actual output in actual_output
    

    //Initialise population
    struct chrom *pop=(struct chrom*) malloc(init_pop * (sizeof(struct chrom)));
    struct chrom *childs=(struct chrom*) malloc(max_offsprings * (sizeof(struct chrom)));
    struct chrom *combined=(struct chrom*) malloc((init_pop+max_offsprings) * (sizeof(struct chrom)));
    
    struct Node *hash_map=NULL ;
    init_chrom(init_pop,pop);

    int key[32]={1,1,0,1, 0,0,1,1, 0,1,1,0, 0,1,0,1, 0,0,1,0, 0,0,1,0,  0,1,1,0,  1,1,0,1};
    
    for(int i=0;i<key_size;i++){
        pop[2].key[i]=key[i];
    }
    hash_map=fitness(pop,init_pop,hash_map);
    

    

    arg1->node=hash_map;
    arg2->node=hash_map;
    arg1->sample=pop;
    arg2->sample=pop;
    pthread_create(&t1,NULL,&fitness_parallel,(void*) arg1);
    pthread_create(&t2,NULL,fitness_parallel,(void*) arg2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);



    // disp_chrom_data(pop,init_pop);

    if(found_flag==1){
        printf("Found Exact Key :");
        exit(0);
    }
    
    FILE *file=fopen("avg_values.csv","w");


    
    int mut_count=0;


    
    unsigned int n1,n2,n; //For representing binary keys into integers
    struct custom_struct parents;
    // struct Node *map =NULL;
    int pop_size=init_pop;
    int continuity_count=0,prev=0;
    int count[max_offsprings];
    // mutate_prob(pop,init_pop,count);


    
    for( int i=0;i<max_itr;i++){
        t=clock();


        average_error[i] =    avg_err(pop,init_pop);

        //Checks if the error is stucked
        if(i>0 && average_error[i-1]-average_error[i]<0.01){
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

        //Write the average errors into a csv file
        if(i<max_itr-1){
            fprintf(file,"%lf,",average_error[i]);

        }
        else{
            fprintf(file,"%lf\n",average_error[i]);

        }
        printf("Itereation : %d . Average error : %lf\n",i,average_error[i]);

        
        
        //Mutation using probabilities.Parents with less error will have more childs
        mutate_prob(pop,max_offsprings,count);
        int y=0,j=0,a,x=0;
        while( y< max_offsprings){
            a=0;
            while(a!= count [j] ){
                mutation(&pop[x],&childs[y]);
                n=bin2int(childs[y].key,key_size);
                while(search(n,hash_map)){
                    mutation(&pop[x],&childs[y]);
                    n=bin2int(childs[y].key,key_size);
                }
                y++;
                a++;
                
            }
            x++;
            j++;

            if(j==max_offsprings-1 && y<max_offsprings ){
                j=0;
            }
        }

        
        
        /*for( int j=0;j<max_offsp    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

            n1=bin2int(childs[j].key,key_size); //converting binary key to integer
            n2=bin2int(childs[j+1].key,key_size); 

            //check if the two childs are produced generated before
            while(search(n1,hash_map) ){
                uniform_crossover(&pop[parents.first],&pop[parents.second],&childs[j],&childs[j+1]);
                n1=bin2int(childs[j].key,key_size); 
                
            }
            while(search(n2,hash_map) && n1 !=n2){
                uniform_crossover(&pop[parents.first],&pop[parents.second],&childs[j],&childs[j+1]);
                n2=bin2int(childs[j+1].key,key_size);
                
            }
pthread tutorial c
            n1=bin2int(childs[j].key,key_size); 
            n2=bin2int(childs[j+1].key,key_size);

            while(search(n1,hash_map)){
                mutation(&pop[parents.first],&childs[j]);

                n1=bin2int(childs[j].key,key_size); 
                
            }
            while(search(n2,hash_map) && n1!=n2){
                mutation(&pop[parents.second],&childs[j+1]);

                n2=bin2int(childs[j+1].key,key_size);
                
            }

        // printf("Reached here %d\n",rand());

            // nanosleep(&t1,&t2);

        }
        */

    pthread_create(&t3,NULL, fitness_parallel,(void *)arg1);
    pthread_create(&t3,NULL, fitness_parallel,(void *)arg2);

    pthread_join(t4,NULL);
    pthread_join(t4,NULL);

        hash_map=fitness(childs,max_offsprings,hash_map);
        if(found_flag==1){
            printf(("Found exact key "));
            fclose(file);
            exit(0);
        }
        fill_combined(pop,childs,combined);
        qsort(combined,max_offsprings+init_pop,sizeof(struct chrom),comparator);
        for(int k=0;k<max_offsprings;k++){
            pop[k]=combined[k];
        }
        
        // printf("Elements in hashmap : %d\n",count_nodes(hash_map));


        t=clock()-t;
        printf("Time taken for iteration : %lf\n",((double) t)/CLOCKS_PER_SEC);
    
    
    } 
        
    
    

    printf("Elements in hashmap : %d\n",count_nodes(hash_map));
    
   
    fclose(file);
   free(pop);
   free(childs);

   free(combined);
   free (hash_map);

    return 0;

}

