#include <bits/stdc++.h>
#include <cassert>
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

#define MAX_N 101

class Bignum {
private:
	vector<long long> num;
	void reArrange() {
		int t = num.size();
		for (int i = 0; i < t; i++) {
			if (num[i] >= 1000000000) {
				if (i + 1 == t)
					num.push_back(0);
				num[i + 1]++;
				num[i] -= 1000000000;
			}
		}
	}
public:
	Bignum() {

	}
	Bignum(int init) {
		num.push_back(init);
	}

	Bignum(const Bignum & init) {
		num = init.num;
	}
	Bignum operator+(const Bignum& other) {
		if (num.size() >= other.num.size()) {
			for (int i = 0; i < other.num.size(); i++)
				num[i] += other.num[i];
			reArrange();
		}
		else {
			for (int i = 0; i < num.size(); i++)
				num[i] += other.num[i];
			for (int i = num.size(); i < other.num.size(); i++)
				num.push_back(other.num[i]);
			reArrange();
		}
		return *this;
	}

	Bignum operator*(const Bignum& other) {
		if (num.size() >= other.num.size()) {
			for (int i = 0; i < other.num.size(); i++)
				num[i] *= other.num[i];
			reArrange();
		}
		else {
			for (int i = 0; i < num.size(); i++)
				num[i] *= other.num[i];
			for (int i = num.size(); i < other.num.size(); i++)
				num.push_back(other.num[i]);
			reArrange();
		}

		return *this;
	}

	void operator*=(const Bignum& other) {

	}

	friend ostream& operator<<(ostream&, const Bignum&);
};

ostream& operator<<(ostream& os, const Bignum& bignum) {
	for (int i = bignum.num.size() - 1; i >= 0; i--)
		os << bignum.num[i];
	return os;
}


int n, m;
Bignum dp[MAX_N][MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	cout << dp[n][m] << endl;

	return 0;
}