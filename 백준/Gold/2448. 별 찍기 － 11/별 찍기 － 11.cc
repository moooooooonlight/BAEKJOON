#include <iostream>
using namespace std;

int n;
char arr[3073][6145];

void pick(int h,int w){ // 높이, n-a = 시작 위치.
    if(h==n){
        return;    
    }

    //위의 값을 시작 위치에서 복사하는 코드
    for(int i=1;i<=h;++i){
        for(int j=n-w;j<=n+w;++j){
            arr[h+i][j-w] = arr[i][j];   
        }
        for(int j=n-w;j<=n+w;++j){
            arr[h+i][j+w] = arr[i][j];
        }
    }
    pick(h*2,w*2);
}

int main(){
    cin>>n;

    //1번
    arr[1][n] = '*';
    //2번
    arr[2][n-1] = '*';
    arr[2][n+1] = '*';
    //3번
    for(int i=n-2;i<=n+2;++i)
        arr[3][i] = '*';

    pick(3,3);

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n*2;++j){
            if(arr[i][j]!='*') cout<<" ";
            else cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}
