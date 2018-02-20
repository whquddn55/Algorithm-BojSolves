#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<pii> arr;
vector<int> lis;
vector<pii> ans;

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.end());

	lis.push_back(arr[0].second);
	ans.push_back({ 0, arr[0].first });
	int lastIdx = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i].second > lis[lastIdx]) {
			lis.push_back(arr[i].second);
			lastIdx++;
			ans.push_back({ lastIdx, arr[i].first });
		}
		else {
			int idx = lower_bound(lis.begin(), lis.end(), arr[i].second) - lis.begin();
			lis[idx] = arr[i].second;
			ans.push_back({ idx, arr[i].first });
		}
	}

	stack<int> ret;
	for (int i = n - 1; i >= 0; i--) {
		if (ans[i].first == lastIdx) {
			
			lastIdx--;
		}
		else
		{ ret.push(ans[i].second);}
	}

	printf("%d\n", n - lis.size());
	while (!ret.empty()) {
		printf("%d\n", ret.top());
		ret.pop();
	}


	return 0;
}