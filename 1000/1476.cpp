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

#define MAX_N 200001

int n;
int e, s, m;

pii extendedEuclid(int a, int b) {
	int s0 = 1, s1 = 0;
	int t0 = 0, t1 = 1;
	int r0 = a, r1 = b;
	int q = (r0 / r1);

	while (r1) {
		q = r0 / r1;
		int tr = r1, ts = s1, tt = t1;
		r1 = r0 - r1 * q;
		s1 = s0 - s1 * q;
		t1 = t0 - t1 * q;
		r0 = tr;
		s0 = ts;
		t0 = tt;
	}
	return { s0, t0 };
}

pii chinaRemain(vector<int> ak, vector<int> mk) {
	ll M = 1;
	for (auto e : mk)
		M *= e;

	vector<int> nk;
	for (auto e : mk)
		nk.push_back(M / e);

	vector<int> sk;
	for (int i = 0; i < nk.size(); i++)
		sk.push_back((extendedEuclid(nk[i], mk[i]).first + mk[i]) % mk[i]);

	ll ans = 0;
	for (int i = 0; i < nk.size(); i++)
		ans += sk[i] * nk[i] * ak[i];
	return { ans % M, M };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> e >> s >> m;
	int ans = chinaRemain({ e, s, m }, { 15, 28, 19 }).first;
	cout << ((ans == 0) ? 15 * 28 * 19 : ans) << endl;

	return 0;
}
