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

#define MAX_N 100005
#define MOD 1000000007

int n, m;
string arr[MAX_N];
map<string, int> cnt;

bool comparer(string& a, string& b) {
	if (cnt[a] != cnt[b])
		return cnt[a] > cnt[b];
	if (a.length() != b.length())
		return a.length() > b.length();
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tmp;
	cin >> tmp >> m;
	for (int i = 0; i < tmp; ++i) {
		string strTmp;
		cin >> strTmp;
		if (strTmp.length() >= m)
			arr[n++] = strTmp;
	}

	for (int i = 0; i < n; ++i)
		++cnt[arr[i]];
	sort(arr, arr + n);
	n = unique(arr, arr + n) - arr;
	

	sort(arr, arr + n, comparer);
	for (int i = 0; i < n; ++i)
		cout << arr[i] << endl;
	
	return 0;
}