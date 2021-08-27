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
#define MAX_N 5000005
#define MOD 1000003

int n;
bool isPrime[MAX_N];
int minValue[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	fill(isPrime, isPrime + MAX_N, true);
	for (int i = 2; i < MAX_N; ++i)
		minValue[i] = i;
	for (int i = 2; i <= sqrt(MAX_N); ++i) {
		if (isPrime[i]) {
			for (int j = i * 2; j < MAX_N; j += i) {
				isPrime[j] = false;
				minValue[j] = min(minValue[j], i);
			}
		}
	}
	

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int value;
		cin >> value;
		while(value != 1) {
			cout << minValue[value] << ' ';
			value /= minValue[value];
		}
		cout << endl;
	}

	return 0;
}
