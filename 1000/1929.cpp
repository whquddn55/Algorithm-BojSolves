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

#define MAX_N 1000001

int n, m;
bool isnPrime[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	isnPrime[0] = isnPrime[1] = true;
	for (int i = 2; i <= 1000; i++)
		if (!isnPrime[i])
			for (int j = i * 2; j < MAX_N; j += i)
				isnPrime[j] = true;

	cin >> n >> m;
	for (int i = n; i <= m; i++)
		if (!isnPrime[i])
			cout << i << endl;
	
	return 0;
}