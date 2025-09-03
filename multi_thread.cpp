#include<bits/stdc++.h>
#include<pthread.h>
#include<sys/wait.h>
#include<sys/types.h>
using namespace std;
typedef long long ll;
#define nl '\n'

struct State
{
    ll start,end,sum;
    vector<ll>*v;
};

void* cal_sum(void* arg)
{
    State* data=(State*) arg;
    data->sum=0;

    for(ll i=data->start;i<data->end;i++)
    {
        data->sum+=(*(data->v))[i];
    }
    return nullptr;
}

int main()
{
    ll n;   n=10;
    vector<ll>v(n);
    iota(v.begin(),v.end(),1);

    State st1={0LL,n/2,0LL,&v};
    State st2={n/2,n,0LL,&v};

    pthread_t thread1,thread2;
    pthread_create(&thread1,nullptr,cal_sum,&st1);
    pthread_create(&thread2,nullptr,cal_sum,&st2);

    pthread_join(thread1,nullptr);
    pthread_join(thread2,nullptr);

    cout<<st1.sum+st2.sum<<nl;

}
