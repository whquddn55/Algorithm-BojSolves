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
#define MAX_N 1005
#define MOD 31991
#define MOD2 1000000009

struct Matrix {
	vector<vector<int>> arr;

	Matrix(int n) 
		: arr(n, vector<int>(n, 0)) { }

	Matrix operator*(const Matrix& other) const {
		Matrix res(arr.size());
		for (int i = 0; i < arr.size(); ++i)
			for (int j = 0; j < arr.size(); ++j) {
				for (int k = 0; k < arr.size(); ++k) {
					res.arr[i][j] += (arr[i][k] * other.arr[k][j]) % MOD;
					res.arr[i][j] %= MOD;
				}
			}
		return res;
	}

	void print() {
		for (int i = 0; i < arr.size(); ++i,cout<<endl)
			for (int j = 0; j < arr.size(); ++j)
				cout << arr[i][j] << ' ';
	}
};

int d, t;

Matrix power(Matrix m, int times) {
	Matrix res(m.arr.size());
	for (int i = 0; i < res.arr.size(); ++i)
		res.arr[i][i] = 1;
	while(times) {
		if (times % 2) 
			res = res * m;
		m = m * m;
		times /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> d >> t;

	Matrix res(d);
	for (int i = 0; i < d; ++i)
		res.arr[0][i] = 1;
	for (int i = 1; i < d; ++i)
		res.arr[i][i - 1] = 1;
	
	res = power(res, t);
	
	int ans = res.arr[d - 1][d - 1];
	int coValue = 1;
	for (int i = d - 2; i >= 0; --i) {
		ans = (ans + res.arr[d - 1][i] * coValue) % MOD;
		coValue = (coValue * 2) % MOD;
	}
	cout << ans << endl;

	return 0;
}