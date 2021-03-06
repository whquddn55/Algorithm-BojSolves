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

#define MAX_N 4300
#define MOD 1000000007

int n, k;
int result[MAX_N];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		s.insert(i);

	int value = n;
	int index = 0;
	int t = k;
	while ((value != 1) && (t >= value - 1)) {
		result[index] = value;
		s.erase(value);
		index++;
		t -= (value - 1);
		value--;
	}
	result[n - t - 1] = value;
	s.erase(value);

	for (int i = 0; i < n; ++i) {
		if (result[i])
			cout << result[i] << ' ';
		else {
			cout << *s.begin() << ' ';
			s.erase(s.begin());
		}
	}
	
	return 0;
}