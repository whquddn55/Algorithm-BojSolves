#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 101
#define MAX_T 30001

int n, t;
int arr[MAX_N];
bool dp[MAX_N][MAX_T];
pii prv[MAX_N][MAX_T];
vector<bool> pm;
int cnt = 0;

int print(int idx1) {
	if (idx1 == pm.size() - 1) {
		cout << idx1 + 1 - cnt << endl;
		return pm.size() - 1;
	}
	if (pm[idx1] == 1) {
		int t = idx1;
		while (idx1 < pm.size() && pm[idx1] == 1) {
			cout << idx1 + 1 - cnt << endl;
			cnt++;
			idx1++;
		}
		return idx1;
	}
	if (pm[idx1 + 1] == 1) {
		int next = print(idx1 + 1);
		cout << idx1 + 1 - (cnt - (next - idx1 - 1)) << endl;
		cnt++;
		if (next != idx1 + 1)
			print(next);
	}
	else {
		cout << idx1 + 1 - cnt << endl;
		cnt++;
		print(idx1 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0][arr[0] + 15000] = true;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < MAX_T; ++j) {
			if (j < arr[i]) {
				dp[i][j] = dp[i - 1][j + arr[i]];
				prv[i][j] = { j + arr[i], 0 };
			}
			if (j >= MAX_T - arr[i]) {
				dp[i][j] = dp[i - 1][j - arr[i]];
				prv[i][j] = { j - arr[i], 1 };
			}
			else {
				dp[i][j] = dp[i - 1][j - arr[i]] || dp[i - 1][j + arr[i]];
				if (dp[i - 1][j - arr[i]])
					prv[i][j] = { j - arr[i], 1 };
				else
					prv[i][j] = { j + arr[i], 0 };
			}
		}

	bool c = prv[n - 1][t + 15000].second;
	int here = prv[n - 1][t + 15000].first;
	int idx = n - 2;
	stack<bool> st;
	while (idx != -1) {
		st.emplace(c);
		c = prv[idx][here].second;
		here = prv[idx][here].first;
		idx--;
	}
	while (!st.empty()) {
		pm.push_back(st.top());
		st.pop();
	}
	/*for (auto e : pm)
		cout << e << endl;*/
	
	print(0);

	return 0;
}