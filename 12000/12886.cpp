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
#define MAX_N 1505
#define MOD 1'000'000'007

bool bfs(int a, int b, int c) {
    int sum = a + b + c;
    bool visited[MAX_N][MAX_N] = { 0, };
    queue<pii> q;
    q.emplace(a, b);
    visited[a][b] = true;

    while(q.size()) {
        int hereA = q.front().first;
        int hereB = q.front().second;
        q.pop();


        if (hereA == hereB && sum - hereA - hereB == hereB) 
            return true;

        int hereC = sum - hereA - hereB;
        if (hereA < hereB) {
            if (!visited[hereA * 2][hereB - hereA]) {
                visited[hereA * 2][hereB - hereA] = true;
                q.emplace(hereA * 2, hereB - hereA);
            }
        } else {
            if (!visited[hereA - hereB][hereB * 2]) {
                visited[hereA - hereB][hereB * 2] = true;
                q.emplace(hereA - hereB, hereB * 2);
            }
        }

        if (hereB < hereC) {
            if (!visited[hereA][hereB * 2]) {
                visited[hereA][hereB * 2] = true;
                q.emplace(hereA, hereB * 2);
            }
        } else {
            if (!visited[hereA][hereB - hereC]) {
                visited[hereA][hereB - hereC] = true;
                q.emplace(hereA, hereB - hereC);
            }
        }

        if (hereA < hereC) {
            if (!visited[hereA * 2][hereB]) {
                visited[hereA * 2][hereB] = true;
                q.emplace(hereA * 2, hereB);
            }
        } else {
            if (!visited[hereA - hereC][hereB]) {
                visited[hereA - hereC][hereB] = true;
                q.emplace(hereA - hereC, hereB);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << bfs(a, b, c) << endl;

    return 0;
}
