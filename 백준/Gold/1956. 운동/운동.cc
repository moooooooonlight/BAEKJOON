#include <iostream>
#include <algorithm>
using namespace std;

int n,m,MIN=999999999;
int arr[401][401];

void input(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int k=1;k<=n;++k){
            arr[i][k] = 999999999;
        }
    }
    for(int i=0;i<m;++i){
      int a,b,c;
      cin>>a>>b>>c;
        arr[a][b] = c;
    }
}

void floyd(){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j]= arr[i][k]+arr[k][j];
            }
        }
    }

    for(int i=1;i<=n;++i){
        MIN = min(MIN,arr[i][i]);   
    }
  if(MIN==999999999) cout<<-1;
  else cout<<MIN;

}

int main(){
    input();
    floyd();
    return 0;
}