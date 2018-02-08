#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
pii result[101]; // first : 추천횟수, second : 들어온 우선순위

int main() {
	scanf("%d %d", &n, &k);
	
	int minValue = INF;
	int minIdx;
	int cnt = 0;
	for (int i = 0; i < k && cnt < n; i++) {
		int temp;
		scanf("%d", &temp);

		result[temp].first++;
		if (result[temp].first == 1) {
			result[temp].second = i;
			cnt++;
		}
		if (result[temp].first < minValue) {
			minValue = result[temp].first;
			minIdx = temp;
		}
	}

	for (int i = n; i < k; i++) {
		int temp;
		scanf("%d", &temp);

		if (result[temp].first) 
			result[temp].first++;
		else {
			result[minIdx].first = 0;
			result[temp].first++;
			result[temp].second = i;
		}

		minValue = INF;
		for (int j = 1; j <= 100; j++) {
			if (result[j].first == 0)
				continue;
			if (result[j].first < minValue) {
				minValue = result[j].first;
				minIdx = j;
			}
			else if (result[j].first == minValue) 
				if (result[j].second < result[minIdx].second) 
					minIdx = j;
				
		}
	}

	for (int i = 1; i <= 100; i++)
		if (result[i].first)
			printf("%d ", i);

	return 0;
}