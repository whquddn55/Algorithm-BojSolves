#include <iostream>
using namespace std;

typedef unsigned int uint;

uint LCM(const uint a, const uint b);
uint GCM(const uint a, const uint b);

int main() {
	uint n;
	cin >> n;

	uint a, b;
	for (uint i = 0; i < n; i++) {
		cin >> a >> b;
		cout << LCM(a, b) << endl;
	}



	return 0;
}

uint LCM(const uint a, const uint b) {
	uint gcm = GCM(a, b);

	return a*b / gcm;
}

uint GCM(const uint a, const uint b) {
	uint p = a, q = b;
	while (true) { // p = t*q + r
		uint r = p % q;
		if (r == 0)
			break;
		p = q;
		q = r;
	}

	return q;
}