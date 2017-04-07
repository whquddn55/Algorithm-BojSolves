#include <iostream>
#include <string>
using namespace std;
typedef unsigned int uint;

void back(uint* student, uint s, uint e);

int main() {
	uint n;
	uint arr[100];
	uint student[100];

	cin >> n;
	for (uint i = 0; i < n; i++)
		student[i] = i;

	for (uint i = 0; i < n; i++)
		cin >> arr[i];

	uint temp;
	for (uint i = 0; i < n; i++) {
		temp = student[i];
		if (arr[i] != 0)
			back(student, i - arr[i] , i);
		student[i - arr[i]] = temp;
	}

	for (uint i = 0; i < n; i++)
		cout << student[i] + 1 << ' ';
	cout << endl;

	return 0;
}

void back(uint* student, uint s, uint e) {
	for (uint i = e; i > s; i--) {
		student[i] = student[i - 1];
	}
}
