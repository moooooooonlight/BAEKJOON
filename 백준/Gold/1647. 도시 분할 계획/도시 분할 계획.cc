// n개의 집, m개의 길. 양방. 길 유지비.
// 마을 분할.
// 분리된 두 마을 사이에 필요없는 길은 없앤다.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int result, MAX;
vector<pair<int,pair<int,int>>> path;
int parent[100001];

void input(){
  cin>>n>>m;
  int a,b,c;
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    path.push_back({c,{a,b}});
  }
  sort(path.begin(), path.end());
}

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

void kruscal(){
  for(int i=1;i<=n;i++){
    parent[i]=i;
  }
  int cnt = 0;
  for(int i = 0; i < path.size(); i++){
      pair<int, pair<int,int>> curEdge;
      curEdge = path[i];
      int cost = curEdge.first;
      int now = curEdge.second.first;
      int next = curEdge.second.second;

      if(findParent(now) == findParent(next)) continue;

      unionParent(now, next);
      result += cost;
      MAX = max(MAX, cost);

      if(++cnt == n - 1) break;
  }
}

void solve(){
  // 전체 경로를 최소 프래닝 트리로 하나의 경로를 구한다음
  // 가장 유지비가 큰 경로를 제외하면 됨.
  kruscal();
}

int main(){
  input();
  solve();
  cout<<result - MAX <<"\n";
  return 0;
}
