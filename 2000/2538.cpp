#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename a, typename b>
ostream& operator<<(ostream& os, const pair<a, b>& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}
template<typename a, typename b>
istream& operator>>(istream& is, pair<a, b>& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 500005

int n, m;
int k;
pii arr[MAX_N];

int getBoundLength(pii s, pii e) {
    int result = 0;
    if (s.first == 0) {
        if (e.first == 0) {
            if (s.second < e.second) 
                result = s.second + n + m + n + (n - e.second);
            else 
                result = s.second - e.second;
        }
        else if (e.second == 0)
            result = s.second + e.first;
        else if (e.first == n) 
            result = s.second + n + e.second;
        else 
            result = s.second + n + m + n - e.first;
    }
    else if (s.second == 0) {
        if (e.second == 0) {
            if (s.first < e.first)
                result = e.first - s.first;
            else 
                result = (n - s.first) + m + n + m + e.first;
        }
        else if (e.first == n) 
            result = (n - s.first) + e.second;
        else if (e.second == m)
            result = (n - s.first) + m + (n - e.first);
        else 
            result = (n - s.first) + m + n + (m - e.second);
    }
    else if (s.first == n) {
        if (e.first == n) {
            if (s.second < e.second)
                result = e.second - s.second;
            else
                result = (m - s.second) + n + m + n + e.second;
        }
        else if (e.second == m) 
            result = (m - s.second) + (n - e.first);
        else if (e.first == 0)
            result = (m - s.second) + n + (m - e.second);
        else
            result = (m - s.second) + n + m + e.first;
    }
    else { // s.second == m
        if (e.second == m) {
            if (s.first < e.first)
                result = s.first + m + n + m + (n - e.first);
            else 
                result = s.first - e.first;
        }
        else if (e.first == 0)
            result = s.first + (m - e.second);
        else if (e.second == 0)
            result = s.first + m + e.first;
        else 
            result + s.first + m + n + e.second;
    }

    return result;
}

bool checkSameLine(pii a, pii b) {
    if (a.first == 0 && b.first == 0)
        return true;
    if (a.first == n && b.first == n)
        return true;
    if (a.second == 0 && b.second == 0)
        return true;
    if (a.second == m && b.second == m)
        return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
        cin >> arr[i];
    bool check = false;
    int offset = 0;
    for (int i = 0; i < k; ++i) {
        if (arr[i].first == 0 || arr[i].second == 0 || arr[i].first == n || arr[i].second == m) {
            check = true;
            offset = i;
        }
        else if (check)
            break;
    }

    arr[k] = arr[0];
    ++k;
    if (!check) {
        ll sum = (n + m) * 2;
        pii here = arr[0];
        for (int i = 1; i < k; ++i) {
            int dist = abs(here.first - arr[i].first) + abs(here.second - arr[i].second);
            sum += dist;
            here = arr[i];
        }
        cout << 1 << ' ' << sum << endl;
    }
    else {
        pii here = arr[offset];
        pii startPoint = here;
        bool flag = true;
        ll sum = 0;
        pll result = {0, 0};
        for (int j = 1; j < k; ++j) {
            int i = (j + offset) % k;
            if (checkSameLine(here, arr[i])) {
                startPoint = here = arr[i];
                continue;
            }
            int dist = abs(here.first - arr[i].first) + abs(here.second - arr[i].second);
            sum += dist;

            if (arr[i].first == 0 || arr[i].second == 0 || arr[i].first == n || arr[i].second == m) {
                ++result.first;
                result.second = max(result.second, sum + getBoundLength(startPoint, arr[i]));
                sum = 0;
                startPoint = arr[i];
            }

            here = arr[i];
        }
        cout << result << endl;
    }
	return 0;
}
