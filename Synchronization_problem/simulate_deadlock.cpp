#include <bits/stdc++.h>
#include <pthread.h>
#include<semaphore.h>

#define nl '\n'
using namespace std;
pthread_mutex_t resourceA,resourceB;

// lock in the same order

void* thread1(void* arg){
    sleep(2);
    pthread_mutex_lock(&resourceA);
    pthread_mutex_lock(&resourceB);

    cout<<"accees resource a and b by thread 1"<<nl;

    pthread_mutex_unlock(&resourceB);
    pthread_mutex_unlock(&resourceA);

    return nullptr;
}

void* thread2(void* arg){
    pthread_mutex_lock(&resourceA);
    pthread_mutex_lock(&resourceB);

    cout<<"accees resource a and b by thread 2"<<nl;

    pthread_mutex_unlock(&resourceB);
    pthread_mutex_unlock(&resourceA);

    return nullptr;
}

int main(){
    pthread_mutex_init(&resourceA,nullptr);
    pthread_mutex_init(&resourceB,nullptr);

    pthread_t t1,t2;

    pthread_create(&t1,nullptr,thread1,nullptr);
    pthread_create(&t2,nullptr,thread2,nullptr);

    pthread_join(t1,nullptr);
    pthread_join(t2,nullptr);

}
