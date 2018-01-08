#include <bits/stdc++.h>
using namespace std;

struct Data {
	int start;
	int end;

	bool operator<(const Data& other) {
		if (end == other.end)
			return start < other.start;
		return end < other.end;
	}
};

int main() {
	int n;
	cin >> n;

	vector<Data> times(n);
	for (int i = 0; i < n; i++) 
		cin >> times[i].start >> times[i].end;
	
	sort(times.begin(), times.end());

	int endTime = 0;
	int result = 0; 
	for (int i = 0; i < n; i++) {
		if (times[i].start < endTime)
			continue;

		result++;
		endTime = times[i].end;
	}

	cout << result << endl;


	return 0;
}