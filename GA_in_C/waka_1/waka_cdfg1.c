// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include<time.h>


int waka(int keys[],int in1, int in2, int in3, int in4, int in7, int in8, int in9, int in10, int in14, int in15, int in12, int in17, int in19, int in20, int in22, int in24, int in27, int in28, int in29, int in32)
{
  int return_port;
   int reg_1, reg_1_in;
   int reg_7, reg_7_in;
   int reg_0, reg_0_in;
   int reg_2, reg_2_in;
   int reg_3, reg_3_in;
   int reg_4, reg_4_in;
   int reg_5, reg_5_in;
   int reg_6, reg_6_in;
   int reg_8, reg_8_in;
   int reg_9, reg_9_in;

  //key values
  int key1=keys[0];
  int key2=keys[1];

  bool sig_key_0_7_=keys[2];
  

  goto S_0;

  S_0:
  if (((in2 == in1) == 1) == 1)  {
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_9_in = reg_9;
    reg_1 = key1 - in15;
    reg_7 = in8 + in7 + in12;
    goto S_1;
  }
  if (((in2 == in1) == 1) == 0)  {
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_9_in = reg_9;
    reg_0 = in3 - in4;
    reg_1 = key1 - in15;
    reg_2 = in9 < (217 ^ sig_key_0_7_);
    reg_3 = in3 - in4;
    reg_4 = in8 + in7 + in12;
    goto S_2;
  }

S_2:
  if ((reg_2 == 1) == 1)  {
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_9_in = reg_9;
    reg_5 = reg_4_in + reg_0_in + in22;
    goto S_4;
  }
  if ((reg_2 == 1) == 0)  {
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_9_in = reg_9;
    reg_6 = reg_3_in + in19 + in20;
    goto S_5;
  }

S_4:
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_9_in = reg_9;
  reg_6 = reg_5_in - in24 + in27;
  goto S_5;

S_5:
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_9_in = reg_9;
  reg_8 = reg_6_in - in28;
  reg_9 = reg_6_in + in29;
  goto S_3;

S_1:
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_9_in = reg_9;
  reg_8 = reg_7_in - in17;
  reg_9 = key2 ;
  goto S_3;

S_3:
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_9_in = reg_9;
  return_port = (reg_1_in + in32 + reg_8_in) + reg_9_in;
  return return_port;

}



//for current_output
void waka1_ga_func(int keyss[]){
  int key1[32],key2[32],key[3];
  unsigned int k1,k2;

  for(int i=0;i<32;i++){
    key1[i]=keyss[i];
  }

  for(int i=32;i<64;i++){
    key2[i-32]=keyss[i];
  }


  k1=bin2int(key1,32);
  k2=bin2int(key2,32);
  key[0]=(short) k1;
  key[1]=(short) k2;
  key[2]=keyss[key_size-1];

  
  int arr[20];
  

  for(int row =0;row<output_rows;row++){
    for(int i=0;i<20;i++){
      arr[i]=actual_input[row][i];
      
    }
    curr_output[row]=waka(key,arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19]);
    // printf("%d",curr_output[row]);

  }
}

//For data generation
void waka3_cdfg(int key[],int arr[],int *output){

    *output=waka(key,arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19]);
}
