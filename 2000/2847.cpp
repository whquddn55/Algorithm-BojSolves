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

#define MAX_N 100

int n;
int arr[MAX_N];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = n - 2; i >= 0; --i) {
		if (arr[i] >= arr[i + 1]) {
			ans += arr[i] - (arr[i + 1] - 1);
			arr[i] = arr[i + 1] - 1;
		}
	}
	cout << ans << endl;

	return 0;
}
