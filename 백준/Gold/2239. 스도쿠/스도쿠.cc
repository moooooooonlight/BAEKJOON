
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char c;
int map[11][11];
int posible[11];
vector<pair<int,int>> v;

// 입력 받기.
void input() {
  for (int i = 1; i <= 9; i++) {
    for (int k = 1; k <= 9; k++) {
      cin >> c;
      map[i][k] = c - '0';
      if(map[i][k] ==0)
        v.push_back({i,k});
    }
  }
}

bool check(int x, int y, int k){
  // 가로 세로
  for(int i=1;i<=9;i++){
    if(map[x][i] == k)
        return false;
  }
  for(int i=1;i<=9;i++){
    if(map[i][y] == k)
        return false;
  }

  // 네모 칸.
  int x1 = (x-1)/3*3 + 1;
  int y1 = (y-1)/3*3 + 1;
  for(int i=x1;i<x1+3;i++){
    for(int j=y1;j<y1+3;j++){
      if(map[i][j] == k)
        return false;
    }
  }
  return true;
}

void show(){
  for (int i = 1; i <= 9; i++) {
    for (int k = 1; k <= 9; k++) {
      cout<<map[i][k];
    }
    cout<<"\n";
  }
}

void solve(int r){
  if(r==v.size()){
    show();
    exit(0);
  }

  int x = v[r].first;
  int y = v[r].second;
  //가능한 숫자 확인
  for(int k=1;k<=9;k++){
    if(check(x,y,k)){
      map[x][y] = k;
      solve(r+1);
      map[x][y] = 0;
    }
  }
  return ;
}


int main() {
  input();
  solve(0);
  return 0;
}