#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n,m;
bool visited[32001]={false};
vector<int> arr[32001];
vector<int> result;

void input(){
  cin>>n>>m;
  int x,y;
  for(int i=0;i<m;++i){
    cin>>x>>y;
    arr[x].push_back(y);
  }
}

void DFS(int s){
  visited[s] = true;
  for(int i=0;i<arr[s].size();++i){
    if(visited[arr[s][i]]==false) DFS(arr[s][i]);
  }
  result.push_back(s);
}

void topological_sorting(){
  for(int i=1;i<=n;++i){
    if(!visited[i]){
      DFS(i);
    }
  }
}

int main(){
  input();
  topological_sorting();
  for(int i=result.size()-1;i>=0;--i)
    cout<<result[i]<<" ";
  return 0;
}