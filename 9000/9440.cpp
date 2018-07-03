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

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 14

int n;
int num1, num2;
int arr[MAX_N];
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	while (true) {
		s.clear();
		num1 = num2 = 0;

		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			s.insert(arr[i]);
		}
		sort(arr, arr + n);
		
		if (n % 2) {
			auto it = s.upper_bound(0);
			num1 += *it;
			s.erase(it);
			it = s.begin();
			num1 *= 10;
			num1 += *it;
			s.erase(it);
		}
		else {
			auto it = s.upper_bound(0);
			num1 += *it;
			s.erase(it);
		}
		auto it = s.upper_bound(0);
		num2 += *it;
		s.erase(it);

		int remain = n / 2 - 1;
		while (remain--) {
			it = s.begin();
			num1 *= 10;
			num1 += *it;
			s.erase(it);
			it = s.begin();
			num2 *= 10;
			num2 += *it;
			s.erase(it);
		}
		cout << num1 + num2 << endl;
	}
	
	return 0;
}
