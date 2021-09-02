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

#ifndef DEBUG
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 500005
#define MOD 1000003

int n;
vector<int> arr;
vector<pii> br;

int ans = INT_MIN;
void pick(int here) {
	if (here == arr.size() - 1) {
		int sum = arr[0];
		int idx = 0;
		for (int i = 2; i < arr.size(); i += 2) {
			char op = arr[i - 1];
			int value;
			if (idx != br.size() && br[idx].first == i) {
				switch(arr[i + 1]) {
					case '+': {
						value = arr[i] + arr[i + 2];
						break;
					}
					case '-': {
						value = arr[i] - arr[i + 2];
						break;
					}
					case '*': {
						value = arr[i] * arr[i + 2];
						break;
					}
				}
				
				++idx;
				i += 2;
			} else {
				value = arr[i];
			}
			switch(op) {
				case '+': {
					sum += value;
					break;
				}
				case '-': {
					sum -= value;
					break;
				}
				case '*': {
					sum *= value;
					break;
				}
			} 
		}
		ans = max(ans, sum);
		return;
	}
	pick(here + 2);

	br.emplace_back(here, here + 2);
	if (here + 4 >= arr.size())
		pick(here + 2);
	else
		pick(here + 4);
	br.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	while(n--) {
		char c;
		cin >> c;
		if (isdigit(c))
			c -= '0';
		arr.push_back(c);
	}

	pick(0);
	cout << ans << endl;
	
	return 0;
}
