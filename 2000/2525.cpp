#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int hour, minute;
	scanf("%d %d", &hour, &minute);
	int interval;
	scanf("%d", &interval);

	int result = hour * 60 + minute + interval;

	hour = (result / 60) % 24;
	minute = (result % 60);

	printf("%d %d\n", hour, minute);
	

	return 0;
}