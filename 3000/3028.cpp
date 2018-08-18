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

int pos = 1;
string str;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> str;
	for (auto e : str) {
		if (e == 'A') {
			if (pos == 1)
				pos = 2;
			else if (pos == 2)
				pos = 1;
		}
		else if (e == 'B') {
			if (pos == 2)
				pos = 3;
			else if (pos == 3)
				pos = 2;
		}
		else {
			if (pos == 1)
				pos = 3;
			else if (pos == 3)
				pos = 1;
		}
	}

	cout << pos << endl;
	
	return 0;
}