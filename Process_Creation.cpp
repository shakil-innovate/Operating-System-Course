#include<bits/stdc++.h>
#include<unistd.h>      // for fork() and getpid()
#include<sys/types.h>   //for pid_t
#include<sys/wait.h>    //for wait()
#define nl '\n'
using namespace std;

int main()
{
    pid_t check=fork();      //it return a positive id to parent and 0 to child
                             // and -1 to process failed
    fork();                  //duplicate a process from here
    
    if(check>0)
    {
        cout<<"Parent Process"<<endl<<getpid()<<nl;
    }
    else if(check==0)
    {
        cout<<"Child Process"<<nl<<getpid()<<nl;
    }
    else
    {
        cout<<"Process Failed"<<nl;
    }
}
