// 두 용액을 합쳐서 특성값이 0에 가까운 값 만들기
// 두 용액을 찾아야함.
// 백트레킹?
// 0에 가장 가까운 값을 구하는거.
// 최대 = 벡터 정렬 후 맨 끝 2숫자 더하기
// 최소 -99 최대 98.
// 만약에 최소값이 더 커 -> 왼쪽에서 움직임.
// 만약에 최대값이 더 커 -> 오른쪽에서 움직임.
// 3 -3


#include <iostream>
#include <vector>
using namespace std;


int n;
long long Left, Right, MIN=2000000000;
long long result_L, result_R;
vector<long long> v;

void input(){
  cin>>n;
  int x;
  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }
}

void solve(){
  Left = 0;
  Right = n-1;

  
  while(Left < Right){
    int sum = v[Left] + v[Right];
    if(abs(sum)<MIN){
          MIN = abs(sum);
      result_L = v[Left];
      result_R = v[Right];
    }
    
    if(abs(v[Left]) > abs(v[Right])) {
      Left++;
    }else{
      Right--;
    }
  }
}

int main(){
  input();
  solve();
  cout<<result_L<<" "<<result_R<<"\n";
  return 0;
}