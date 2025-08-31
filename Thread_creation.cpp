#include<bits/stdc++.h>
#include<unistd.h>      // for fork() and getpid()
#include<sys/types.h>   //for pid_t
#include<sys/wait.h>
#include<pthread.h>
using namespace std;
typedef long long ll;
#define nl '\n'

void *thread_fun(void *start)
{
    ll st=*(ll *)(start);
    for(;st<=10;st++)
    {
        cout<<st<<nl;
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread1;
    ll start=1;
    
    pthread_create(&thread1,NULL,thread_fun,(void *) &start);
    pthread_join(thread1,NULL);
    
    cout<<nl;
    for(ll i=4;i<=10;i++)
    {
        cout<<i<<nl;
    }
    
    
}
