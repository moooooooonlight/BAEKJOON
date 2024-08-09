// 여행 지도
// 각 지점의 높이.
// 

#include <iostream>
#include <stack>
#define MAX 501
using namespace std;

int n,m;
int height[MAX][MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void input(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int k=0;k<m;k++){
      cin>>height[i][k];
      dp[i][k] = -1;
    }
  }
}

int dfs(int x, int y){
  // 이미 지나간 경로
  if(x==n-1 && y==m-1) return 1;
  if(dp[x][y]!=-1) return dp[x][y];
  

  int &count= dp[x][y];
  count = 0;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx<0 || nx>=n || ny<0 && ny>=m) continue; 
    if(height[nx][ny]>=height[x][y]) continue;
    count += dfs(nx,ny);    
  }
  return count;
}

void solve(){
  visit[0][0] = true;
  cout<<dfs(0,0)<<"\n";
}

int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0); 
  
  input();
  solve();
  return 0;
}
