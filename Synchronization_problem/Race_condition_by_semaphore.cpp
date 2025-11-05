#include<bits/stdc++.h>
#include <pthread.h>
#include<semaphore.h>

#define nl '\n'
using namespace std;

int counter=0;
sem_t sem;

void* increment(void* arg){
    for(int i=0;i<100000;i++){

        sem_wait(&sem);
        counter++;
        sem_post(&sem);
    }
    return nullptr;
}

int main(){
    pthread_t t1,t2;
    sem_init(&sem,0,1);
    
    pthread_create(&t1,nullptr,increment,nullptr);
    pthread_create(&t2,nullptr,increment,nullptr);
    pthread_join(t1,nullptr);
    pthread_join(t2,nullptr);

    cout<<counter<<nl;
}
