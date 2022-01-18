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
#define MAX_N 2048
#define MOD 1'000'000'007

int n;
bool res[MAX_N][MAX_N];
int width[11];
int height[11];

void get(int index, int hereY, int hereX) {
    if (index == 0)
        return;
        
    if (index % 2) {
        for (int i = 0; i < width[index]; ++i) {
            res[hereY + height[index] - 1][hereX + i] = true;
        }
        for (int i = 1; i < height[index]; ++i) {
            res[hereY + height[index] - 1 - i][hereX + i] = true;
            res[hereY + height[index] - 1 - i][hereX + width[index] - 1 - i] = true;
        }
        get(index - 1, hereY + height[index] / 2,  hereX + width[index] / 4 + 1);
    }
    else {
        for (int i = 0; i < width[index]; ++i) {
            res[hereY][hereX + i] = true;
        }
        for (int i = 1; i < height[index]; ++i) {
            res[hereY + i][hereX + i] = true;
            res[hereY + i][hereX + width[index] - 1 - i] = true;
        }
        get(index - 1, hereY + 1, hereX + width[index] / 4 + 1);
    }
    
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    width[1] = 1;
    height[1] = 1;
    for (int i = 2; i <= 10; ++i) {
        width[i] = width[i - 1] * 2 + 3;
        height[i] = height[i - 1] * 2 + 1;
    }
    get(n, 0, 0);

    int last[MAX_N];
    for (int i = 0; i < height[n]; ++i)
        for (int j = 0; j < width[n]; ++j)
            if (res[i][j])
                last[i] = j;

    for (int i = 0; i < height[n]; ++i,cout<<endl)
        for (int j = 0; j <= last[i]; ++j)
            cout << (res[i][j] ? '*' : ' ');

    return 0;
}
