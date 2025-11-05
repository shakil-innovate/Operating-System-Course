#include<bits/stdc++.h>
#include <pthread.h>

#define nl '\n'
using namespace std;

int counter=0;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;

void* increment(void* arg){
    for(int i=0;i<100000;i++){

        pthread_mutex_lock(&mtx);
        counter++;
        pthread_mutex_unlock(&mtx);
    }
    return nullptr;
}

int main(){
    pthread_t t1,t2;
    
    pthread_create(&t1,nullptr,increment,nullptr);
    pthread_create(&t2,nullptr,increment,nullptr);
    pthread_join(t1,nullptr);
    pthread_join(t2,nullptr);

    cout<<counter<<nl;
}
