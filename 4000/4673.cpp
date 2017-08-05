#include <iostream>
using namespace std;

bool arr[10001];

int main() {
	arr[1] = false;

	for (int i = 1; i < 10001; i++) {
		int a = 0;
		int tmp = i;
		int mod = 1000;
		while (mod > 0) {
			a += tmp / mod;
			tmp = tmp % mod;
			mod /= 10;
		}

		arr[i + a] = true;
	}

	for (int i = 1; i < 10001; i++)
		if (arr[i] == false)
			cout << i << endl;

	return 0;
}