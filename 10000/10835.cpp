#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<pii> cards;
int dp[2000][2000];

int getDp(int idx1, int idx2) {
	if (idx1 == n || idx2 == n)
		return 0;

	int &ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = max(getDp(idx1 + 1, idx2), getDp(idx1 + 1, idx2 + 1));
	if (cards[idx1].first > cards[idx2].second)
		ret = max(ret, getDp(idx1, idx2 + 1) + cards[idx2].second);

	return ret;
}

int main() {
	scanf("%d", &n);
	cards.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cards[i].first);
	for (int i = 0; i < n; i++)
		scanf("%d", &cards[i].second);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", getDp(0, 0));
	

	return 0;

}