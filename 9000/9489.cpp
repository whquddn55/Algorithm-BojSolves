#include <bits/stdc++.h>
#include <unordered_set>
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

#define MAX_N 1000
#define MAX_K 1000000

int n, k;
int arr[MAX_N];
int depth[MAX_K];
int parent[MAX_K];

int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while (cin >> n >> k) {
		if (n == 0)
			break;
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i]--;
		}
		k--;

		depth[arr[0]] = 0;
		int last = -1;
		for (int i = 1; i < n; i++) {
			if (arr[i - 1] + 1 < arr[i])
				last++;
			parent[arr[i]] = arr[last];
			depth[arr[i]] = depth[arr[last]] + 1;
		}
		
		for (int i = 0; i < n; i++)
			if (depth[arr[i]] == depth[k] && parent[arr[i]] != parent[k] && parent[parent[arr[i]]] == parent[parent[k]])
				ans++;
		cout << ans << endl;
	}

	return 0;
}