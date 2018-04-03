#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)
#define endl '\n'

#define MAX_SIZE 51

int n, s;
pii arr[MAX_SIZE]; // first : 실제 값, second : 크기 순위(낮을수록 크다)
pii arr2[MAX_SIZE]; // first : 실제 값, second : arr배열의 index

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> arr[i].first;
		cin >> s;

		for (int i = 0; i < n; i++)
			arr2[i] = { arr[i].first, i };
		sort(arr2, arr2 + n, greater<pii>());
		
		for (int i = 0; i < n; i++)
			arr[arr2[i].second].second = i;

		int front = 0;
		while (s) {
			for (int i = front; i < n; i++) {
				int idx;
				for (int j = front; j < n; j++)
					if (arr[j].first == arr2[i].first) {
						idx = j;
						break;
					}
				if ((idx - front) <= s) {
					for (int i = idx; i > front; i--)
						swap(arr[i], arr[i - 1]);
					swap(arr2[i], arr2[front]);
					s -= (idx - front);
					front++;
					break;
				}
			}
			if (front == n)
				break;
		}
		for (int i = 0; i < n; i++)
			cout << arr[i].first << ' ';
		cout << endl;
	}

	return 0;
}
