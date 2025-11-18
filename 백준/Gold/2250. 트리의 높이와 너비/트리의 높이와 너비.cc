#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> level[10001]; //레벨별 크기가 들은 값.
vector<int> parent[10001];
vector<pair<int,int>> arr[10001]; //자식 + 레벨
int n,root;

void input(){
    cin>>n;
    int x,y,z;
    for(int i=0;i<n;++i){
        cin>>x>>y>>z;
        arr[x].push_back({y,0});
        arr[x].push_back({z,0});
        if(y!=-1) parent[y].push_back(x);
        if(z!=-1) parent[z].push_back(x);  
    }
    for(int i=1;i<=n;++i){
        if(parent[i].size()==0) {
          root=i;
          break;
        }
    }
}

int w=1,MAX_lev=0;
void inorder(int a, int b){ // 값 + 레벨
    if(MAX_lev<b) MAX_lev = b;
    if(arr[a][0].first!=-1)inorder(arr[a][0].first, b+1);
    level[b].push_back(w++);
    if(arr[a][1].first!=-1) inorder(arr[a][1].first, b+1);
}

int main(){
    input();
    inorder(root,1); // 위치를 알아내는 방법 -> 넓이 구하기 가능.
    int MAX = 0, MAX_p=0;
    for(int i=1;i<=MAX_lev;++i){
        sort(level[i].begin(),level[i].end());
        int x = level[i][level[i].size()-1]-level[i][0];
        if(MAX<x){
            MAX = x;
            MAX_p = i;
        }
    }
  if(MAX==0) cout<<1<<" "<<1;
  else cout<<MAX_p<<" "<<MAX+1;
    return 0;
}

// 각 레벨의 넓이 = 가장 오른쪽 열 번호 - 가장 왼쪽 번+1
// 구해야 하는 것. = 넓이가 가장 넓은 레벨. 그리고 그 넓이
// 레벨에 따른 넓이를 알기 위해서 각 레벨별로 가장 왼쪽 가장 오른쪽이 어디인지를 알아야 함. 
// 그 위치를 알려면? => BFS를 하면 각각의 레벨은 알 수 있음.
// 레벨별로 위치는 어떻게 알아? => DFS로 위치를 구할 수 있음. 
// 레벨별 연결리스트를 만들어서 가장 큰수 - 가장 작은 수 한 값들의 가장 큰 수가 답이다.
// 계속 실패 -> 루트가 1이 아닐 수 있었음.
// 그럼 누가 루트인지 어떻게 찾아? -> 