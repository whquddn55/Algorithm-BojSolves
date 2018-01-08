#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> ropes(n);
	for (int i = 0; i < n; i++)
		cin >> ropes[i];

	sort(ropes.begin(), ropes.end());

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, ropes[i] * (n - i));

	cout << result << endl;

	return 0;
}