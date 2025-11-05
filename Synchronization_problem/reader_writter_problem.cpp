#include <bits/stdc++.h>
#include <pthread.h>
#include<semaphore.h>

#define nl '\n'
using namespace std;
pthread_mutex_t w_mutex,mute;
int read_cnt=0;
int dat=0;

void* read(void* arg){
    pthread_mutex_lock(&mute);
    read_cnt++;
     if(read_cnt==1)
         pthread_mutex_lock(&w_mutex);
     pthread_mutex_unlock(&mute);

     cout<<"Data is read"<<nl;

     pthread_mutex_lock(&mute);
     read_cnt--;
     if(read_cnt==0)
        pthread_mutex_unlock(&w_mutex);
    pthread_mutex_unlock(&mute);

    return nullptr;
}

void* write(void* arg){
    pthread_mutex_lock(&w_mutex);
    dat++;
    cout<<"data is written"<<nl;
    pthread_mutex_unlock(&w_mutex);

    return nullptr;
}

int main(){
    pthread_mutex_init(&w_mutex,nullptr);
    pthread_mutex_init(&mute,nullptr);

    pthread_t r1,r2,w;

    pthread_create(&r1,nullptr,read,nullptr);
    pthread_create(&r2,nullptr,read,nullptr);
    pthread_create(&w,nullptr,write,nullptr);

    pthread_join(r1,nullptr);
    pthread_join(r2,nullptr);
    pthread_join(w,nullptr);


}
