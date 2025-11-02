#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

#include<pthread.h>

void* createFile(void* arg){
    string file_name=*(string*)arg;
    cout<<file_name<<endl;
    ofstream file(file_name);
    file.close();
    return nullptr;
}

void* copyFile(void* arg){
    string* files=(string*)arg;

    ifstream src(files[0],ios::binary);
    ofstream dst(files[1],ios::binary);

    dst << src.rdbuf();
    return nullptr;
}

int main(){
    pthread_t t1,t2;
    string file1="example.txt";
    pthread_create(&t1,nullptr,createFile,&file1);
    pthread_join(t1,nullptr);

    string files[2]={"file_handling.cpp","nw_file_hand.cpp"};

    pthread_create(&t2,nullptr,copyFile,&files);
    pthread_join(t2,nullptr);

    remove("example.txt");
}
