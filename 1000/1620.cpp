#include <bits/stdc++.h>
#include <unordered_map>
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

#define MAX_N 100001

int n, m;
string arr[MAX_N];
map<string, int> um;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		um[str] = (i + 1);
		arr[i + 1] = str;
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (um[str])
			cout << um[str] << endl;
		else
			cout << arr[stoi(str)] << endl;
	}

	return 0;
}
