#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
string s;
string ioi;

void makeioi() {
	for (int i = 0; i < n; i++) {
		ioi.push_back('I');
		ioi.push_back('O');
	}
	ioi.push_back('I');
}

vector<int> getPi() {
	int m = (int)ioi.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i< m; i++) {
		while (j > 0 && ioi[i] != ioi[j])
			j = pi[j - 1];
		if (ioi[i] == ioi[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp() {
	vector<int> ans;
	auto pi = getPi();
	int n = (int)s.size(), m = (int)ioi.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j>0 && s[i] != ioi[j])
			j = pi[j - 1];
		if (s[i] == ioi[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d %d", &n, &m);
	cin >> s;
	makeioi();
	auto matched = kmp();
	printf("%d\n", (int)matched.size());
	return 0;
}