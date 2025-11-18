#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

void input(int &n, int &m,char** board){
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            cin >> board[i][k];
        }
    }
}

int countMinCnt(int startRow, int startCol, char** board){
    int count = 0;
    char first = board[startRow][startCol];

    for (int i = 0; i < 8; i++) {
        for (int k = 0; k < 8; k++) {

            char expected;

            if(((i + k) % 2 == 0)){
                expected = first;
            }else{
                expected = ((first=='W') ? 'B' : 'W');
            }

            if(board[startRow+i][startCol+k] != expected)
                count++;
        }
    }

   return min(count, 64 - count);
}

int findMinChanged(int n, int m, char** board){
    int result = 64;
    
    for (int i = 0; i <= n - 8; i++) {
        for (int k = 0; k <= m - 8; k++) {
            result = min(result, countMinCnt(i, k, board));
        }
    }
    
    return result;
}

// 정상 체스판을 만드는 최소 개수 구하기
int main(){
    int n,m;
    cin>>n>>m;
    char** board = (char **)malloc(n * sizeof(char *));
    for(int i=0;i<n;i++){
        board[i] = (char *)malloc(m*sizeof(char));
    }

    // 현재 체스판 상태 입력 받기
    input(n,m, board); 
    
    // 개수 계산.
    cout<<findMinChanged(n, m, board)<<endl; 

    // 동적 할당 제거
    for(int i=0; i<n; i++){
        free(board[i]);
    }
    free(board);

    return 0;
}