#include <iostream>
using namespace std;

int n,m;
int r,c,d;
int arr[51][51];
bool visited[51][51];

void input(){
    cin>>n>>m;
    cin>>r>>c>>d;
    int x;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>x;
            arr[i][j] = x;
        }
    }
}

int sum=0;

void solve(){
    //기준이 r,c
    while(true){
        if(visited[r][c] == false && arr[r][c]==0){
            visited[r][c] = true;
            sum++;
        }

        bool check = false;
        //개수 확인하기.

        if(r-1>=0 &&  visited[r-1][c]==false && arr[r-1][c]!=1) check = true;
        if(r+1<n && visited[r+1][c]==false && arr[r+1][c]!=1) check = true;
        if(c-1>=0 && visited[r][c-1]==false && arr[r][c-1]!=1) check = true;
        if(c+1<m && visited[r][c+1]==false && arr[r][c+1]!=1) check = true;


        //청소할게 없을 때 멈출지 후진할지.
        if(!check){
            if(d==0){
                if(arr[r+1][c]==1){
                    break;
                }else r=r+1;
            }else if(d==1){
                if(arr[r][c-1]==1){
                    break;
                }else c=c-1;
            }else if(d==2){
                if(arr[r-1][c]==1){
                    break;
                }else r=r-1;
            }else if(d==3){
                if(arr[r][c+1]==1){
                    break;
                }else c=c+1;
            } 
        }else{
            //청소해야함 d를 고려해서.
            d-=1;
            if(d<0) d+=4;
            if(d==0 && r-1>=0 && visited[r-1][c]==false && arr[r-1][c]!=1)
            { r=r-1;}
            else if(d==1 && c+1<m && visited[r][c+1]==false && arr[r][c+1]!=1)
            { c=c+1;}
            else if(d==2 && r+1<n && visited[r+1][c]==false && arr[r+1][c]!=1)
            { r=r+1;}
            else if(d==3 && c-1>=0 && visited[r][c-1]==false && arr[r][c-1]!=1)
            { c=c-1;}
        }
    }
}

int main(){
    input();
    solve();
    cout<<sum<<endl;
    return 0;
}