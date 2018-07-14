#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

#define MAX_N 100000001

int a, b;
vector<int> pelinPrime;

bool isPrime(int num) {
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;
	return true;
}

int makePelindrom(int num) {
	if (num < 10)
		return num * 10 + num;
	string s = to_string(num / 10);
	reverse(s.begin(), s.end());
	int l = 10;
	int t = s.size();
	while (t--)
		l *= 10;

	int v = atoi(s.c_str());
	return (num / 10) * l + (num % 10) * (l / 10) + v;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	
	cin >> a >> b;

	pelinPrime.push_back(2);
	pelinPrime.push_back(3);
	pelinPrime.push_back(5);
	pelinPrime.push_back(7);
	
	for (int i = 1; i <= 10000; i++) {
		int value = makePelindrom(i);
		if (isPrime(value))
			pelinPrime.push_back(value);
	}
	
	int l = lower_bound(pelinPrime.begin(), pelinPrime.end(), a) - pelinPrime.begin();
	int r = upper_bound(pelinPrime.begin(), pelinPrime.end(), b) - pelinPrime.begin();

	for (int i = l; i < r; i++)
		cout << pelinPrime[i] << endl;

	cout << -1 << endl;
	
	return 0;
}