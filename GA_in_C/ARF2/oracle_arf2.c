#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void arf( unsigned int *o1, unsigned int *o2, unsigned int *o3, unsigned int *o4,unsigned int i1, unsigned int i2, unsigned int i3, unsigned int i4, unsigned int i6, unsigned int G1, unsigned int G2, unsigned int G3, unsigned int G4, unsigned int GG1, unsigned int GG2)
{
  unsigned int reg_23, reg_23_in;
  unsigned int reg_11, reg_11_in;
  unsigned int reg_16, reg_16_in;
  unsigned int reg_19, reg_19_in;
  unsigned int reg_17, reg_17_in;
  unsigned int reg_7, reg_7_in;
  unsigned int reg_9, reg_9_in;
  unsigned int reg_10, reg_10_in;
  unsigned int reg_4, reg_4_in;
  unsigned int reg_0, reg_0_in;
  unsigned int reg_1, reg_1_in;
  unsigned int reg_2, reg_2_in;
  unsigned int reg_3, reg_3_in;
  unsigned int reg_18, reg_18_in;
  unsigned int reg_22, reg_22_in;
  unsigned int reg_5, reg_5_in;
  unsigned int reg_24, reg_24_in;
  unsigned int reg_25, reg_25_in;
  unsigned int reg_21, reg_21_in;
  unsigned int reg_20, reg_20_in;
  unsigned int reg_15, reg_15_in;
  unsigned int reg_13, reg_13_in;
  unsigned int reg_14, reg_14_in;
  unsigned int reg_12, reg_12_in;
  unsigned int reg_6, reg_6_in;
  unsigned int reg_8, reg_8_in;

  //key values
  int sig_key_0_0_=1;
  int sig_key_1_1_=0;
  int sig_key_2_2_=1;
  int sig_key_3_3_=0;
  int sig_key_4_4_=1;

  int sig_key_5_5_=0;
  int sig_key_6_6_=1;
  int sig_key_7_7_=1;
  int sig_key_8_8_=0;

  int sig_key_9_9_=0;
  int sig_key_10_10_=1;
  int sig_key_11_11_=0;
  int sig_key_12_12_=0;

  int sig_key_13_13_=1;
  int sig_key_14_14_=0;
  int sig_key_15_15_=0;
  int sig_key_16_16_=1;

  int sig_key_17_17_=0;
  int sig_key_18_18_=1;
  int sig_key_19_19_=0;
  int sig_key_20_20_=1;

  int sig_key_21_21_=0;
  int sig_key_22_22_=1;
  int sig_key_23_23_=1;
  int sig_key_24_24_=0;

  int sig_key_25_25_=0;
  int sig_key_26_26_=1;
  int sig_key_27_27_=0;
  int sig_key_28_28_=0;

  int sig_key_29_29_=1;
  int sig_key_30_30_=0;
  int sig_key_31_31_=0;
  int sig_key_32_32_=1;
  
  int sig_key_33_33_=0;
  int sig_key_34_34_=1;

  goto S_0;

S_0:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_10 = (sig_key_13_13_ ? (GG2 * i2) : (GG2 + i2));
  reg_4 = G1 > 10;
  reg_0 = (sig_key_12_12_ ? (GG1 + i1) : (GG1 * i1));
  reg_1 = (sig_key_14_14_ ? (i2 + G1) : (i2 * G1));
  reg_2 = (sig_key_15_15_ ? (i1 + G2) : (i1 * G2));
  reg_3 = (sig_key_19_19_ ? (i4 + 9) : (i4 * 9));
  goto S_1;

S_1:
  if (((reg_4 ^ sig_key_0_0_) == 0) == 1)  {
    reg_23_in = reg_23;
    reg_11_in = reg_11;
    reg_16_in = reg_16;
    reg_19_in = reg_19;
    reg_17_in = reg_17;
    reg_7_in = reg_7;
    reg_9_in = reg_9;
    reg_10_in = reg_10;
    reg_4_in = reg_4;
    reg_0_in = reg_0;
    reg_1_in = reg_1;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_18_in = reg_18;
    reg_22_in = reg_22;
    reg_5_in = reg_5;
    reg_24_in = reg_24;
    reg_25_in = reg_25;
    reg_21_in = reg_21;
    reg_20_in = reg_20;
    reg_15_in = reg_15;
    reg_13_in = reg_13;
    reg_14_in = reg_14;
    reg_12_in = reg_12;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_5 = (sig_key_29_29_ ? (reg_2_in + reg_1_in) : (reg_2_in - reg_1_in));
    goto S_2;
  }
  if (((reg_4 ^ sig_key_0_0_) == 0) == 0)  {
    reg_23_in = reg_23;
    reg_11_in = reg_11;
    reg_16_in = reg_16;
    reg_19_in = reg_19;
    reg_17_in = reg_17;
    reg_7_in = reg_7;
    reg_9_in = reg_9;
    reg_10_in = reg_10;
    reg_4_in = reg_4;
    reg_0_in = reg_0;
    reg_1_in = reg_1;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_18_in = reg_18;
    reg_22_in = reg_22;
    reg_5_in = reg_5;
    reg_24_in = reg_24;
    reg_25_in = reg_25;
    reg_21_in = reg_21;
    reg_20_in = reg_20;
    reg_15_in = reg_15;
    reg_13_in = reg_13;
    reg_14_in = reg_14;
    reg_12_in = reg_12;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_5 = (sig_key_29_29_ ? (reg_2_in + reg_1_in) : (reg_2_in - reg_1_in));
    goto S_4;
  }

S_4:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_7 = (sig_key_17_17_ ? (i3 + i4) : (i3 * i4));
  goto S_5;

S_5:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_11 = (sig_key_5_5_ ? (reg_7_in + reg_1_in) : (reg_7_in - reg_1_in));
  goto S_6;

S_2:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_6 = (sig_key_16_16_ ? (G1 * i3) : (G1 + i3));
  goto S_3;

S_3:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_11 = (sig_key_4_4_ ? (((sig_key_30_30_ ? (GG1 - reg_6_in) : (GG1 + reg_6_in))) - reg_2_in) : (((sig_key_30_30_ ? (GG1 - reg_6_in) : (GG1 + reg_6_in))) + reg_2_in));
  reg_7 = (sig_key_30_30_ ? (GG1 - reg_6_in) : (GG1 + reg_6_in));
  goto S_6;

S_6:
  if (((((sig_key_3_3_ ? (reg_7 > reg_2) : (reg_7 < reg_2))) ^ sig_key_1_1_) == 1) == 0)  {
    reg_23_in = reg_23;
    reg_11_in = reg_11;
    reg_16_in = reg_16;
    reg_19_in = reg_19;
    reg_17_in = reg_17;
    reg_7_in = reg_7;
    reg_9_in = reg_9;
    reg_10_in = reg_10;
    reg_4_in = reg_4;
    reg_0_in = reg_0;
    reg_1_in = reg_1;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_18_in = reg_18;
    reg_22_in = reg_22;
    reg_5_in = reg_5;
    reg_24_in = reg_24;
    reg_25_in = reg_25;
    reg_21_in = reg_21;
    reg_20_in = reg_20;
    reg_15_in = reg_15;
    reg_13_in = reg_13;
    reg_14_in = reg_14;
    reg_12_in = reg_12;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_8 = (sig_key_8_8_ ? (reg_10_in + reg_2_in) : (reg_10_in - reg_2_in));
    goto S_9;
  }
  if (((((sig_key_3_3_ ? (reg_7 > reg_2) : (reg_7 < reg_2))) ^ sig_key_1_1_) == 1) == 1)  {
    reg_23_in = reg_23;
    reg_11_in = reg_11;
    reg_16_in = reg_16;
    reg_19_in = reg_19;
    reg_17_in = reg_17;
    reg_7_in = reg_7;
    reg_9_in = reg_9;
    reg_10_in = reg_10;
    reg_4_in = reg_4;
    reg_0_in = reg_0;
    reg_1_in = reg_1;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_18_in = reg_18;
    reg_22_in = reg_22;
    reg_5_in = reg_5;
    reg_24_in = reg_24;
    reg_25_in = reg_25;
    reg_21_in = reg_21;
    reg_20_in = reg_20;
    reg_15_in = reg_15;
    reg_13_in = reg_13;
    reg_14_in = reg_14;
    reg_12_in = reg_12;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    goto S_7;
  }

S_9:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_10 = (sig_key_9_9_ ? (reg_2_in + reg_8_in) : (reg_2_in - reg_8_in));
  reg_16 = (sig_key_10_10_ ? (reg_8_in - ((sig_key_9_9_ ? (reg_2_in + reg_8_in) : (reg_2_in - reg_8_in)))) : (reg_8_in + ((sig_key_9_9_ ? (reg_2_in + reg_8_in) : (reg_2_in - reg_8_in)))));
  goto S_10;

S_7:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_9 = (sig_key_18_18_ ? (G2 * i4) : (G2 + i4));
  goto S_8;

S_8:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_11 = (sig_key_6_6_ ? (reg_9_in - i3) : (reg_9_in + i3));
  reg_16 = (sig_key_7_7_ ? (((sig_key_6_6_ ? (reg_9_in - i3) : (reg_9_in + i3))) - G2) : (((sig_key_6_6_ ? (reg_9_in - i3) : (reg_9_in + i3))) + G2));
  goto S_10;

S_10:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_13 = (sig_key_28_28_ ? (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) - 11) : (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) + 11));
  reg_14 = (sig_key_28_28_ ? (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) - 11) : (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) + 11));
  reg_19 = (sig_key_28_28_ ? (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) - 11) : (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) + 11));
  reg_12 = (sig_key_31_31_ ? (reg_10_in - reg_0_in) : (reg_10_in + reg_0_in));
  *o1 = (sig_key_28_28_ ? (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) - 11) : (((sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in))) + 11));
  reg_20 = (sig_key_20_20_ ? (G2 * i3) : (G2 + i3));
  reg_22 = (sig_key_32_32_ ? (reg_11_in + reg_2_in) : (reg_11_in - reg_2_in));
  goto S_11;

S_11:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_18 = (sig_key_26_26_ ? (reg_19_in * G2) : (reg_19_in + G2));
  reg_15 = reg_13_in == (reg_3_in + i6 + reg_20_in);
  reg_19 = reg_3_in + i6 + reg_20_in;
  *o2 = reg_3_in + i6 + reg_20_in;
  goto S_12;

S_12:
  if (((reg_15 ^ sig_key_2_2_) == 0) == 0)  {
    reg_23_in = reg_23;
    reg_11_in = reg_11;
    reg_16_in = reg_16;
    reg_19_in = reg_19;
    reg_17_in = reg_17;
    reg_7_in = reg_7;
    reg_9_in = reg_9;
    reg_10_in = reg_10;
    reg_4_in = reg_4;
    reg_0_in = reg_0;
    reg_1_in = reg_1;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_18_in = reg_18;
    reg_22_in = reg_22;
    reg_5_in = reg_5;
    reg_24_in = reg_24;
    reg_25_in = reg_25;
    reg_21_in = reg_21;
    reg_20_in = reg_20;
    reg_15_in = reg_15;
    reg_13_in = reg_13;
    reg_14_in = reg_14;
    reg_12_in = reg_12;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_23 = (sig_key_27_27_ ? (reg_19_in + G1) : (reg_19_in * G1));
    goto S_15;
  }
  if (((reg_15 ^ sig_key_2_2_) == 0) == 1)  {
    reg_23_in = reg_23;
    reg_11_in = reg_11;
    reg_16_in = reg_16;
    reg_19_in = reg_19;
    reg_17_in = reg_17;
    reg_7_in = reg_7;
    reg_9_in = reg_9;
    reg_10_in = reg_10;
    reg_4_in = reg_4;
    reg_0_in = reg_0;
    reg_1_in = reg_1;
    reg_2_in = reg_2;
    reg_3_in = reg_3;
    reg_18_in = reg_18;
    reg_22_in = reg_22;
    reg_5_in = reg_5;
    reg_24_in = reg_24;
    reg_25_in = reg_25;
    reg_21_in = reg_21;
    reg_20_in = reg_20;
    reg_15_in = reg_15;
    reg_13_in = reg_13;
    reg_14_in = reg_14;
    reg_12_in = reg_12;
    reg_6_in = reg_6;
    reg_8_in = reg_8;
    reg_23 = (sig_key_27_27_ ? (reg_19_in + G1) : (reg_19_in * G1));
    goto S_13;
  }

S_15:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_16 = reg_23_in;
  reg_19 = (sig_key_22_22_ ? (reg_14_in * G1) : (reg_14_in + G1));
  reg_17 = reg_16_in;
  goto S_16;

S_13:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_17 = (sig_key_21_21_ ? (reg_22_in + reg_16_in) : (reg_22_in * reg_16_in));
  goto S_14;

S_14:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_16 = (sig_key_33_33_ ? (reg_17_in - reg_23_in) : (reg_17_in + reg_23_in));
  reg_19 = (sig_key_11_11_ ? (reg_13_in + reg_17_in) : (reg_13_in - reg_17_in));
  goto S_16;

S_16:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_18 = (sig_key_26_26_ ? (reg_19_in * G2) : (reg_19_in + G2));
  reg_19 = (sig_key_23_23_ ? (reg_18_in * reg_16_in) : (reg_18_in + reg_16_in));
  reg_22 = (sig_key_23_23_ ? (reg_18_in * reg_16_in) : (reg_18_in + reg_16_in));
  goto S_17;

S_17:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_19 = (sig_key_34_34_ ? (reg_18_in + reg_17_in) : (reg_18_in - reg_17_in));
  reg_21 = (sig_key_24_24_ ? (reg_22_in + G1) : (reg_22_in * G1));
  reg_20 = (sig_key_26_26_ ? (reg_19_in * G2) : (reg_19_in + G2));
  reg_22 = (sig_key_34_34_ ? (reg_18_in + reg_17_in) : (reg_18_in - reg_17_in));
  goto S_18;

S_18:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_23 = (sig_key_27_27_ ? (reg_19_in + G1) : (reg_19_in * G1));
  reg_24 = (sig_key_25_25_ ? (reg_22_in + G2) : (reg_22_in * G2));
  goto S_19;

S_19:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  reg_25 = reg_5_in + reg_24_in + reg_21_in;
  *o3 = reg_12_in + reg_23_in + reg_20_in;
  goto S_20;

S_20:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  *o4 = reg_25_in+10;
  goto S_21;

S_21:
  reg_23_in = reg_23;
  reg_11_in = reg_11;
  reg_16_in = reg_16;
  reg_19_in = reg_19;
  reg_17_in = reg_17;
  reg_7_in = reg_7;
  reg_9_in = reg_9;
  reg_10_in = reg_10;
  reg_4_in = reg_4;
  reg_0_in = reg_0;
  reg_1_in = reg_1;
  reg_2_in = reg_2;
  reg_3_in = reg_3;
  reg_18_in = reg_18;
  reg_22_in = reg_22;
  reg_5_in = reg_5;
  reg_24_in = reg_24;
  reg_25_in = reg_25;
  reg_21_in = reg_21;
  reg_20_in = reg_20;
  reg_15_in = reg_15;
  reg_13_in = reg_13;
  reg_14_in = reg_14;
  reg_12_in = reg_12;
  reg_6_in = reg_6;
  reg_8_in = reg_8;
  return;
}


#include<math.h>
#include<string.h>
#include<time.h>

#include"variables.h"
#include"hash_map.c"
#include"ga_func_arf2.c"




int main(){
  srand(time(NULL));

  FILE *ptr1=fopen("act_input_arf.csv","w");
  FILE *ptr2=fopen("act_output_arf.csv","w");

  unsigned int output[output_rows][output_cols];
  unsigned int a,inputs[11];

  for(int row=0;row<output_rows;row++){


  for(int i=0;i<11;i++){
    a=((unsigned int) rand() )%200;
    inputs[i]=a;

    if(i<10){
      fprintf(ptr1,"%u,",a);
    }
    else{
      fprintf(ptr1,"%u\n",a);

    }
  }

  arf(&output[row][0],&output[row][1],&output[row][2],&output[row][3],inputs[0],inputs[1],inputs[2],inputs[3],inputs[4],inputs[5],inputs[6],inputs[7],inputs[8],inputs[9],inputs[10]);
    fprintf(ptr2,"%u,",output[row][0]);
    fprintf(ptr2,"%u,",output[row][1]);
    fprintf(ptr2,"%u,",output[row][2]);
    fprintf(ptr2,"%u\n",output[row][3]);

    
  }
  disp_2d(output,output_rows,output_cols);
  return 0;
}