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

#define MAX_N 105
#define MOD 1000000007

int n;
vector<int> prv;
vector<int> result;

void dfs(int here) {
	prv.push_back(here);
	if (result.size() && (prv.size() > result.size())) {
		prv.pop_back();
		return;
	}
	if (here == n) {
		if (result.empty() || prv.size() < result.size())
			result = prv;

		prv.pop_back();
		return;
	}
	if (prv.size() > 10) {
		prv.pop_back();
		return;
	}

	for (int i = prv.size() - 1; i >= 0; --i) {
		int value = prv[i];
		if (value + here > n)
			continue;
		dfs(value + here);
	}

	prv.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while (true) {
		result.clear();
		cin >> n;
		if (!n)
			break;

		dfs(1);

		for (auto value : result)
			cout << value << ' ';
		cout << endl;
	}

	return 0;
}