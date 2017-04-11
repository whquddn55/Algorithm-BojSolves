#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned int uint;


int main() {
	uint n;
	cin >> n;

	for (uint i = 0; i < n; i++) {
		for (uint j = n - 1; j > i ; j--) 
			cout << ' ';
		for (uint j = 0; j < i * 2 + 1; j++) 
			cout << '*';
		cout << endl;
	}

	return 0;
}