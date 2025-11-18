#include<vector>
#include <queue>
using namespace std;

int n,m;
bool visited[100][100];
int arr[100][100];
int result[100][100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(){
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{0,0}});
    while(!q.empty()){
    	int d = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
       
        if(d>result[x][y] && result[x][y]!=0) continue;
       	result[x][y] = d;
        
        for(int i=0;i<4;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(arr[nx][ny]!=0 && nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny]){
                q.push({d+1,{nx,ny}});
                visited[nx][ny] = true;
            }
        }
    }
}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    for(int i=0;i<maps.size();++i){
        vector<int> a = maps[i];
        m = a.size();
        for(int j=0;j<a.size();++j){
            arr[i][j] = a[j];
        }
    }

    BFS();
    if(result[n-1][m-1]==0) answer = -1;
    else answer = result[n-1][m-1];
    return answer;
}

