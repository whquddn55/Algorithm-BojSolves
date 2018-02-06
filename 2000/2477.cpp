#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int k;
vector<pii> arr(6);
vector<int> cnt(5);

int main() {
	scanf("%d", &k);
	for (int i = 0; i < 6; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		cnt[arr[i].first]++;
	}
	
	int result = 1;
	for (int i = 1; i < 5; i++)
		if (cnt[i] == 1)
			for (int j = 0; j < 6; j++)
				if (arr[j].first == i) {
					result *= arr[j].second;
					break;
				}

	int temp = 0;
	int idx = 0;
	while (true) {
		if (temp == 0) {
			if (cnt[arr[idx].first] == 1)
				temp++;
		}
		else if (temp == 1) {
			if (cnt[arr[idx].first] == 1)
				temp++;
		}
		else if (temp == 2) {
			if (cnt[arr[idx].first] == 2) {
				result -= (arr[(idx + 1) % 6].second * arr[(idx + 2) % 6].second);
				break;
			}
		}

		idx = (idx + 1) % 6;
	}

	printf("%d\n", result * k);


	return 0;
}