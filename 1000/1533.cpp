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
#define MAX_N 10
#define MOD 1000003

typedef vector<vector<int>> Matrix;

int n, s, e, t;
char arr[10][10];
Matrix m;

Matrix mul(const Matrix& a, const Matrix& b) {
	int sz = a.size();
	Matrix result(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			for (int k = 0; k < sz; ++k)
				result[i][j] = (result[i][j] + (ll)a[i][k] * b[k][j]) % MOD;
	return result;
}

Matrix power(Matrix a, int b) {
	int sz = a.size();
	Matrix result(sz, vector<int>(sz, 0));
	for (int i = 0; i < sz; ++i)
		result[i][i] = 1;
	while(b) {
		if (b % 2) 
			result = mul(result, a);
		b >>= 1;
		a = mul(a, a);
	}
	return result;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> n >> s >> e >> t;
	m.resize(n * 5, vector<int>(n * 5, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			arr[i][j] -= '0';
		}
		
	for (int i = 0; i < n; ++i) {
		m[i][n + i * 4] = 1;
		m[n + i * 4][n + i * 4 + 1] = 1;
		m[n + i * 4 + 1][n + i * 4 + 2] = 1;
		m[n + i * 4 + 2][n + i * 4 + 3] = 1;
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] - 2 >= 0) {
				m[n + i * 4 + (arr[i][j] - 2)][j] = 1;
			}
			else {
				m[i][j] = arr[i][j];
			}
		}
	}

	cout << (int)power(m, t)[s - 1][e - 1] << endl;
	
	return 0;
}
