#include<bits/stdc++.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
using namespace std;
#define nl '\n'
typedef long long ll;

void* print_f(void* arg)
{
    for(int i=0;i<5;i++)
    {
        cout<<i<<nl;
        sleep(1);
    }
    return nullptr;
}

int main()
{
    pthread_t th1;
    pthread_create(&th1,nullptr,print_f,nullptr);

    pthread_join(th1,nullptr);

    for(int i=5;i<10;i++)
    {
        cout<<i<<nl;
    }
    
}
