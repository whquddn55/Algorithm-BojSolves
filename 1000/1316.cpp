#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int result = 0;
	while (n--) {
		string s;
		cin >> s;

		vector<bool> v(26);
		fill(v.begin(), v.end(), false);
		v[s[0] - 'A'] = true;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1])
				continue;

			if (v[s[i] - 'A']) {
				result--;
				break;
			}
			v[s[i] - 'A'] = true;
		}
		result++;
	}

	cout << result << endl;

	return 0;
}