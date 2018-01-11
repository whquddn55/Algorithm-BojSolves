#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> lessons;

// mid분으로 녹화해서 m개 이하로 가능한가?
bool decide(int mid) {
	int sum = 0;
	int cntBluelay = 1;
	for (int i = 0; i < n; i++) {
		sum += lessons[i];
		if (sum > mid) {
			sum = lessons[i];
			cntBluelay++;
			if (lessons[i] > mid) {
				cntBluelay += (lessons[i] / mid + 1);
				sum = 0;
			}
			
		}
	}

	return cntBluelay <= m;
}

int binarySearch(int minValue, int maxValue) {
	int left = minValue, right = maxValue;

	while (left <= right) {
		int mid = (left + right) / 2;
		//cout << left << ". " << right << ". " << mid << endl;
		if (decide(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}

	return left;
}

int main() {
	cin >> n >> m;
	lessons.resize(n);
	int minValue = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> lessons[i];
		minValue = min(minValue, lessons[i]);
	}
	
	cout << binarySearch(minValue, 1000000000) << endl;

	return 0;
}