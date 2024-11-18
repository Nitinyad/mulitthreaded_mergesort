#include<pthread.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<stdio.h>
#define NUM_OF_JOB 3

using namespace std;

void* doJob(void* arg){
    int i = *((int*)arg);
    printf("%d\n",i);
}

void init_job() {
    pthread_t thread[NUM_OF_JOB];
    int index[NUM_OF_JOB]={-1,-1,-1};
    for(int i=0;i<NUM_OF_JOB;i++){
    pthread_create(&thread[i],NULL,doJob,(void*)(&index[i]));
    }
}

int main(){
    init_job();
    // sleep(1);
    return 0;
}