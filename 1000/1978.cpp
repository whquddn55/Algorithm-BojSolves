#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int uint;

bool isPrime(const uint& a);

int main() {
	uint n;
	cin >> n;

	uint cnt = 0;
	uint a;
	for (uint i = 0; i < n; i++) {
		cin >> a;
		if (isPrime(a))
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}

bool isPrime(const uint& a) {
	if (a == 1)
		return false;

	uint b = static_cast<uint> (sqrt(a));
	for (uint i = 2; i < b + 1; i++)
		if (a % i == 0)
			return false;

	return true;
}
