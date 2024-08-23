// 합이 S 이상이 되는 최소 길이.
// 앞의 값을 더해주었을 때 


#include <iostream>
#include <queue>
using namespace std;

int n,s;
int start=0, finish=0,minLen=1e9,len, sum;
int arr[100002];

void input(){
  cin>>n>>s;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
}

void solve(){
  while(true){
    if(sum<s){
      finish++;
      sum+=arr[finish];
      len++;
    }else{
      minLen = min(minLen, len);
      if(len==1){
        break;
      }else{
        start++;
        sum-=arr[start];
        len--;
      }
    }

    if(finish<start) break;
    if(finish==n && sum<s) break;
    else if(start==n && sum>=s){
      minLen = 1;
      break;
    }
  }
}

int main(){
  input();
  solve();
  if(minLen==1e9) cout<<0<<"\n";
  else cout<<minLen<<"\n";
  return 0;
}