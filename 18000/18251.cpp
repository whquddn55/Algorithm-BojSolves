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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 262150
#define MOD 1000000007

int n;
int arr[MAX_N];
int nodeNum[MAX_N];
vector<int> heightNodes[(int)ceil(log2(MAX_N)) + 20];
int dfsn;
void dfs(int here, int height) {
	if (here > n)
		return;
	
	heightNodes[height].emplace_back(here);
	dfs(here * 2, height + 1);
	nodeNum[here] = dfsn++;
	dfs(here * 2 + 1, height + 1);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;

	int maxValue = -INF;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		maxValue = max(maxValue, arr[i]);
	}

	dfs(1, 0);
	
	int maxHeight = (int)floor(log2(n));
	ll ans = maxValue;
	for (int i = 0; i <= maxHeight; ++i) {
		for (int j = 0; j <= maxHeight; ++j) {
			vector<int> temp;
			for (int k = i; k <= j; ++k) 
				temp.insert(temp.end(), heightNodes[k].begin(), heightNodes[k].end());
			sort(temp.begin(), temp.end(), [](int i, int j) -> bool {
				return nodeNum[i] < nodeNum[j];
			});

			ll sum = 0;
			for (int idx : temp) {
				sum += arr[idx];
				sum = max(sum, 0LL);
				ans = max(ans, sum);
			}
		}
	}

	if (maxValue < 0)
		cout << maxValue << endl;
	else
		cout << ans << endl;
	
	
	return 0;
}
