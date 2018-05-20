#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_N 50001

struct Data {
	int height, area;
	bool isStart;
};

int n, volume;
Data arr[MAX_N * 2];
ll sum = 0;
int areaSum = 0;
int here;

bool comp(Data& a, Data& b) {
	return a.height < b.height;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout << fixed;
	cout.precision(2);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int b, h, w, d;
		cin >> b >> h >> w >> d;
		arr[i * 2] = { b, d * w, true };
		arr[i * 2 + 1] = { b + h, d * w, false };
	}
	cin >> volume;
	n *= 2;

	sort(arr, arr + n, comp);

	for (int i = 0; i < n - 1; i++) {
		if (arr[i].isStart)
			areaSum += arr[i].area;
		else
			areaSum -= arr[i].area;

		if (sum + areaSum * (arr[i + 1].height - arr[i].height) >= volume) {
			int remain = volume - sum;
			cout << arr[i].height + (double)remain / areaSum << endl;
			return 0;
		}
		else
			sum += areaSum * (arr[i + 1].height - arr[i].height);
	}
	cout << "OVERFLOW" << endl;

	return 0;
}