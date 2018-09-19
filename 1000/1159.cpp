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

#define MAX_N 150

int n;
char arr[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		++arr[str[0] - 'a'];
	}

	bool printed = false;
	for (int i = 0; i < 26; i++)
		if (arr[i] >= 5) {
			cout << (char)('a' + i);
			printed = true;
		}
	if (!printed)
		cout << "PREDAJA" << endl;
	
	return 0;
}