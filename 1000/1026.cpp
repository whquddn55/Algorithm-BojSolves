#include <iostream>
#include <algorithm>
using namespace std;

int data1[50];
int data2[50];
int arr[50];


int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> data1[i];
	for (int i = 0; i < n; i++)
		cin >> data2[i];

	sort(data1, data1 + n);
	sort(data2, data2 + n);

	int result = 0;
	for (int i = 0; i < n; i++)
		result += data1[i] * data2[n - i - 1];

	cout << result << endl;

	return 0;
}