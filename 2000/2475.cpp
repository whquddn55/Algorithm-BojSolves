#include <iostream>
using namespace std;

typedef unsigned int uint;

const uint MAX = 5;


int main() {
	uint number[MAX];

	uint checkNum = 0;
	for (uint i = 0; i < MAX; i++) {
		cin >> number[i];
		checkNum += number[i] * number[i];
	}

	cout << checkNum % 10 << endl;

	return 0;
}
