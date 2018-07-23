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

#define MAX_N 1000

int n;
int arr[MAX_N][MAX_N];
int degree[MAX_N];

void dfs(int here) {
	for (int i = 0; i < n; i++)
		if (arr[here][i]) {
			arr[here][i]--;
			arr[i][here]--;
			dfs(i);
		}
	cout << here + 1 << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			degree[i] += arr[i][j];
		}
	for (int i = 0; i < n; i++)
		if (degree[i] % 2) {
			cout << -1 << endl;
			return 0;
		}

	dfs(0);
	
	return 0;
}
