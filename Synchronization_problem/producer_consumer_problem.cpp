#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>

using namespace std;
sem_t full,empt;
pthread_mutex_t mtx;

#define nl '\n'
#define SIZE 5
int buffer[SIZE];
int in=0,out=0;

void* producer(void* arg){
    for(int i=0;i<1000;i++){
        sem_wait(&empt);
        // pthread_mutex_lock(&mtx);
        buffer[in]=i;
        cout<<"produce "<<i<<nl;
        in=(in+1)%SIZE;
        sem_post(&full);
        // pthread_mutex_unlock(&mtx);
        // sleep(1);
    }
    return nullptr;
}

void* consumer(void* arg){
    for(int i=0;i<1000;i++){
        sem_wait(&full);
        // pthread_mutex_lock(&mtx);
        int item=buffer[out];
        out=(out+1)%SIZE;
        cout<<"consumed "<<item<<nl;
        sem_post(&empt);
        // pthread_mutex_unlock(&mtx);
        // sleep(1);
    }
    return nullptr;
}

int main(){
    pthread_t t1,t2;
    sem_init(&empt,0,SIZE);
    sem_init(&full,0,0);
    pthread_mutex_init(&mtx,nullptr);

    pthread_create(&t1,nullptr,producer,nullptr);
    pthread_create(&t2,nullptr,consumer,nullptr);
    pthread_join(t1,nullptr);
    pthread_join(t2,nullptr);
}
