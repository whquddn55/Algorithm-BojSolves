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

#define MAX_N 500000

int n, k;
int cntOfPrint;
list<int> arr;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> k;
	cntOfPrint = n - k;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		temp -= '0';
		arr.push_back(temp);
	}

	int idx = -1;
	auto it = arr.begin();
	for (; it != arr.end(); ++it) {
		auto t = it;
		t++;
		if (t == arr.end()) {
			it = arr.end();
			break;
		}
		if (*it < *t)
			break;
	}

	while (k && (it != arr.end())) {
		auto t = it;
		t++;
		if (t == arr.end())
			break;

		if (*it < *t) {
			it = arr.erase(it);
			if (it != arr.begin())
				it--;
			k--;
		}
		else
			it++;
	}
	for (auto it = arr.begin(); it != arr.end() && cntOfPrint--; it++) 
		cout << *it;
	cout << endl;

	return 0;
}