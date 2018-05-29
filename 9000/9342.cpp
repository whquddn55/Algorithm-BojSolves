#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 2000002

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;

		bool ret1 = true;
		if (s[0] != 'A' && s[0] != 'B' && s[0] != 'C' && s[0] != 'D' && s[0] != 'E' && s[0] != 'F')
			ret1 = false;
		int idx = 1;
		if (s[idx] != 'A')
			ret1 = false;
		while (s[++idx] == 'A');
		if (s[idx] != 'F')
			ret1 = false;
		while (s[++idx] == 'F');
		if (s[idx] != 'C')
			ret1 = false;
		while (s[++idx] == 'C');
		if (idx < s.size() - 1 || (idx == s.size() - 1 && (s[idx] != 'A' && s[idx] != 'B' && s[idx] != 'C' && s[idx] != 'D' && s[idx] != 'E' && s[idx] != 'F')))
			ret1 = false;


		bool ret2 = true;
		idx = 0;
		if (s[idx] != 'A')
			ret2 = false;
		while (s[++idx] == 'A');
		if (s[idx] != 'F')
			ret2 = false;
		while (s[++idx] == 'F');
		if (s[idx] != 'C')
			ret2 = false;
		while (s[++idx] == 'C');
		if (idx < s.size() - 1 || (idx == s.size() - 1 && (s[idx] != 'A' && s[idx] != 'B' && s[idx] != 'C' && s[idx] != 'D' && s[idx] != 'E' && s[idx] != 'F')))
			ret2 = false;

		if (ret1 || ret2)
			cout << "Infected!" << endl;
		else
			cout << "Good" << endl;
	}
	

	return 0;
}
