#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 500001

string str;
int t;
int sA[MAX_N]; // suffix array
int g[MAX_N]; // 현재 비교할 group
int tg[MAX_N]; // 다음에 비교할 group
int sAReverse[MAX_N]; // suffix array의 inverse
int lcp[MAX_N]; // lcp

bool cmp(int x, int y) {
	if (g[x] == g[y])
		return g[x + t] < g[y + t];
	return g[x] < g[y];
}

void getSA() {
	t = 1;
	for (int i = 0; i < str.size(); i++) {
		sA[i] = i;
		g[i] = str[i] - 'a';
	}

	while (t <= str.size()) {
		g[str.size()] = -1;
		sort(sA, sA + str.size(), cmp);

		tg[sA[0]] = 0;
		for (int i = 1; i < str.size(); i++) {
			if (cmp(sA[i - 1], sA[i]))
				tg[sA[i]] = tg[sA[i - 1]] + 1;
			else
				tg[sA[i]] = tg[sA[i - 1]];
		}

		for (int i = 0; i < str.size(); i++)
			g[i] = tg[i];
		t *= 2;
	}
}

void getLcp() {
	for (int i = 0; i < str.size(); i++)
		sAReverse[sA[i]] = i;
	int len = 0;
	for (int i = 0; i < str.size(); i++) {
		int k = sAReverse[i];
		if (k) {
			int j = sA[k - 1];
			while (str[j + len] == str[i + len])
				len++;
			lcp[k] = len;
			if (len)
				len--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> str;
	getSA();
	getLcp();
	for (int i = 0; i < str.size(); i++)
		cout << sA[i] + 1 << ' ';
	cout << endl;
	for (int i = 0; i < str.size(); i++)
		if (!i)
			cout << 'x' << ' ';
		else
			cout << lcp[i] << ' ';
	cout << endl;

	return 0;
}