#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

struct Score {
	int s[3];
	int sum = 0;
	int idx;

	bool operator<(const Score& other) {
		if (sum == other.sum) 
			if (s[0] == other.s[0]) 
				if (s[1] == other.s[1]) 
					return s[2] > other.s[2];
				else 
					return s[1] > other.s[1];
			else 
				return s[0] > other.s[0];
		else 
			return sum > other.sum;
	}
};

int n;
vector<Score> arr(3);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		arr[0].s[3 - t1]++;
		arr[0].sum += t1;
		arr[1].s[3 - t2]++;
		arr[1].sum += t2;
		arr[2].s[3 - t3]++;
		arr[2].sum += t3;
	}
	arr[0].idx = 1;
	arr[1].idx = 2;
	arr[2].idx = 3;
	sort(arr.begin(), arr.end());

	for (int i = 1; i < arr.size(); i++)
		if (arr[i].sum != arr[0].sum)
			arr.erase(arr.begin() + i);

	if (arr.size() == 1) {
		printf("%d %d\n", arr[0].idx, arr[0].sum);
		return 0;
	}

	for (int i = 1; i < arr.size(); i++)
		if (arr[i].s[0] != arr[0].s[0])
			arr.erase(arr.begin() + i);

	if (arr.size() == 1) {
		printf("%d %d\n", arr[0].idx, arr[0].sum);
		return 0;
	}

	for (int i = 1; i < arr.size(); i++)
		if (arr[i].s[1] != arr[0].s[1])
			arr.erase(arr.begin() + i);

	if (arr.size() == 1) {
		printf("%d %d\n", arr[0].idx, arr[0].sum);
		return 0;
	}

	printf("0 %d\n", arr[0].sum);

	return 0;
}