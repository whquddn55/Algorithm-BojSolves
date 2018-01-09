#include <bits/stdc++.h>
using namespace std;

vector<int> h;
int n;

typedef long long LL;

LL get(const int left, const int right) {
	if (left == right)
		return h[left];
	const int mid = (left + right) / 2;
	int l = mid, r = mid + 1;
	LL midResult = 0;
	
	bool b = true;
	int lowHeight = min(h[l], h[r]);
	while (true) {
		int width = (r - l) + 1;
		lowHeight = min({ lowHeight, h[l], h[r] });
		midResult = max(midResult, (LL)lowHeight * width);

		if (l > left && (r == right || h[l - 1] >= h[r + 1]))
			l--;
		else if (r < right && (l == left || h[l - 1] < h[r + 1]))
			r++;
		else
			break;
	}

	return max({ get(left, mid), get(mid + 1, right), midResult });
}

int main() {
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		h.clear();
		h.resize(n);
		for (int i = 0; i < n; i++)
			cin >> h[i];

		cout << get(0, n - 1) << endl;
	}

	return 0;
}