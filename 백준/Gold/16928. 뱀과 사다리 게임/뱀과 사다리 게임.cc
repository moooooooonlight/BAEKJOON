#include <iostream>
#include <queue>

using namespace std;

int n, m, MIN = 7;
int arr[101];
bool visited[101];
int dist = 0, D=0;
void findway(int cur, int d);

int main(){
  cin >> n >> m;
  int x,y;
  for(int i=0;i<n+m;++i){
    cin>>x>>y;
    arr[x] = y;
  }

  findway(1, 0);
  return 0;  
}

void findway(int cur, int c){
  queue<pair<int,int>>q;
  q.push(make_pair(cur,c));
  while(!q.empty()){
    int current = q.front().first;
    int count = q.front().second;
    q.pop();

    for(int i=1;i<=6;++i){
      int next = current + i;
      if(next == 100){
        cout<<count+1;
        return ;
      }else if(next<100){
        while(arr[next]!=0){
          next = arr[next];
        }
        if(!visited[next]){
          q.push(make_pair(next, count+1));
          visited[next] = true;
        }
      }
    }
  }
}