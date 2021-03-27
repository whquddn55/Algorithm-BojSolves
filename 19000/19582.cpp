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

#define MAX_N 100005

int n;
pii arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];


	ll sum = 0;
	int maxValue = 0;
	bool used = false;
	string result = "Kkeo-eok";

	for (int i = 0; i < n; ++i) {
		if (arr[i].first < sum) {
			if (used) {
				result = "Zzz";
				break;
			}

			used = true;
			if (maxValue > arr[i].second) {
				sum -= maxValue;
				if (arr[i].first < sum) {
					sum += maxValue;
					sum -= arr[i].second;
				}
			}
			else
				sum -= arr[i].second;
		}
		else {
			maxValue = max(maxValue, arr[i].second);
		}
		sum += arr[i].second;
	}

	cout << result << endl;

	return 0;
}