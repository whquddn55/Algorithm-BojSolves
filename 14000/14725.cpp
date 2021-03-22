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
#define MOD 1000000007

#define MAX_N 15005

int n;
vector<int> adj[MAX_N];
string arr[MAX_N];
map<string, int> strIndex;

void dfs(int here, int depth) {
	for (int i = 0; i < depth; ++i)
		cout << "--";
	cout << arr[here] << endl;


	for (int i = 0; i < adj[here].size(); ++i) {
		dfs(adj[here][i], depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	strIndex["root"] = 1;
	arr[1] = "root";
	cin >> n;
	while (n--) {
		int len;
		cin >> len;
		string parent = "root";
		while (len--) {
			string origin;
			cin >> origin;
			string child = origin + parent;


			if (strIndex.find(child) == strIndex.end()) {
				arr[strIndex.size() + 1] = origin;
				strIndex.emplace(child, strIndex.size() + 1);
				adj[strIndex[parent]].emplace_back(strIndex[child]);
			}

			parent = child;
		}
	}

	for (int i = 1; i < strIndex.size() + 1; ++i)
		sort(adj[i].begin(), adj[i].end(), [](int a, int b) -> bool {
			return arr[a] < arr[b];
		});

	for (int i = 0; i < adj[1].size(); ++i) 
		dfs(adj[1][i], 0);
	
	
	return 0;
}