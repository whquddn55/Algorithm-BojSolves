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

#define MAX_N 31
#define MOD 1000000007

int n;
int arr[MAX_N];
int k;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		k = 0;

		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> arr[i];


		vector<int> result;
		for (int i = n; i > 0; --i) {
			if (arr[i] == i)
				continue;

			int index = 1;
			for (; index < i; ++index) 
				if (arr[index] == i)
					break;
			
			if (index != 1) {
				reverse(arr + 1, arr + 1 + index);
				k++;
				result.emplace_back(index);
			}
			reverse(arr + 1, arr + 1 + i);
			k++;
			result.emplace_back(i);
		}

		cout << k << ' ';
		for (auto r : result)
			cout << r << ' ';

		cout << endl;
	}
	

	return 0;
}