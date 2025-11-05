    #include<bits/stdc++.h>
    using namespace std;
    #define nl '\n'
    typedef long double ld;
    
    struct Pr{
        int pid,arrival_time,burst_time;
        ld turnAround_time=0,waiting_time=0,comp_time=0,start_time=0;
    };

    int main(){
        int n;  cin>>n;
        vector<Pr>p(n);

        for(int i=0;i<n;i++){
            cin>>p[i].arrival_time>>p[i].burst_time;
            p[i].pid=i+1;
        }

        sort(p.begin(),p.end(),[](auto &a,auto &b){
            return a.arrival_time<b.arrival_time;
        });

        int time=0;

        for(int i=0;i<n;i++){
            if(time<p[i].arrival_time) time=p[i].arrival_time;

            p[i].start_time=time;
            p[i].comp_time=time+p[i].burst_time;
            p[i].turnAround_time=p[i].comp_time-p[i].arrival_time;
            p[i].waiting_time=p[i].turnAround_time-p[i].burst_time;
            time=p[i].comp_time;
        }

        ld tlt_waiting_time=0,tlt_turnAround_time=0;
        for(int i=0;i<n;i++){
            tlt_waiting_time+=p[i].waiting_time;
            tlt_turnAround_time+=p[i].turnAround_time;
        }

        cout<<"Total waiting time is: "<<tlt_waiting_time*1.0/n<<nl;
        cout<<"Total turnaround time is: "<<tlt_turnAround_time*1.0/n<<nl;

        for(auto it:p)
        cout<<it.pid<<" "<<it.arrival_time<<" "<<it.burst_time<<nl;

    }
