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
#define MAX_N 1000005
#define MOD 1000000007

int n;
int arr[MAX_N];
bool isIn[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
	cin >> n;
	int maxValue = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		isIn[arr[i]] = true;
		maxValue = max(maxValue, arr[i]);
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int b = 2;
		int c = 1;
		int value = arr[i] * b + c * c;
		while (value <= maxValue) {
			if (isIn[value])
				++ans;
			b += 2;
			c += 1;
			value = arr[i] * b + c * c;
		} 
	}
	cout << ans << endl;



	return 0;
}
