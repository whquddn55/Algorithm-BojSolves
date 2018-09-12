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

#define MAX_N 10000000

int k;
bool isnPrime[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> k;
	for (ll i = 2; i * i < MAX_N; i++)
		if (isnPrime[i] == false)
			for (int j = i * 2; j < MAX_N; j += i)
				isnPrime[j] = true;

	int cnt = 0;
	for (ll i = 2; i < MAX_N; i++)
		if (!isnPrime[i]) {
			cnt++;
			if (cnt == k)
				cout << i << endl;
		}

	return 0;
}