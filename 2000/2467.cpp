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

int n;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	int l = 0;
	int r = n - 1;

	int minValue = INF* 2;
	pii result;
	while (l < r) {
		int sum = arr[l] + arr[r];

		if (abs(sum) < minValue) {
			minValue = abs(sum);
			result = { arr[l], arr[r] };
		}

		if (sum < 0)
			l++;
		else if (sum > 0)
			r--;
		else
			break;
	}
	cout << result << endl;
	
	return 0;
}