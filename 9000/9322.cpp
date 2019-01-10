#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 1005

int n;
string arr[MAX_N];
string arr2[MAX_N];
map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		m.clear();

		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for (int i = 0; i < n; ++i) {
			string str;
			cin >> str;
			m[str] = i;
		}
		for (int i = 0; i < n; ++i)
			cin >> arr2[i];
		
		for (int i = 0; i < n; ++i)
			cout << arr2[m[arr[i]]] << ' ';
		cout << endl;
	}
	
	return 0;
}