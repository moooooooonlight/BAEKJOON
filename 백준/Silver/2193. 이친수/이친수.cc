#include <iostream>
using namespace std;

class point {
public:
  long zero;
  long one;
  long data;
};

int main() {
  int n;
  cin >> n;
  point p[100]={{0,0,0}};
  p[1].one = 1;
  p[1].zero = 0;
  p[1].data = 1;
  for (int i = 2; i <= n;++i) {
    p[i].one = p[i-1].zero;
    p[i].zero = p[i-1].one+p[i-1].zero;
    p[i].data =p[i].one + p[i].zero;
  }
  cout<<p[n].data<<endl;
  return 0;
}