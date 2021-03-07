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

#define MAX_N 530000
#define MOD 1000000007

int n;
int get(int al, int ar, int bl, int br) {
	int amid = al - 1 + (ar - al + 1) / 2;
	int bmid = bl - 1 + (br - bl + 1) / 2;
	int amidValue;
	int bmidValue;
	cout << "? A " << amid << endl;
	cout << flush;
	cin >> amidValue;
	cout << "? B " << bmid << endl;
	cout << flush;
	cin >> bmidValue;

	if ((ar - al + 1) / 2 == 1) {
		int temp[4] = { amidValue, bmidValue, };
		cout << "? A " << amid + 1 << endl;
		cout << flush;
		cin >> temp[2];
		cout << "? B " << bmid + 1 << endl;
		cout << flush;
		cin >> temp[3];
		sort(temp, temp + 4);
		return temp[1];
	}

	if (amidValue < bmidValue)
		return get(amid + 1, ar, bl, bmid);
	else
		return get(al, amid, bmid + 1, br);
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n;
	if (n == 1) {
		int a, b;
		cout << "? A 1" << endl;
		cout << flush;
		cin >> a;
		cout << "? B 1" << endl;
		cout << flush;
		cin >> b;
		cout << "! " << min(a, b) << endl;
		cout << flush;
	}
	else {
		int result = get(1, n, 1, n);
		cout << "! " << result << endl;
		cout << flush;
	}

	return 0;
}