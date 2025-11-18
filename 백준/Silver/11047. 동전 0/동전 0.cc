#include <iostream>
using namespace std;

int N,K;
int cnt = 0;
int coin[11];

// k원 만들기
void input(){
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>coin[i];   
  }
}

void solve(){
    for(int i=N-1;i>=0;i--){
        while(K>=coin[i]){
            K-=coin[i];
            cnt++;
        }
    }
}

int main(){
  input();
  solve();
  cout<<cnt<<"\n";
  return 0;
}