#include <iostream>
using namespace std;

int main() {
	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int space = 0; space < i; space++)
			cout << ' ';
		for (int star = 0; star < (size - i) * 2 - 1; star++)
			cout << '*';
		cout << endl;
	}

	return 0;
}