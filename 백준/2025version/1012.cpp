#include <iostream>
using namespace std;

int x[4] = {0,0,1,-1};
int y[4] = {-1,1,0,0};

void input(int k, int **arr){
    int x,y;
    for(int i=0;i<k;i++){
        cin >> x >> y;
        arr[x][y] = 1;
    }
}

void dfs(int m, int n, int **arr, int startX, int startY){
    arr[startX][startY] = 0;

    for(int j=0;j<4;j++){
        int nextX = startX+x[j];
        int nextY = startY+y[j];
        
        if (nextX<0 || nextX>=m || nextY <0 && nextY>=n){
            continue;
        }

        if(arr[nextX][nextY]==1){
            dfs(m, n, arr, nextX, nextY);
        }
    }
}

int search(int m, int n, int **arr){
    int sum = 0;
    for(int i=0;i<m;i++){
        for(int k=0;k<n;k++){
            if(arr[i][k]==1){
                sum++;
                dfs(m, n, arr, i,k);
            }
        }
    }
    return sum;
}

int main(){
    int t;
    int m,n,k;
    cin >> t;

    for(int i=0;i<t;i++){
        cin>> m >> n >> k;
        int **arr = new int*[m];
        for(int i=0;i<m;i++){
            arr[i] = new int[n];
        }

        input(k, arr);
        cout << search(m, n, arr) << endl;
    
        for(int i=0;i<m;i++){
            delete[] arr[i];
        }
        delete[] arr;
    }

    return 0;
}