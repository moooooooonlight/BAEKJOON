#include <iostream>

using namespace std;

void min(int x, int y) {
    int k = x * y;
    int term;
    while (y) {
        term = x % y;
        x = y;
        y = term;
    }
    cout << x<<endl;
    cout << k / x<<endl;
}


int main(void) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        min(a, b);
    }
    else {
        min(b, a);
    }


    return 0;
}