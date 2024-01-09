#include <iostream>
#include <vector>
#define INF 999999999;
using namespace std;

int TC;
int N,M,W;
vector<pair<pair<int,int>,int>> arr;
vector<string> result;
long dist[501];
bool check;

void input(){
  cin>>N>>M>>W;
  int S,E,T;
  for(int i=0;i<=N;++i)
    dist[i] = INF;
  for(int i=0;i<M;++i){
    cin>>S>>E>>T;
    arr.push_back({{S,E},T});
    arr.push_back({{E,S},T});
  }
  for(int i=0;i<W;++i){
    cin>>S>>E>>T;
    arr.push_back({{S,E},-T});
  }
}

void bellman_ford(){

  for(int i=0;i<N;++i){
    for(int k=0;k<arr.size();++k){
      int from = arr[k].first.first;
      int to = arr[k].first.second;
      int distant = arr[k].second;

      if(dist[to]>dist[from]+distant){
        dist[to] = dist[from]+distant;
      }
    }
  }
  check = false;
  for(int i=0;i<arr.size();++i){
    int from = arr[i].first.first;
    int to = arr[i].first.second;
    int distant = arr[i].second;
    if(dist[to]>dist[from]+distant){
      check = true;
      return;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>TC;
  for(int i=0;i<TC;++i){
    input();
    bellman_ford();
    if(check) result.push_back("YES");
    else result.push_back("NO");
    arr.clear();
  }
  for(int i=0;i<result.size();++i)
    cout<<result[i]<<endl;
  return 0;  
}