    #include<bits/stdc++.h>
    using namespace std;
    #define nl '\n'
    typedef long double ld;
    
    struct Pr{
        int pid,arrival_time,burst_time;
        int turnAround_time=0,waiting_time=0,comp_time=0,start_time=-1,rem_time;
    };

    int main(){
        int n;      cin>>n;
        vector<Pr>p(n);
        int tq;     cin>>tq;

        for(int i=0;i<n;i++){
            cin>>p[i].arrival_time>>p[i].burst_time;
            p[i].pid=i+1;
            p[i].rem_time=p[i].burst_time;
        }

        sort(p.begin(),p.end(),[](auto &a, auto &b){
            return a.arrival_time < b.arrival_time;
        });

        queue<int>q;
        vector<bool>isQueue(n+1,0);
        isQueue[0]=1;

        q.push(0);
        int time=p[0].arrival_time;

        while(!q.empty()){
            int ind=q.front();
            q.pop();

            int exe_time=0;
            exe_time=min(tq,p[ind].rem_time);
            p[ind].rem_time-=exe_time;

            if(p[ind].start_time==-1) p[ind].start_time=time;
            time+=exe_time;

            for(int i=0;i<n;i++){
                if(isQueue[i]==0 && p[i].arrival_time <= time){
                    q.push(i);
                    isQueue[i]=1;
                }
            }

            if(p[ind].rem_time>0){
                q.push(ind);
            }
            else{
                p[ind].comp_time=time;
                p[ind].turnAround_time=p[ind].comp_time-p[ind].arrival_time;
                p[ind].waiting_time=p[ind].turnAround_time-p[ind].burst_time;
            }

            if(q.empty()){
                for(int i=0;i<n;i++){
                    if(p[i].rem_time>0){
                         time = max(time, p[i].arrival_time);
                        isQueue[i]=1;
                        q.push(i);
                        break;
                    }
                }
            }
        }

        int tlt_turnaround_time=0,tlt_waiting_time=0;
        for(int i=0;i<n;i++){
            tlt_turnaround_time+=p[i].turnAround_time;
            tlt_waiting_time+=p[i].waiting_time;
        }

        cout<<"Total turn around time: "<<tlt_turnaround_time*1.0/n<<nl;
        cout<<"Total waiting time : "<<tlt_waiting_time*1.0/n<<nl;

        for(auto it:p)
        cout<<it.pid<<" "<<it.arrival_time<<" "<<it.burst_time<<nl;

    }
