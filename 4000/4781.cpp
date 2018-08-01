#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

#define MAX_N 5000

int n, m;
pii arr[MAX_N];
int dp[10001];

int getDp(int idx1) {
	int& ret = dp[idx1];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i < n; i++)
		if (idx1 - arr[i].second >= 0)
			ret = max(ret, getDp(idx1 - arr[i].second) + arr[i].first);
		else
			break;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while (true) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if (n == 0)
			break;
		string temp;
		cin >> temp;
		m = stoi(temp.substr(0, temp.size() - 3)) * 100 + stoi(temp.substr(temp.size() - 2));

		for (int i = 0; i < n; i++) {
			cin >> arr[i].first;
			cin >> temp;
			arr[i].second = stoi(temp.substr(0, temp.size() - 3)) * 100 + stoi(temp.substr(temp.size() - 2));
		}
		sort(arr, arr + n, [](const pii& a, const pii& b)->bool {
			return a.second < b.second;
		});
		cout << getDp(m) << endl;
	}

	return 0;
}