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

#define MAX_N 10001

int n;
vector<int> arr;

int dp[1000001];
int prv[1000001];

void getNum(string s) {
	if (s.size() >= 7)
		return;

	s.push_back('4');
	arr.emplace_back(atoi(s.c_str()));
	getNum(s);
	s.pop_back();
	s.push_back('7');
	arr.emplace_back(atoi(s.c_str()));
	getNum(s);
}

int getDp(int idx1) {
	if (idx1 < 0)
		return INF;
	if (idx1 == 0)
		return 0;

	int& ret = dp[idx1];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int e : arr) {
		if (idx1 < e)
			break;
		int value = getDp(idx1 - e) + 1;
		if (ret > value) {
			ret = value;
			prv[idx1] = e;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	getNum("");
	sort(arr.begin(), arr.end());

	cin >> n;
	
	memset(dp, -1, sizeof(dp));
	memset(prv, -1, sizeof(prv));
	getDp(n);
	if (dp[n] == INF)
		cout << -1 << endl;
	else {
		vector<int> ans;
		int here = prv[n];
		int phere = n;
		while (here != -1) {
			ans.push_back(here);
			phere = phere - here;
			here = prv[phere];
		}
		sort(ans.begin(), ans.end());
		for (auto e : ans)
			cout << e << ' ';
		cout << endl;
	}
	
	return 0;
}