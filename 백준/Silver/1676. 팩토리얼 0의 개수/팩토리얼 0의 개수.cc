#include <iostream>

using namespace std;
void two(int x);
void five(int x);
int tsum = 0;
int fsum = 0;

int main(void) {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}

	two(n);
	five(n);

	if (tsum > fsum) {
		cout << fsum;
	}
	else cout << tsum;

	return 0;
}

void two(int x) {
	int i = 1;
	while (x>=i) {
		int k = i;
		while (k%2 == 0) {
			tsum++;
			k /= 2;
		}
		i++;
	}
}

void five(int x) {
	int i = 1;
	while (x >= i) {
		int k = i;
		while (k % 5 == 0) {
			fsum++;
			k /= 5;
		}
		i++;
	}
}