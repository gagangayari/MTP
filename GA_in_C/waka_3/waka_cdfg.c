#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include"ga.h"

int waka(int keys[],int in1, int in2, int in3, int in4, int in7, int in8, int in9, int in10, int in14, int in15, int in12, int in17, int in19, int in20, int in22, int in24, int in27, int in28, int in29, int in32)
{
  int return_port;
   int reg_6, reg_6_in;
   int reg_1, reg_1_in;
   int reg_7, reg_7_in;
   int reg_3, reg_3_in;
   int reg_0, reg_0_in;
   int reg_2, reg_2_in;
   int reg_4, reg_4_in;
   int reg_5, reg_5_in;
   int reg_8, reg_8_in;

  //key values
  int sig_key_0_0_ = keys[0];
  int sig_key_1_1_ = keys[1];
  int sig_key_2_2_ = keys[2]; //No changes
  int sig_key_3_3_ = keys[3]; //giving no changes
  int sig_key_4_4_ = keys[4];
  int sig_key_5_5_ = keys[5];//No changes
  int sig_key_6_6_ = keys[6]; //No changes
  int sig_key_7_7_ = keys[7];
  int sig_key_8_8_ = keys[8];

  /*bool sig_key_0_0_ = 0;
  bool sig_key_1_1_ = 0;
  bool sig_key_2_2_ = 0; //No changes
  bool sig_key_3_3_ = 0; //giving no changes
  bool sig_key_4_4_ = 0;
  bool sig_key_5_5_ = 0;//No changes
  bool sig_key_6_6_ = 0; //No changes
  bool sig_key_7_7_ = 0;
  bool sig_key_8_8_ = 0;*/

  goto S_0;

S_0:
  if (((in2 == in1) == 1) == 0)  {
    reg_6_in = reg_6;
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_3_in = reg_3;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_8_in = reg_8;
    reg_7 = (sig_key_1_1_ ? (in3 + in4) : (in3 - in4));
    reg_3 = (sig_key_0_0_ ? (in9 < in10) : (in9 > in10));
    reg_1 = (sig_key_2_2_ ? (in14 - in15) : (in14 + in15));
    reg_0 = (sig_key_1_1_ ? (in3 + in4) : (in3 - in4));
    reg_2 = (sig_key_5_5_ ? ((in8 + in12 + in7) - in27) : ((in8 + in12 + in7) + in27));
    goto S_2;
  }
  if (((in2 == in1) == 1) == 1)  {
    reg_6_in = reg_6;
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_3_in = reg_3;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_8_in = reg_8;
    reg_6 = in8 + in12 + in7;
    reg_1 = (sig_key_2_2_ ? (in14 - in15) : (in14 + in15));
    goto S_1;
  }

S_2:
  if ((reg_3 == 1) == 0)  {
    reg_6_in = reg_6;
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_3_in = reg_3;
    reg_0_in = reg_0;
    // long int a=random()%100;reg_7_in;
    goto S_4;
  }
  if ((reg_3 == 1) == 1)  {
    reg_6_in = reg_6;
    reg_1_in = reg_1;
    reg_7_in = reg_7;
    reg_3_in = reg_3;
    reg_0_in = reg_0;
    reg_2_in = reg_2;
    reg_4_in = reg_4;
    reg_5_in = reg_5;
    reg_8_in = reg_8;
    reg_4 = in22 - in24 + reg_2_in;
    goto S_3;
  }

S_3:
  reg_6_in = reg_6;
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_3_in = reg_3;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_8_in = reg_8;
  reg_5 = (sig_key_6_6_ ? (reg_4_in + reg_0_in) : (reg_4_in - reg_0_in));
  goto S_4;

S_4:
  reg_6_in = reg_6;
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_3_in = reg_3;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_8_in = reg_8;
  reg_8 = (sig_key_4_4_ ? (reg_5_in - in28) : (reg_5_in + in28));
  reg_7 = (sig_key_7_7_ ? (reg_5_in + in29) : (reg_5_in - in29));
  goto S_5;

S_1:
  reg_6_in = reg_6;
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_3_in = reg_3;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_8_in = reg_8;
  reg_8 = (sig_key_3_3_ ? (reg_6_in + in17) : (reg_6_in - in17));
  reg_7 = 0;
  goto S_5;

S_5:
  reg_6_in = reg_6;
  reg_1_in = reg_1;
  reg_7_in = reg_7;
  reg_3_in = reg_3;
  reg_0_in = reg_0;
  reg_2_in = reg_2;
  reg_4_in = reg_4;
  reg_5_in = reg_5;
  reg_8_in = reg_8;
  return_port = (sig_key_8_8_ ? ((reg_1_in + reg_8_in + reg_7_in) - in32) : ((reg_1_in + reg_8_in + reg_7_in) + in32));
  return return_port;
}


void waka_cdfg(int key[]){
  int arr[20],res;
  // int key[key_size]={0,0,0,0,0,0,0,0};

  // FILE *ptr =fopen("act_output.csv","w");
  read_input();
  for(int row =0;row<output_rows;row++){
    for(int i=0;i<20;i++){
      arr[i]=actual_input[row][i];
      
    }
    res=waka(key,arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19]);
    curr_output[row][0]=res;
/*
    if(row<output_rows-1){
      fprintf(ptr,"%d,",res);
    }
    else{
      fprintf(ptr,"%d\n",res);
    }
  }
  fclose(ptr);
  */
  }
}