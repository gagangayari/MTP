#!/usr/bin/env python
# coding: utf-8

# In[1]:
import copy
import pickle
import time
import subprocess as sb
from subprocess import PIPE
from scipy.stats import expon
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
# from numba import jit,vectorize,float64

#%% Declare constants
key_len=32
possible_val=['0','1']
populations=400
max_itr=100
max_offsprings=300
p_cross= 0.7
p_mut =0.01
error_vals=[]
found=False
exact_key=None

#%% Read data file

##Actual output data .
output_data=pd.read_csv('actual_output.csv',header=None)






# In[19]: A chromosome class



class sample:
    def __init__(self):
        self.key=np.random.randint(0,2,key_len)
        self.fitness= -1

#%% In[ ]: generate output from obfuscated code.


def get_output(key):
    """
    Runs a C code by passing the "key" as parameters and creates
    a output csv file based on the given key. 

    Parameters
    ----------
    key : Binary string

    Returns
    -------
    None.

    """
    exe="locked_adpcm"
    filename="adpcm_operation.c"
    
    temp= [str(k) for k in key]

    run=".\locked_adpcm"
    aout=[run]
    
    aout.extend(temp)
    # print(aout)
    sb.run(["gcc","-o",exe,filename],shell=True,stdout=PIPE)
    sb.run(aout,shell=True,stdout=PIPE)
    
    # output=pd.read_csv("cur_output.csv",header=None)  
    # print(outputtput)

       
#%% Mutation
    
                
                
def mutation(sample):
    mutation_prob=np.random.uniform(0,1,key_len)<=p_mut
    mutation_index= np.array(np.where(mutation_prob)).ravel()
    
 

    for index in mutation_index:

        if(sample.key[index]==0):
            # print("here","0")
            sample.key[index]=1
        else:
            sample.key[index]=0
    # print(sample.key)
    return sample

def flip(sample,index,prob):
    ##Flip at random points based on given probability
    for i,p in zip(index,prob):
        if(p>p_mut):
            # print("\nchange at index :{}\n".format(i))
            if(sample.key[i]==0):
                sample.key[i]=1
            else:
                sample.key[i]=0
    return sample


def custom_mutation(chromosome):
    ##Indexes
    # chromosome.key=np.array(chromosome.key)
    const1=np.hstack((0,range(12,43)))
    const2=np.hstack((1,range(43,74)))
    const3=np.hstack((5,range(74,105)))
    const4=np.hstack((6,range(105,136)))
    const5=np.hstack((10,range(136,167)))
    
    # constants=[const1,const2,const3,const4,const5]
    # constants=[const1]
    
    ##Exploration
    # print("\before {}\n".format(chromosome.key[const1]))
    
    ##Exploitation
    #Taking the last 16bits for exploitation
    i_const1=np.hstack((0,range(12,43)))[16:]
    i_const2=np.hstack((1,range(43,74)))[16:]
    i_const3=np.hstack((5,range(74,105)))[16:]
    i_const4=np.hstack((6,range(105,136)))[16:]
    i_const5=np.hstack((10,range(136,167)))[16:]
    
    
    
    constants=[i_const1,i_const2,i_const3,i_const4,i_const5]
    # constants=[i_const1,i_const2]
    
    ##Exploitation
    for const in constants:
        prob=np.random.uniform(0,(p_mut*100)/80,16)
        # print("prob",prob)
        chromosome=flip(chromosome,const,prob)
        
    ##For operation and branch
    indexes=[2,3,4,7,8,9,11]
    prob=np.random.uniform(0,(p_mut*100)/80,7)
    
    for i,p in zip(indexes,prob):
        if(p>p_mut):
            if(chromosome.key[i]==0):
                chromosome.key[i]=1
            else:
                chromosome.key[i]=0
    
        
    # chromosome
    # print("\n after\n",chromosome.key[const1])
    return chromosome
        
            
        
    

#%% Custom Crossover

def helper(p1,p2,i,j,k,method='one_point'):
    
    child1=copy.deepcopy(p1)
    child2=copy.deepcopy(p2)
    a=np.hstack((p1.key[i],p1.key[j:k+1]))
    b=np.hstack((p2.key[i],p2.key[j:k+1]))
        
    if(method=='one_point'):
        point=np.random.randint(0,33,1)[0]
        c1=np.hstack((a[:point],b[point:]))
        c2=np.hstack((b[:point],a[point:]))
        
    child1.key[i]=c1[0]
    child1.key[j:k+1]=c1[1:]
    
    child2.key[i]=c2[0]
    child2.key[j:k+1]=c2[1:]
    
    return (child1,child2)
            
    
    
    
def custom_crossover(p1,p2,method='one_point'):
    
    child1=copy.deepcopy(p1)
    child2=copy.deepcopy(p2)
    
    ##Crossover for 5 constants
    
    p1,p2=helper(p1,p2,0,12,42)
    p1,p2=helper(p1,p2,1,43,73)
    p1,p2=helper(p1,p2,5,74,104)
    p1,p2=helper(p1,p2,6,105,135)
    p1,p2=helper(p1,p2,10,136,166)
    
    
    ##For operation and branch locking
    # Bits are  k3,k4,k5,k8,k9,k10,k12
    
    indexes=[2,3,4,7,8,9,11]
    
    #Perform uniform crossover
    for i in indexes:
        if(np.random.choice([0,1],1)):
            temp=p1.key[i]
            p1.key[i]=p2.key[i]
            p2.key[i]=temp
    
    
    child1.key=p1.key
    child2.key=p2.key
    
    return (child1,child2)
        
            
#%% Crossover
    
def crossover(p1,p2,type="one_point",no_of_offsprings=10):
    
    child1=sample()
    child2=sample()
    if(np.random.uniform()<p_cross):
        
        
        if(type=="one_point"):  ##if single split
            split_point=np.random.randint(0,key_len,1)[0]

            child1.key=np.hstack((p1.key[:split_point],p2.key[split_point:]))
            child2.key=np.hstack((p2.key[:split_point],p1.key[split_point:]))

        elif(type=="two_point"):
            split_1=np.random.randint(0,key_len,1)[0]
            split_2=np.random.randint(0,key_len,1)[0]
            while(split_2==split_1):
                split_2=np.random.randint(0,key_len,1)[0]
            
            child1.key=np.hstack((p1.key[:split_1],p2.key[split_1:split_2],p1.key[split_2:]))
            child2.key=np.hstack((p2.key[:split_1],p1.key[split_1:split_2],p2.key[split_2:]))

        elif(type=="uniform"):
            # print("\np1",p1.key,"\np2",p2.key)
            coin=np.random.choice([0,1],len(p1.key))
            # print("\ncoin",coin)
            
            for i,c in enumerate(coin):
                if(c==1):
                    ##swap
                    temp=p1.key[i]
                    p1.key[i]=p2.key[i]
                    p2.key[i]=temp
            child1.key=p1.key
            child2.key=p2.key
            
            # print("\nchild1 {} \nchild2 {}".format(child1.key,child2.key))
            
                    

                
                 

    return (child1,child2)



#%% selection
def selection(samples,method='tournament'):
    
    samples_copy=copy.deepcopy(samples)
    n_sample=5
    if(method=='tournament'):
        ##select 10 samples at random
        candidate_samples_indexes=np.random.choice(range(len(samples)),n_sample,replace=False) ##indexes 
        # print(type(candidate_samples_indexes[0]))
        candidate_samples=samples[candidate_samples_indexes]
        # print("sampleindexes1 \n",candidate_samples_indexes)
        
        ##choose best fit parent
        parent1=max(candidate_samples,key= lambda x:x.fitness)
        
        
        
        ##For second parent
        remaining_samples=list(set(range(0, len(samples)))-set(candidate_samples_indexes))
        # print (np.array(list(remaining_samples)))
        candidate_samples_indexes2=np.random.choice(np.array(remaining_samples),n_sample,replace=False)
        candidate_samples2=samples[candidate_samples_indexes2]
        parent2=max(candidate_samples2,key= lambda x:x.fitness)
        
        # print("\nsampleindexes2 \n",candidate_samples_indexes2)
        
        
        
        
        
        
        return (parent1,parent2)
        
        
        
    
#%%
def printfitness(samples):
    for s in samples:
        print(s.fitness,end=" ")
#%%
@jit(nopython=False)
# @vectorize
def fitness_parallel(samples):
    errors=[]
    for sample in samples:
        get_output(sample.key)
        output=pd.read_csv("cur_output.csv",header=None)  #predicted output
        ##Scaling down the error by 100
        rss =[np.linalg.norm(np.sqrt(np.mean((output_data-output)**2,axis=1)))/100]
        errors.append(rss[0])
    return errors

@vectorize
def add(a,b):
    return a+b


    
        
#%% fitness

def fitness(samples,if_child=False):
    
    output=[]
    fit_values=[]
    flag=0
    err=0
    # print("before\n",printfitness(samples))
    for i,sample in enumerate(samples):
        print(i)
        # print(sample.fitness)
        
        # start=time.process_time()
        get_output(sample.key)
        ##output csv is generated with the name cur_output.csv
        
        # print(time.process_time()-start)
        
        
        curr_output=pd.read_csv("cur_output.csv",header=None)  #predicted output
        ##Scaling down the error by 100
        rss =[np.linalg.norm(np.sqrt(np.mean((output_data-curr_output)**2,axis=1)))/100]
        err+=rss[0]
        print("rss",rss[0])
        if(rss[0]==0):
            found=True
            exact_key=sample.key
            
            print("Exact key found ",sample.key)
            flag=1
            break
        # try:
        visited[sample]=1
        fitness_strength=1/rss[0]
        
        sample.fitness=fitness_strength
        fit_values.append(fitness_strength)
        
        
    if(if_child==False):
        error_vals.append(err/len(samples))
        ax=plt.plot(error_vals)
        plt.show()
    
    if(flag):
        index=[i for _ in range(len(samples))]
        return index
    ##sort the fit_values
    
    
    samples_sorted=sorted(samples,key=lambda x:x.fitness,reverse=True)
    
    return np.array(samples_sorted)



#%% SGA..
    
# visited={}
visited=np.load('visited_hashmap.npy',allow_pickle=True).item()
fig=plt.figure()
xx=0
ax=fig.add_subplot() 
error_vals=[]

best_offspring=sample()


population=np.array([sample() for _ in range(100)])   
    
def sga(population,visited):

    best_offspring=population[0]
    ##select the n fittest samples
    # print("pop",population)
    for _ in range( max_itr):
        print(" Iteration :",_)
        population=fitness(population) ##reordering in order of decreasing fitness score
        # print("pop",(indexes))
        if(len(set(population))==1):
            print("Best key found ! ",population[0].key)
            break 
        
        if(best_offspring.fitness<population[0].fitness):
            best_offspring=population[0]
            print("current best fitness ",best_offspring.fitness)
            print("key : ",best_offspring.key)


        offsprings=np.empty(max_offsprings,dtype=sample)
        print(offsprings)


        ##selecting two chromosmes with highest fitness
        
        for n_child in range(0,(max_offsprings)-1,2):
            p1,p2=selection(population)
            visited[p1]=1
            visited[p2]=1
            ##crossover
            c1,c2=crossover(p1, p2)
            while(c1 in visited or c2 in visited):
                c1,c2=crossover(p1,p2)
                
            ##Mutation
            c1=mutation(c1)
            c2=mutation(c2)
            
            while(c1 in visited or c2 in visited):
                c1=mutation(c1)
                c2=mutation(c2)
            # print("\n nchild",n_child)
            
            offsprings[n_child]=c1
            offsprings[n_child+1]=c2
            # print(offsprings)
        ##Save visited dictionary after every 10 iterations
        # if(_%5==0):
        #     np.save('visited_hashmap.npy',visited)
        #     visited=np.load('visited_hashmap.npy',allow_pickle=True).item()
        
        # print(offsprings)
        ##choose the best n_childs from combined parents+offsprings
        offsprings=fitness(offsprings,True)
        combined=np.hstack((population,offsprings))
        combined=sorted(combined,key=lambda x:x.fitness,reverse=True)

        population = combined[:max_offsprings]
        
        
    return best_offspring


start=time.process_time()
print(sga(population,visited))
print(time.process_time()-start)

#%% Exact key

ss="1,1,0,1, 0,0,1,1, 0,1,1,0, 0,1,0,1, 0,0,1,0, 0,0,1,0, 0,1,1,0, 1,1,0,1"
act_key=list(map(int,ss.split(",")))

# a=[]

a_sample=sample()
a_sample.key=act_key
#%%
# def binaryToDecimal(binary): 
      

aa=np.hstack((act_key[0],act_key[12:43]))

def bool2int(x):
    y = 0
    for i,j in enumerate(x):
        y += j<<i
    return y    

y=bool2int(aa[::-1])
print(y)







# %%
a_dict=np.load('test_dict.npy',allow_pickle=True).item()

for i in range(10000):
    if(i%5==0):
        a_dict[i]='k'
        np.save('test_dict.npy',a_dict)

    
    
    
