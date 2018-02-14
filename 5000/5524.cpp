#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << endl;
	}

	return 0;
}