#include <bits/stdc++.h>

using namespace std;

const int INF = 123;
int n, k, cnt;
set<int> tap;
int arr[INF];

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	for (int i = 0; i < k; i++) {
		if (tap.size() < n) {
			tap.insert(arr[i]);
			continue;
		}
		if (tap.count(arr[i]))
			continue;

		int value;
		int maxIndex = -1;
		for (auto e : tap) {
			bool updated = false;
			for (int j = i + 1; j < k; j++) {
				if (e == arr[j]) {
					if (maxIndex < j) {
						maxIndex = j;
						value = e;
					}
					updated = true;
					break;
				}
			}
			if (!updated) {
				value = e;
				break;
			}
		}
		tap.erase(value);
		tap.insert(arr[i]);
		cnt++;
	}

	cout << cnt << '\n';
}