#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k;
vector<int> arr[1001];
int dr[1001];
int br[1001];
bool dv[1001];
bool bv[1001];
int number= 1;

void BFS(){
    number= 1;
    queue<int> q;
    q.push(k);
    bv[k]=true;
    br[number++]= k;
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0;i<arr[x].size();++i){
            if(!bv[arr[x][i]]){
                bv[arr[x][i]]=true;
                br[number++]=arr[x][i];
                q.push(arr[x][i]);
            }
        }
    }
}


void DFS(int x){
    dv[x]=true;
    dr[number++] = x; 
    for(int i=0;i<arr[x].size();++i){
        if(!dv[arr[x][i]]) DFS(arr[x][i]);
    }
}

int main(){
    cin>>n>>m>>k;
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        sort(arr[i].begin(),arr[i].end());
    }
    DFS(k);
    BFS();
    for(int i=1;i<=n;++i)
        if(dr[i]!=0) cout<<dr[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;++i)
      if(br[i]!=0) cout<<br[i]<<" ";    
    return 0;    
}