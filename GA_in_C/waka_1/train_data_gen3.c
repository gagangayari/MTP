#include"variables.h"
// #include"hash_map.c"
// #include<time.h>
// #include<math.h>
// #include<string.h>
// #include"waka_cdfg3.c"
// #include<stdio.h>
// #include<stdlib.h>
// #include"ga_func.c"


/*generates a single output*/
void gen_inputs(){
    for(int i=0;i<input_cols;i++){
        input[i]=rand()%200 -100  ;  //Inputs ranging from  -100 to 100
        
    }
    // disp_1d(input,input_cols);
}

void fill_inputs(int count){
    for(int r =0;r<input_cols;r++){
        actual_input[count][r]=input[r];

    }
}

void gen_keys(struct chrom *random_keys,int n){
    init_chrom(n,random_keys);

}

int check_keys(int key1[],int key2[]){
    for(int i=0;i<key_size;i++){
        if(key1[i] != key2[i]){
            return 1;
        }
    }
    return 0;
}



void gen_io_pairs(){
    srand(time(NULL));
    int n_keys=2;
    struct chrom *rand_keys=(struct chrom*) malloc(n_keys*sizeof(struct chrom));

    int output1,output2;
    int a_row=0;
    int exact_key[key_size]={0,0,0,0 ,0,0,0,0, 0};
    while(a_row != output_rows){
        gen_keys(rand_keys,n_keys);
        gen_inputs();
        waka3_cdfg(rand_keys[0].key,input,&output1);
        waka3_cdfg(rand_keys[1].key,input,&output2);
        
        if(output1 != output2 && check_keys(rand_keys[0].key,rand_keys[1].key)){
            fill_inputs(a_row);
            waka3_cdfg(exact_key,input,&actual_output[a_row]);
            a_row++;

        }
    }
    disp_1d(actual_output,output_rows);
    printf("train_data gen\n");
    // disp_2d(actual_input,output_rows,input_cols);
    free(rand_keys);

}
/*
int main(){
    gen_io_pairs();
    return 0;
}*/


