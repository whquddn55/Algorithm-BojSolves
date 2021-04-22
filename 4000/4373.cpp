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

#define MAX_N 1005

int n;
int arr[MAX_N];
pair<int, pii> arr1[MAX_N * MAX_N];
pair<int, pii> arr2[MAX_N * MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    while(true) {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int size = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                arr1[size] = {arr[i] + arr[j], pii{i, j}};
                arr2[size] = {arr[i] - arr[j], pii{i, j}};
                ++size;
            }
        sort(arr1, arr1 + size);
        sort(arr2, arr2 + size);

        int result = -INF;
        int l = 0, r = size - 1;
        while(l < r) {
            if (arr1[l].first + arr2[r].first == 0) {
                if (arr1[l].second.first == arr2[r].second.first || arr1[l].second.first == arr2[r].second.second ||
                    arr1[l].second.second == arr2[r].second.first || arr1[l].second.second == arr2[r].second.second) {
                        ++l;
                        --r;
                        continue;
                    }
                result = max(result, arr[arr2[r].second.second]);
                ++l;
                --r;
                if (arr1[l].second.first == arr2[r].second.first || arr1[l].second.first == arr2[r].second.second ||
                    arr1[l].second.second == arr2[r].second.first || arr1[l].second.second == arr2[r].second.second) {
                        ++l;
                        --r;
                    }
            }
            else if (arr1[l].first + arr2[r].first < 0) {
                ++l;
                if (arr1[l].second.first == arr2[r].second.first || arr1[l].second.first == arr2[r].second.second ||
                    arr1[l].second.second == arr2[r].second.first || arr1[l].second.second == arr2[r].second.second)
                        ++l;
            }
            else {
                --r;
                if (arr1[l].second.first == arr2[r].second.first || arr1[l].second.first == arr2[r].second.second ||
                    arr1[l].second.second == arr2[r].second.first || arr1[l].second.second == arr2[r].second.second)
                        --r;
            }
        }
        
        if (result == -INF)
            cout << "no solution" << endl;
        else
            cout << result << endl;
    }
    
	return 0;
}
