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

#define INF (LLONG_MAX / 2)

#define MAX_N 100

bool check[30];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	for (int i = 0; i < 28; i++) {
		int t;
		cin >> t;
		check[t - 1] = true;
	}
	for (int i = 0; i < 30; i++)
		if (!check[i])
			cout << i + 1 << endl;
	
	return 0;
}