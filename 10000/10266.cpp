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
#define MAX_N 200005
#define MOD 1000000007

int n;
int arr[MAX_N], brr[MAX_N];
int adiff[MAX_N * 2], bdiff[MAX_N];
int pi[MAX_N];
vector<int> matches;

void getPi() {
	pi[0] = 0;
	int from = 1, matched = 0;
	while(from + matched < n) {
		if (bdiff[from + matched] == bdiff[matched]) {
			++matched;
			pi[from + matched - 1] = matched;
		}
		else if (matched == 0) {
			++from;
		}
		else {
			from += matched;
			from -= pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
}

void kmp() {
	int from = 0, matched = 0;
	while(from + matched < n * 2) {
		if (matched != n && adiff[from + matched] == bdiff[matched]) {
			++matched;

			if (matched == n)
				matches.push_back(from);
		}
		else if (matched == 0)
			++from;
		else {
			from += matched;
			from -= pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)	
		cin >> brr[i];

	sort(arr, arr + n);
	sort(brr, brr + n);

	for (int i = 0; i < n - 1; ++i)
		adiff[i] = arr[i + 1] - arr[i];
	adiff[n - 1] = 360000 - arr[n - 1] + arr[0];

	for (int i = n; i < n * 2; ++i)
		adiff[i] = adiff[i - n];

	for (int i = 0; i < n - 1; ++i)
		bdiff[i] = brr[i + 1] - brr[i];
	bdiff[n - 1] = 360000 - brr[n - 1] + brr[0];

	getPi();
	kmp();

	cout << (matches.size() ? "possible" : "impossible") << endl;
	
	
	return 0;
}
