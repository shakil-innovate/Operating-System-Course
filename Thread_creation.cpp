#include<bits/stdc++.h>
#include<unistd.h>      // for fork() and getpid()
#include<sys/types.h>   //for pid_t
#include<sys/wait.h>
#include<pthread.h>
using namespace std;
typedef long long ll;
#define nl '\n'

void* print(void* arg)
{
    ll* x=(ll*) arg;
    cout<<"IN child thread x is: "<<*x<<nl;

    ll* sum=new ll();
    *sum=2*(*x);

    return (void*) sum;
}
int main()
{
    ll x=40;
    pthread_t thread1;

    pthread_create(&thread1,nullptr,print,&x);
      void* sum;
    pthread_join(thread1,&sum);

    ll* _sum=(ll*)sum;
    cout<<"IN main thread: "<<*_sum<<nl;
  
    return 0;


}
