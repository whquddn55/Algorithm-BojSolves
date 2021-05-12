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

#define MAX_N 5005
#define MOD 1000000007

int n, w;
int arr[MAX_N];
vector<pii> v[800005];

bool comp(pii& a, pii& b) {
    return (a.first == b.first || a.first == b.second || a.second == b.first || a.second == b.second);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> w >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (v[arr[i] + arr[j]].size() < 2)
                v[arr[i] + arr[j]].emplace_back(i, j);
        }

    bool result = false;
    for (int i = 0; i <= w; ++i) {
        if (result)
            break;
        if (v[i].size() && v[w - i].size()) {
            for (pii& p1 : v[i])
                for(pii& p2 : v[w - i])
                    if (!comp(p1, p2))
                        result = true;
        }
    }

    cout << (result ? "YES" : "NO") << endl;

    

	return 0;
}
