#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  int x,k;
  cin>>x>>k;
  long arr[100002];
  int MAX=999999;
  
  fill(arr+1,arr+100001,999999);
  arr[x]=999999;
  arr[0]=999999;
  
  queue<pair<int,int>> q;
  q.push({x,0});
  while(!q.empty()){
    int move = q.front().first;
    int value = q.front().second;
    q.pop();
    if(move==k){
      if(MAX>value) MAX = value;
    }
    if(arr[move]>value){
      arr[move] = value;
      if(move>=1) q.push({move-1,value+1});
      if(move<100000) q.push({move+1,value+1});
      if(2*move<=100000) q.push({move*2,value+1});
    }
  }
  cout<<MAX;
  return 0;
}