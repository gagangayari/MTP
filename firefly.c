
#include<stdio.h>
#include<math.h>
#include<limits.h>

int power(double val,double n){
    double k=pow(val,n);
    // printf("here %lf ",k);
    return k;
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

void int2bin(unsigned int n,int bin[]){
    int i=32;
    while(i!=0){
        while(n){
        bin[i-1]=n%2;
        n=n/2;
        i--;
        }
        bin[i-1]=0;
        i--;
    }

    
    
    
}


void normalize(int arr[],int n,int n_const,double res[]){
    int temp[32];
    
    unsigned int x,y;
    for(int i=0;i<n_const;i++){
        for(int j=i*32;j<i*32+32;j++){
            for(int k=j;k<j+32;k++){
                
                temp[k-j]=arr[k];
            }
             x=bin2int(temp,32);
             y=(double)x/UINT_MAX; //Normalizing 0 to 1
            printf("%d ,%u\n",x,UINT_MAX);
            res[i]=1000*y;
            


            
        }
        printf("\n");

    }
}

//For waka1 
void firefly(struct chrom *pop,int n,int max_itr,int n_consts){
    // for(int i=0;i<n;i++){
    //     normalize(pop+i);

    // }

    int pop[n][3];
    int itr=0;
    int dimen=n_consts +2; //dimension= n_const+ branch + operation
    double dist[dimen];
    double step[dimen];
    double k,a,b,c;
    while (itr<max_itr)
    {
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                a=pop[j][0]-pop[i][0];
                b=pop[j][1]-pop[i][1];
                c=pop[j][2]-pop[i][2];

                k= sqrt(pow(a,2) + pow(b,2) + pow(c,2));

                dist[0]+= step[0] * (dist[0]/k);
                dist[1]+= step[1] * (dist[1]/k);
                dist[2]+= step[2] * (dist[2]/k);


            }

            pop[i][0]=pop[i][0] + dist[0];
            pop[i][1]=pop[i][1] + dist[1];
            pop[i][2]=pop[i][2] + dist[2];

           

        }
        //random movement for the last element
        

        itr++;



    }
    
}

int main(){
    double res[3];
    int arr[64]={0,0,1,0 ,0,1,0,0,  1,1,0,1, 0,1,0,1,  0,0,1,0, 0,1,0,0, 1,1,0,1 ,0,1,0,1,0,0,1,0 ,0,1,0,0,  1,1,0,1, 0,1,0,1,  0,0,1,0, 0,1,0,0, 1,1,0,1 ,0,1,0,1};
    normalize(arr,64,2,res);

    for(int i=0;i<3;i++){
        printf("%lf ",res[i]);
    }
    return 0;
}
