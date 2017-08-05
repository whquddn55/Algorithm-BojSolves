#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	char str[100];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		sum += str[i] - '0';
	}

	cout << sum << endl;

	return 0;
}