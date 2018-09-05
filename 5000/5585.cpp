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

#define MAX_N 100

int n;
int arr[] = { 500, 100, 50, 10, 5, 1 };
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	n = 1000 - n;
	for (int i = 0; i < 6; i++)
		if (n / arr[i]) {
			ans += n / arr[i];
			n %= arr[i];
		}
	cout << ans << endl;
	
	return 0;
}