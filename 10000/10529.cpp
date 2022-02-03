#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 13
#define MOD 1'000'000'007

int n;
string arr[MAX_N];
int value[300];
vector<int> brr;
bool canZero[300];
bool used[10];

int ans = 0;
void pick(int index) {
	if (index == brr.size()) {
		int sum = 0;
		for (int i = 0; i < n - 1; ++i) {
			int v = 0;
			for (auto c : arr[i])
				v = v * 10 + value[c];
			sum += v;
		}
		int v = 0;
		for (auto c : arr[n - 1])
			v = v * 10 + value[c];
		ans += (sum == v);
		return;
	}

	for (int i = !canZero[brr[index]]; i <= 9; ++i) {
		if (used[i]) {
			continue;
		}
		value[brr[index]] = i;
		used[i] = true;
		pick(index + 1);
		used[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	memset(value, -1, sizeof(value));
	fill_n(canZero, sizeof(canZero), true);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < arr[i].size(); ++j) {
			char c = arr[i][j];
			if (value[c] == 0) {
				continue;
			}
			value[c] = 0;
			brr.emplace_back(c);
			if (j == 0) {
				canZero[c] = false;
			}
		}
	}

	pick(0);
	cout << ans << endl;

	return 0;
}