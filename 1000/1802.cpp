#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 10000
#define MAX_K 21

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		str.clear();
		str.push_back(' ');
		string temp;
		cin >> temp;
		str.append(temp);

		int n = str.size();
		int t = 1;
		while (t < n)
			t *= 2;

		bool ans = true;
		while (t > 1) {
			for (int i = t / 2 + t; i < n && ans; i += t) {
				if (str[i] == str[i - t]) {
					/*cout << pii(t, i) << endl;
					cout << str[t / 2] << ", " << str[i] << endl;*/
					ans = false;
				}
			}
			if (!ans) {
				break;
				
			}
			t /= 2;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}

	return 0;
}
