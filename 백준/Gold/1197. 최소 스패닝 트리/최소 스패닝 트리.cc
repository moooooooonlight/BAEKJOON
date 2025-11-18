#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,sum=0;
int parent[10001];
priority_queue<pair<int , pair<int,int>>> pq;

void input(){
  cin>>n>>m;
  int a,b,c;
  for(int i=0;i<m;++i){
    cin>>a>>b>>c;
    pq.push(make_pair(-c,make_pair(a,b)));
  }
  for(int i=1;i<=n;++i)
    parent[i]=i;
}

int find(int k){
  if(parent[k]==k){
    return k;
  }else return parent[k] = find(parent[k]);
}

void union_(int x, int y){
  x = find(x);
  y = find(y);
  parent[y] = x;
}

bool cycle(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return true;
  else return false;
}

void kruskal(){
  while(!pq.empty()){
    int v = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();
    if(!cycle(x,y)){
      union_(x,y);
      sum+=-v;
    }
  }
  cout<<sum<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  input();
  kruskal();
  return 0;
}