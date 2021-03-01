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

#define MAX_N 15
#define MOD 1000000007

int n;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < 14; ++i)
		cin >> arr[i];

	int total = 0;
	int totalBudget = n;
	for (int i = 3; i < 14; ++i) {
		if (arr[i - 3] < arr[i - 2] && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
			totalBudget += arr[i] * total;
			total = 0;
		}
		if (arr[i - 3] > arr[i - 2] && arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i]) {
			total += totalBudget / arr[i];
			totalBudget -= arr[i] * (totalBudget / arr[i]);
		}
	}
	int result1 = totalBudget + total * arr[13];

	totalBudget = n;
	total = 0;
	for (int i = 0; i < 14; ++i) {
		if (arr[i] <= totalBudget) {
			total += totalBudget / arr[i];
			totalBudget -= arr[i] * (totalBudget / arr[i]);
		}
	}
	int result2 = totalBudget + total * arr[13];
	
	cout << (result1 > result2 ? "TIMING" : (result1 < result2 ? "BNP" : "SAMESAME")) << endl;

	return 0;
}