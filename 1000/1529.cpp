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

#define MAX_N 50

struct Matrix {
	ll arr[2][2];

	Matrix(ll a, ll b, ll c, ll d) {
		arr[0][0] = a;
		arr[0][1] = b;
		arr[1][0] = c;
		arr[1][1] = d;
	}

	void operator*=(const Matrix m) {
		ll temp[2][2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				temp[i][j] = arr[i][j];
		arr[0][0] = temp[0][0] * m.arr[0][0] + temp[0][1] * m.arr[1][0];
		arr[0][1] = temp[0][0] * m.arr[0][1] + temp[0][1] * m.arr[1][1];
		arr[1][0] = temp[1][0] * m.arr[0][0] + temp[1][1] * m.arr[1][0];
		arr[1][1] = temp[1][0] * m.arr[0][1] + temp[1][1] * m.arr[1][1];
	}

	void operator%=(const int t) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				arr[i][j] %= t;
	}
};

int n, l;
int arr[4];
set<int> s;
vector<int> kmmin;

void makeKmmin() {
	kmmin.push_back(4);
	kmmin.push_back(7);
	int cnt = 8;
	int prv = 0;
	while (cnt--) {
		int t = kmmin.size();
		for (int i = prv; i < t; i++) {
			kmmin.push_back(kmmin[i] * 10 + 4);
			kmmin.push_back(kmmin[i] * 10 + 7);
		}
		prv = t;
	}
}

Matrix fast(Matrix m, int a) {
	Matrix ret(1, 0, 0, 1);
	while (a) {
		if (a % 2)
			ret *= m;
		ret %= 1234567891;
		m *= m;
		m %= 1234567891;
		a /= 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	makeKmmin();
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (s.count(t))
			continue;
		s.insert(t);
		if (find(kmmin.begin(), kmmin.end(), t) != kmmin.end()) {
			if (t % 10 == 4) {
				while (t / 10)
					t /= 10;
				if (t == 4)
					arr[0]++;
				else
					arr[1]++;
			}
			else {
				while (t / 10)
					t /= 10;
				if (t == 4)
					arr[2]++;
				else
					arr[3]++;
			}
		}
	}
	
	Matrix m = fast(Matrix(arr[0], arr[2], arr[1], arr[3]), l - 1);
	cout << ((m.arr[0][0] * (arr[0] + arr[2])) % 1234567891 + (m.arr[0][1] * (arr[1] + arr[3])) % 1234567891 + (m.arr[1][0] * (arr[0] + arr[2])) % 1234567891 + (m.arr[1][1] * (arr[1] + arr[3])) % 1234567891) % 1234567891 << endl;
	
	
	return 0;
}
