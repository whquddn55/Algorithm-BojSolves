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

#define MAX_N 100000

int n, s;
int arr[MAX_N];

int sum = 0;
int len = 0;

int minLen = INF;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		len++;

		while (sum - arr[i - len + 1] >= s) {
			sum -= arr[i - len + 1];
			len--;
		}
		if (sum >= s)
			minLen = min(minLen, len);
	}
	cout << (minLen == INF ? 0 : minLen) << endl;

	return 0;
}