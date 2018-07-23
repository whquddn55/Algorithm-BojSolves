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

#define MAX_N 20000

int n;
pair<int, string> arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		arr[i] = { t.size(), t };
	}
	sort(arr, arr + n);
	n = unique(arr, arr + n) - arr;
	for (int i = 0; i < n; i++)
		cout << arr[i].second << endl;
	
	return 0;
}
