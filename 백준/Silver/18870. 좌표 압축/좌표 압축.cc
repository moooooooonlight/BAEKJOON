#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 1000001
using namespace std;

int n;
long long arr[MAX];
vector<pair<long long,int>> v; // 순서.
long long result[MAX];

void input(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    v.push_back({arr[i],i});
  }
  sort(v.begin(), v.end());
}

void solve(){
  int count = 0;
  for(int i=0;i<v.size();i++){
    int index = v[i].second;
    if(i>0 && v[i-1].first == v[i].first){
      result[index] = result[v[i-1].second];
      v[i].second = v[i-1].second;
    }
    else {
      result[index] = count;
      count++;
    }
  }
  for(int i=0;i<n;i++){
    cout<<result[i]<<" ";
  }
}

int main(){
  input();
  solve();
  return 0;
}
