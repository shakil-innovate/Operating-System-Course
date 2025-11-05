#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define s second
#define f first

struct Pr{
    int pid,arrival_time,burst_time;
    int rem_time,turnaround_time,waiting_time,complete_time,start_time=-1;
};

int main(){
    int n;      cin>>n;
    vector<Pr>p(n);

    for(int i=0;i<n;i++){
        cin>>p[i].arrival_time>>p[i].burst_time;
        p[i].rem_time=p[i].burst_time;
    }

    sort(p.begin(),p.end(),[](auto &a,auto &b){
        return a.arrival_time < b.arrival_time;
    });

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({p[0].rem_time,0});
    int time=p[0].arrival_time;
    vector<bool>isQueue(n+1,0);

    while(!pq.empty()){
        int ind=pq.top().s;
        pq.pop();

        time=max(time,p[ind].arrival_time);
        if(p[ind].start_time==-1)  p[ind].start_time=time;

        if(p[ind].rem_time>0){
            time++;
            p[ind].rem_time--;
        }
        if(p[ind].rem_time==0){
            p[ind].complete_time=time;
            p[ind].turnaround_time=time-p[ind].arrival_time;
            p[ind].waiting_time=p[ind].turnaround_time-p[ind].burst_time;
        }
        else{
            pq.push({p[ind].rem_time, ind});
        }

        for(int i=0;i<n;i++){
            if(p[i].arrival_time<=time && isQueue[i]==0){
                isQueue[i]=1;
                pq.push({p[i].rem_time,i});
            }
        }

        if(pq.empty()){
            for(int i=0;i<n;i++){
                if(isQueue[i]==0){
                    isQueue[i]=1;
                    pq.push({p[i].rem_time,i});
                    break;
                }
            }
        }
    }

    int tlt_turnAround_time=0,tlt_waiting_time=0;
    for(int i=0;i<n;i++){
        tlt_turnAround_time+=p[i].turnaround_time;
        tlt_waiting_time+=p[i].waiting_time;
    }

    cout<<"Total turnaround time is: "<<tlt_turnAround_time*1.0/n<<nl;
    cout<<"Total waiting time is: "<<tlt_waiting_time*1.0/n<<nl;
}
