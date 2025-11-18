#include <iostream>
#define INF 999999999;
using namespace std;

int n,m;
long arr[101][101];

void input(){
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j){
      if(i==j) arr[i][j]=0;
      else  arr[i][j] = INF;
    }
  int x,y,z;
  for(int i=0;i<m;++i){
    cin>>x>>y>>z;
    if(arr[x][y]<z) continue;
    else arr[x][y] = z;
  }
}

void floyd_warshall(){
  for(int k=1;k<=n;++k){
    for(int i=1;i<=n;++i){
      for(int j=1;j<=n;++j){
        if(arr[i][j] > arr[i][k]+arr[k][j])
          arr[i][j] = arr[i][k]+arr[k][j];
      }
    }
  }
}

int main(){
  input();
  floyd_warshall();
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      if(arr[i][j]==999999999) cout<<0<<" ";
      else cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}