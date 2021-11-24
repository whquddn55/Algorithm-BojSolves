#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_N 2005
#define INF (INT_MAX / 2)
#define endl '\n'

int n;
int arr[MAX_N];
bitset<2000> bit[4][10];
bool c[10000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    bitset<2000> temp;
    temp.set(0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        int t = arr[i];
        for (int j = 0; j < 4; ++j) {
            bit[j][t % 10] |= temp;
            t /= 10;
        }
        temp <<= 1;
    }

    ll ans = 0;
    temp.reset();
    for (int z = 0; z < n; ++z)
        temp.set(z);
    for (int i = 0; i < n; ++i) 
        for (int j = i + 1; j < n; ++j) {
            int a = arr[i];
            int b = arr[j];
            bitset<2000> candi(temp);
            for (int k = 0; k < 4; ++k) {
                if (a % 10 == b % 10) {
                    candi &= bit[k][a % 10];
                } else {
                    bitset<2000> temp;
                    temp |= bit[k][a % 10];
                    temp |= bit[k][b % 10];
                    temp.flip();
                    candi &= temp;
                }
                a /= 10;
                b /= 10;
            }

            ans += candi.count();
        }

    cout << ans / 3 << endl;

    return 0;
}
