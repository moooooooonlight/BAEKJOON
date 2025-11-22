#include <iostream>
#include <sstream>
#include <string>
using namespace std;

pair<int,int> moveDelta(const string& cmd){
    if(cmd == "R") return {1, 0};
    if(cmd == "L") return {-1, 0};
    if(cmd == "B") return {0, -1};
    if(cmd == "T") return {0, 1};
    if(cmd == "RT") return {1, 1};
    if(cmd == "LT") return {-1, 1};
    if(cmd == "RB") return {1, -1};
    if(cmd == "LB") return {-1, -1};
    return {0, 0};
}

bool isValid(int x, int y){
    return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

int main(){
    string kingPos, stonePos;
    int moveCnt;

    cin >> kingPos >> stonePos >> moveCnt;

    int kingX = kingPos[0] - 'A' + 1;
    int kingY = kingPos[1] - '0';

    int stoneX = stonePos[0] - 'A' + 1;
    int stoneY = stonePos[1] - '0';

    while(moveCnt--){
        string cmd;
        cin >> cmd;

        pair<int, int> delta = moveDelta(cmd);

        int nextKingX = kingX + delta.first;
        int nextKingY = kingY + delta.second;

        if(!isValid(nextKingX, nextKingY))
            continue;
        
        if(nextKingX == stoneX && nextKingY == stoneY){
            int nextStoneX = stoneX + delta.first;
            int nextStoneY = stoneY + delta.second;

            if(!isValid(nextStoneX, nextStoneY))
                continue;

            stoneX = nextStoneX;
            stoneY = nextStoneY;
        }

        kingX = nextKingX;
        kingY = nextKingY;
    }

    char kingAlpha = 'A' + kingX - 1;
    char stoneAlpha = 'A' + stoneX - 1;

    cout << kingAlpha << kingY << "\n";
    cout << stoneAlpha << stoneY << "\n";
}