#include <iostream>
#include <queue>
using namespace std;

int n,m,sum=0;
int arr[500][500];
bool visited[500][500];
int MAX = 0, sum1=0;
int x[4] = {0,1,-1};
int y[4] = {0,1,0,1};

void input(){
  cin>>n>>m;
  for(int i=0;i<n;++i){
    for(int k=0;k<m;++k){
      cin>>arr[i][k];
    }
  }
}

void BFS(int a, int b){
  queue<pair<int,int>> q;
  q.push({a,b});
  sum++;
  sum1=0;
  while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      if(!visited[x][y]){
      visited[x][y]=true;
      sum1++;
      if(x+1<n &&y<m && !visited[x+1][y] && arr[x+1][y]==1) q.push({x+1,y});
      if(x<n &&y+1<m && !visited[x][y+1] && arr[x][y+1]==1) q.push({x,y+1});
        if(x-1>=0 &&y<m && !visited[x-1][y] && arr[x-1][y]==1) q.push({x-1,y});
        if(x<n &&y-1>=0 && !visited[x][y-1] && arr[x][y-1]==1) q.push({x,y-1});
    }
  }
  if(MAX<sum1) MAX=sum1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  for(int i=0;i<n;++i){
    for(int k=0;k<m;++k){
      if(!visited[i][k] && arr[i][k]==1) BFS(i,k);
    }
  }
  cout<<sum<<endl;
  cout<<MAX<<endl;
  return 0; 
}