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
#define MAX_N 2005
#define MOD 1000000007

typedef vector<vector<int>> Matrix;

int t, n ,d;
Matrix arr[101];

Matrix multiply(Matrix a, Matrix b) {
	Matrix result(20, vector<int>(20, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			for (int k = 0; k < n; ++k)
				result[i][j] = (result[i][j] + (ll)a[i][k] * b[k][j]) % MOD;
	return result;
}

Matrix power(Matrix a, int b) {
	Matrix result(20, vector<int>(20, 0));
	for (int i = 0; i < n; ++i)
		result[i][i] = 1;
	while(b) {
		if (b % 2) {
			result = multiply(a, result);
		} 
		b >>= 1;
		a = multiply(a, a);
	}
	return result;
}
 
int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL);

	cin >> t >> n >> d;
	for (int i = 0; i <= t; ++i)
		arr[i].resize(n, vector<int>(20));
	for (int i = 0; i < n; ++i)
		arr[0][i][i] = 1;
	for (int i = 1; i <= t; ++i) {
		int m;
		cin >> m;
		while(m--) {
			int a, b, c;
			cin >> a >> b >> c;
			arr[i][a - 1][b - 1] = c;
		}
		arr[i] = multiply(arr[i - 1], arr[i]);
	}

	Matrix result = power(arr[t], d / t);
	result = multiply(result, arr[d % t]);
	for (int i = 0; i < n; ++i,cout<<endl)
		for (int j = 0; j < n; ++j)
			cout << result[i][j] << ' ';
	
	return 0;
}
