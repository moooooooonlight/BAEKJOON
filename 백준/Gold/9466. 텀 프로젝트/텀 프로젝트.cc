
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

int t,n , cnt;
int arr[MAX];
bool visit[MAX];
bool cycle[MAX];

void input(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
}

void cycle_check(int x){
  visit[x] = true;
  int next = arr[x];

  if(!visit[next]){
    cycle_check(next);
  }else if(!cycle[next]){
    // 방문은 했는데 아직 사이클이 아닌것.
    for(int i=next;i!=x;i=arr[i]){
      cnt++;
    }
    cnt++;
  }
  cycle[x] = true;
}

void solve(){
  for(int i=1;i<=n;i++){
    if(!visit[i]){
        cycle_check(i);
    }
  }
}

void init(){
  memset(visit, false, sizeof(visit));
  memset(cycle, false, sizeof(cycle));
  cnt = 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  for(int i=0;i<t;i++){
    input();
    solve();
    cout<<n-cnt<<"\n";
    init();
  }
  return 0;
}