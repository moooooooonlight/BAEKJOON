#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

#define MAX 100

void input(int &n, int &l){
    cin>> n >> l;
}


int main(){
    int N,L;
    input(N,L);

    for(int i=L;i<=100;i++){
        int l = (i - 1) * i / 2;
        int n = N - l;

        if (n < 0)
        {
            continue;
        }

        if (n % i == 0)
        {
            int start = n / i;

            while (i--)
            {
                cout << start++ << " ";
            }
            return 0;
        }
    }

    cout << -1;
    return 0;
}