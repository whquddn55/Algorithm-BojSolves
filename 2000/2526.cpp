#include <bits/stdc++.h>
using namespace std;
#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n, p;
vector<pair<bool, int> > arr;

int main() {
	scanf("%d %d", &n, &p);
	arr.resize(p, make_pair(false, 0));

	arr[n].first = true;
	arr[n].second = n;
	int here = n;
	int prev = n;
	while (true) {
		here = (here * n) % p;
		if (arr[here].first == true) {
			break;
		}
		arr[here].first = true;
		arr[here].second = prev;
		prev = here;
	}

	int result = 1;
	while (prev != here) {
		prev = arr[prev].second;
		result++;
	}
	
	printf("%d\n", result);
	

	return 0;
}