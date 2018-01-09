#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> rest;

// 휴게소 사이 거리를 mid미터 이하로 만들 수 있는가?
bool decision(int mid) {
	int cnt = (rest[0] - 1) / mid + (l - rest[n - 1] - 1) / mid;
	for (int i = 1; i < rest.size(); i++) 
		cnt += (rest[i] - rest[i - 1] - 1) / mid;
	
	return (cnt <= m);

	/*
	bool result = true;

	int lastVisitedRest = 0;
	int here = 0;
	int remainRest = m;
	while (remainRest >= 0 && here < l) {
		here++;
		for (int i = 0; i < n; i++)
			if (here == rest[i]) {
				lastVisitedRest = here;
				break;
			}

		if ((here - lastVisitedRest) == mid) {
			remainRest--;
			lastVisitedRest = here;
			continue;
		}
	}

	return (remainRest >= 0);*/
}

int binarySearch(int maxValue) {
	int left = 1, right = maxValue;
	while (left <= right) {
		int mid = (right + left) / 2;
		
		if (decision(mid)) 
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}

int main() {
	cin >> n >> m >> l;

	rest.resize(n);

	for (int i = 0; i < n; i++)
		cin >> rest[i];

	sort(rest.begin(), rest.end());
	int maxValue = max(rest[0], l - rest[n - 1]);
	for (int i = 1; i < n; i++)
		maxValue = max(maxValue, rest[i] - rest[i - 1]);

	cout << binarySearch(maxValue) << endl;

	return 0;
}