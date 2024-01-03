#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define BMAX 100001
#define INF 999999999
using namespace std;

int n,m;
vector<pair<int, int>> BUS[MAX];
int start,dest;
int dist[MAX];

void input(){
  cin>>n>>m;
  int a,b,c;
  for(int i=0;i<m;++i){
    cin>>a>>b>>c;
    BUS[a].push_back(make_pair(b, c));
  }
  cin>>start>>dest;
  for(int i=1;i<=n;++i)
    dist[i] = INF;
}

void Dijkstra(){
  priority_queue<pair<int, int>> pq; // 어떤거 기준인가?
  pq.push(make_pair(0, start));
  dist[start] = 0;

  while(!pq.empty()){
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    if(dist[cur]<cost)
      continue;
    for(int i=0;i<BUS[cur].size();++i){
      int next = BUS[cur][i].first;
      int nextcost = cost + BUS[cur][i].second;
      if(dist[next]>nextcost){
        dist[next] = nextcost;
        pq.push(make_pair(-nextcost,next));
      }
    }
  }
  cout<<dist[dest]<<endl;
}

int main(){
  input();
  Dijkstra();
  return 0;
}