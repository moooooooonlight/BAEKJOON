#include <iostream>
#define INF 999999;
using namespace std;

int n;
int arr[100][100];
int result[100][100];

void input(){
  cin>>n;
  for(int i=0;i<n;++i){
    for(int k=0;k<n;++k){
      cin>>arr[i][k];
      if(arr[i][k]==1)
        result[i][k]=1;
      else
        result[i][k]=0;
    }
  }
}

void floyd_warshall(){
  for(int t=0;t<2;++t){
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        for(int k=0;k<n;++k){
          if(result[i][j]!=0) break;
          else{
            if(result[i][k]!=0 && result[k][j]!=0){
              result[i][j] = 1;
            }
          }
        }
      }
    }
  }
}

int main(){
  input();
  floyd_warshall();
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j)
      cout<<result[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}