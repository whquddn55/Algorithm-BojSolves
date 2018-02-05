#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> arr;

bool comp(const pii& a, const pii& b) {
	return (a.first == b.first) ? (a.second < b.second) : (a.first > b.first);
}

int calcDay(int m, int d) {
	int here = 1;
	int result = 0;
	while (here < m) {
		switch (here) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			result += 31;
			break;
		case 2:
			result += 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			result += 30;
			break;
		}

		here++;
	}

	return result + d;
}

int main() {
	scanf("%d", &n);
	bool check1 = false;
	bool check2 = false;
	for (int i = 0; i < n; i++) {
		int m1, d1, m2, d2;
		scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
		int v1 = calcDay(m1, d1);
		int v2 = calcDay(m2, d2);
		if (v2 <= 60 || v1 >= 335)
			continue;
		
		arr.emplace_back(v2, v1);
		if (v2 >= 335)
			check1 = true;
		if (v1 <= 60)
			check2 = true;
	}

	if (!check1 || !check2) {
		printf("0\n");
		return 0;
	}
	sort(arr.begin(), arr.end(), comp);
    
	int i = 0;
	int value = INF;
	while (true) {
		if (arr[i].first < 335)
			break;
		
		value = min(value, arr[i].second);
		i++;
	}

	int result = 1;
	vector<pii>::iterator it1 = arr.begin() + i;
	while (true) {
		if (it1->second <= 60) 
			break;

		vector<pii>::iterator minIt = lower_bound(arr.begin(), arr.end(), pii(value, 0), greater<pii>()) - 1;

		for (vector<pii>::iterator it2 = minIt; it1 != it2; --it2)
			if (it2->second < minIt->second)
				minIt = it2;
		value = minIt->second;
		result++;
		it1 = minIt;
	}
	printf("%d\n", result);
	
	return 0;
}