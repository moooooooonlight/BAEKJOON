#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> arr[501];
vector<int> order;
int price[501];
int value[501];
bool visited[501];

void input(){
  cin>>N;
  int v,x;
  for(int i=1;i<=N;++i){
    cin>>v;
    price[i] = v;
    value[i] = v;
    cin>>x;
    while(x!=-1){
      arr[x].push_back(i);
      cin>>x;
    }
  }
}

void DFS(int s){
  visited[s] = true;
  for(int i=0;i<arr[s].size();++i){
    if(!visited[arr[s][i]]){
      DFS(arr[s][i]);
    }
  }
  order.push_back(s);
}

void BFS(){
  queue<int> q;
  for(int i=order.size()-1;i>=0;--i){
    if(!visited[order[i]]){
      q.push(order[i]);
      while(!q.empty()){
        int x = q.front();
        q.pop();
        visited[x] = true;
        for(int k=0;k<arr[x].size();++k){
          if(value[arr[x][k]]<price[arr[x][k]]+value[x]){
            value[arr[x][k]]=price[arr[x][k]]+value[x];
            q.push(arr[x][k]);
          }
        }
      }
    }
  }
  for(int i=1;i<=N;++i)
    cout<<value[i]<<endl;
}


void topological_sorting(){
  for(int i=1;i<=N;++i){
    if(!visited[i]){
      DFS(i);
    }
  }
  for(int i=1;i<=500;++i)
    visited[i] = false;
}

int main(){
  input();  
  topological_sorting();
  BFS();
  return 0;
}