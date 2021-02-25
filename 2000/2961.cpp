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

#define MAX_N 10
#define MOD 1000000007

int n;
pii arr[MAX_N];
int result = INF;

void pick(int index, int s, int b) {
	if (index == n) {
		if (s == 1 && b == 0)
			return;
		result = min(result, abs(s - b));
		return;
	}
	pick(index + 1, s * arr[index].first, b + arr[index].second);
	pick(index + 1, s, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	pick(0, 1, 0);
	cout << result << endl;

	return 0;
}