#include <iostream>
using namespace std;

int main() {
	int length;
	cin >> length;
	int n;
	cin >> n;

	int* const arr = new int[length];

	for (int i = 0; i < length; i++)
		cin >> arr[i];

	for (int i = 0; i < length; i++)
		if (arr[i] < n)
			cout << arr[i] << ' ';
	cout << endl;
	

	return 0;
}