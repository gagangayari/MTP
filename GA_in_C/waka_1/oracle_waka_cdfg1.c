#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
 int waka( int in1,  int in2,  int in3,  int in4,  int in7,  int in8,  int in9,  int in10,  int in14,  int in15,  int in12,  int in17,  int in19,  int in20,  int in22,  int in24,  int in27,  int in28,  int in29,  int in32)
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
  bool sig_key_0_7_;
  

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
    reg_1 = 6 - in15;
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
    reg_1 = 6 - in15;
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
  reg_9 = 0;
  goto S_3;

S_3:
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



#define data_size 100000
#define input_size 20

void main(){
  
  int arr[input_size],res;
  FILE *input=fopen("input_waka1.csv","w");
  FILE *output=fopen("output_waka1.csv","w");

  for(int i=0;i<data_size;i++){
    for(int j=0;j<20;j++){
      arr[j]=(rand() % 500 )-200;
      if(j<input_size-1){
        fprintf(input,"%d,",arr[j]);
      }
      else{

        fprintf(input,"%d\n",arr[j]);
      }

    }
    res= waka(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10],arr[11],arr[12],arr[13],arr[14],arr[15],arr[16],arr[17],arr[18],arr[19]);

    if(i<data_size-1){
      fprintf(output,"%d,",res);
    }
    else{
      fprintf(output,"%d\n",res);

    }
    
  }

  fclose(input);
  fclose(output);




}