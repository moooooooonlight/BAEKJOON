#include <iostream>
#define MAX 17
using namespace std;

int n;
int cnt;
int map[MAX];

bool select(int x){
    for(int i=1;i<x;i++){
        if(map[x]==map[i] || x-i==abs(map[x]-map[i])){
            return false;
        }
    }

    return true;
}

void back(int x){
    if(x==n+1){
        cnt++;
        return;
    }

    for(int i=1;i<=n;i++){
        map[x] = i;

        if(select(x)){
            back(x+1);
        }
    }
}

int main(){
    cin>>n;
    back(1);
    cout<<cnt;
    return 0;
}