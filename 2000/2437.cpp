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

#define MAX_N 1000

int n;
int arr[MAX_N];
int sum = 0;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	
	bool printed = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] > sum + 1) {
			cout << sum + 1 << endl;
			printed = true;
			break;
		}
		sum += arr[i];
	}

	if (!printed)
		cout << sum + 1 << endl;

	return 0;
}