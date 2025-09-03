#include<bits/stdc++.h>
#include<sys/types.h>  //for pid_t
#include<sys/wait.h>   //for wait()
#include<unistd.h>    // for fork() and getpid
#include<signal.h>    //  for kill

using namespace std;
#define nl '\n'

int main()
{
   pid_t check=fork();

   fork();
   if(check>0)
   {
    cout<<"Parent thread and id is:"<<getpid()<<nl;
    cout<<"Parent check "<<check<<nl;
   }

//    exit(0);

   if(check==0)
   {
    cout<<"Child thread and id is: "<<getpid()<<nl;
    cout<<"Child check :"<<check<<nl;
   }
}
