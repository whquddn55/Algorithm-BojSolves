#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)
#define MAX_N 10005

int n;
pii arr[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    double result = INF;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        double maxValue = 0;
        for (int j = 0; j < n ;++j)
            maxValue = max(maxValue, sqrt((arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second)));

        if (result > maxValue) {
            result = maxValue;
            index = i;
        }
    }

    cout << arr[index] << endl;
    
	return 0;
}
