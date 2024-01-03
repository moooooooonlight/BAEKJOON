#include <iostream>
#include <vector>
#include <queue>
#define MAX 999999
#define MAXV 20001
using namespace std;

int V,E,K;
vector<pair<int, int>> arr[MAXV];
int dist[MAX];

void input(){
  cin>>V>>E>>K;
  int x,y,z;
  for(int i=0;i<E;++i){
    cin>>x>>y>>z;
    arr[x].push_back(make_pair(y,z));
  }
  for(int i=1;i<=V;++i)
    dist[i] = MAX;
}

void Dijkstra(){
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, K));
  dist[K]=0;
  while(!pq.empty()){
    int cost = -pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if(dist[node]<cost) continue;
    for(int i=0;i<arr[node].size();++i){
      int next = arr[node][i].first;
      int nextcost = cost + arr[node][i].second;
      if(dist[next]>nextcost){
        dist[next] = nextcost;
        pq.push(make_pair(-nextcost,next));
      }
    }
  }
  for(int i=1;i<=V;++i){
    if(dist[i]==MAX) cout<<"INF"<<endl;
    else cout<<dist[i]<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  Dijkstra();
  return 0;
}