#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int sum = 0;
	for (int i = 0; i < s.size(); i++)
		sum += (s[i] - '0');
	if (sum % 3)
		cout << -1 << endl;
	else {
		sort(s.begin(), s.end(), greater<char>());
		if (s[s.size() - 1] != '0') {
			cout << -1 << endl;
			return 0;
		}

		for (int i = 0; i < s.size(); i++)
			cout << s[i];
		cout << endl;
	}

	return 0;
}