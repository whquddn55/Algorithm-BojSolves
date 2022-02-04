#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

#define all(x) x.begin(), x.end()
#define INF (INT_MAX / 2)
#define MAX_N 55
#define MOD 1'000'000'007

int n;
int arr[MAX_N];
vector<deque<int>> vdq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        bool inserted = false;
        for (auto& deq : vdq) {
            if (deq.back() < arr[i]) {
                bool canInsert = true;
                for (int j = i + 1; j < n; ++j) {
                    if (deq.back() < arr[j] && arr[j] < arr[i]) {
                        canInsert = false;
                    }
                }
                if (canInsert) {
                    deq.push_back(arr[i]);
                    inserted = true;
                }
            }
            else if (deq.front() > arr[i]) {
                bool canInsert = true;
                for (int j = i + 1; j < n; ++j) {
                    if (arr[i] < arr[j] && arr[j] < deq.back()) {
                        canInsert = false;
                    }
                }
                if (canInsert) {
                    deq.push_front(arr[i]);
                    inserted = true;
                }
            }
        }
        if (!inserted) {
            deque<int> newDeque;
            newDeque.push_back(arr[i]);
            vdq.emplace_back(newDeque);
        }
    }

    cout << vdq.size() << endl;

    return 0;
}
