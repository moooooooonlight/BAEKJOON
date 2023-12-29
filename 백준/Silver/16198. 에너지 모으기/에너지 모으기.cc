#include <iostream>
using namespace std;

int n,sum=0,MAX=0;
int *arr;
bool visited[10]={false};

void del(int x);

int main(){
  cin>>n;
  arr = new int[n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }

  for(int i=1;i<n-1;++i){
    visited[i]=true;// 1부터 뺀다는 것.
    int x=i,y=i;
    while(true)
      if(!visited[--x])
        break;
    while(true)
      if(!visited[++y])
        break;
    sum+= arr[x]*arr[y]; // 에너지 더하기.
    del(n-1);
    sum-= arr[x]*arr[y];
    visited[i] = false;
  }
  cout<<MAX;
  return 0;
}

void del(int x){// 남은 개수.
  if(x==2){ //남은 개수가 2개 남았을 때
    if(sum>MAX) MAX = sum;
    return;
  }
  for(int i=1;i<n-1;++i){
    if(visited[i] == false){
      visited[i] = true;
      int z=i,y=i;
      while(true)
        if(!visited[--z])
          break;
      while(true)
        if(!visited[++y])
          break;
      sum+= arr[z]*arr[y]; // 에너지 더하기.
      del(x-1);
      sum-= arr[z]*arr[y];
      visited[i] = false;
    }
  }
}