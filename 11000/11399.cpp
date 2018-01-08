#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int result = 0;
	for (int i = 0; i < n; i++)
		result += arr[i] * (n - i);

	cout << result << endl;

	return 0;
}