#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

double last;
double pos[3][2];

int main() {
	scanf("%lf", &last);
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf", &pos[i][0], &pos[i][1]);
		if (pos[i][0] > pos[i][1])
			swap(pos[i][0], pos[i][1]);
	}
	
	double front = 0;
	for (int i = 0; i < 3; i++) {
		if (pos[i][0] == pos[i][1])
			continue;
		double mid = (pos[i][0] + pos[i][1]) / 2.0;
		last = max(last, mid * 2 - front);
		front = mid;

		for (int j = i + 1; j < 3; j++) {
			if (pos[j][0] < mid)
				pos[j][0] += (mid - pos[j][0]) * 2;
			if (pos[j][1] < mid)
				pos[j][1] += (mid - pos[j][1]) * 2;
		}
	}
	printf("%.1lf\n", last - front);
	
	return 0;
}