#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
int arr[101][101];
int dist[101][101];
int nX[4] = {0,0,-1,1};
int nY[4] = {-1,1,0,0};

void input(){
    cin>>m>>n;
      string str;
      char ch[100];
    for(int i=1;i<=n;++i){
        cin>>str;
       strcpy(ch,str.c_str());
        for(int k=1;k<=str.length();++k){
            arr[i][k] = ch[k-1] - '0';
            dist[i][k] = 1e9;
        }
    }
  dist[1][1] = 0;
}


void BFS(){
    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i=0;i<4;++i){
            int nextA = a+nX[i];
            int nextB = b+nY[i];
            if(nextA>0 && nextA<=n && nextB>0 && nextB<=m){
                if(arr[nextA][nextB]==1){
                  if(dist[nextA][nextB]>dist[a][b]+1){
                    dist[nextA][nextB] = dist[a][b]+1;
                    q.push({nextA,nextB});
                  }
                }else if(arr[nextA][nextB]==0){
                    if(dist[nextA][nextB]>dist[a][b]){
                      dist[nextA][nextB] = dist[a][b];
                      q.push({nextA,nextB});
                    }
                }
            }
        }

    }
}


int main(){   
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL); 
  
    input();
    BFS();
    cout<<dist[n][m]<<endl;
    return 0;
}