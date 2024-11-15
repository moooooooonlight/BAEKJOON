//가장 긴 수열을 찾아내라.
// 

#include <iostream>
#include <vector>
#define MAX 1002
using namespace std;

int n, result;
int arr[MAX];
int dp[MAX][2];
vector<int> ans;

void input(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>arr[i];
  }
}

void DP(){
  for(int i=1;i<=n;i++){
    for(int k=i+1;k<=n;k++){
      if(arr[i]<arr[k]){
        if(dp[k][0]<dp[i][0]+1){
          dp[k][0] = dp[i][0] + 1;
          dp[k][1] = i;
        }
      }
    }
  }
  int max_p = 1;
  for(int i=1;i<=n;i++){
    if(result < dp[i][0]){
      result = dp[i][0];
      max_p = i;
    }
  }
  cout<<result+1<<"\n";
  ans.push_back(arr[max_p]);
  if(max_p != 1){
    do{
      max_p = dp[max_p][1];
      ans.push_back(arr[max_p]);
    }while(dp[max_p][1] != 0);
  }
  
  for(int i=ans.size()-1;i>=0;i--){
    cout<<ans[i]<<" ";
  }
}

int main(){
  input();
  DP();
  
  return 0;
}