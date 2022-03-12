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
#define MOD2 1'000'000'009

char arr[10][10];
int py[] = {0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4};
int px[] = {4, 1, 3, 5, 7, 2, 6, 1, 3, 5, 7, 4};
bool placed[27] = {false, };

bool get(int index) {
    if (index == 12) {
        bool res = true;
        res &= (arr[py[1]][px[1]] + arr[py[2]][px[2]] + arr[py[3]][px[3]] + arr[py[4]][px[4]] - 'A' * 4) == 22;
        res &= (arr[py[1]][px[1]] + arr[py[5]][px[5]] + arr[py[8]][px[8]] + arr[py[11]][px[11]] - 'A' * 4) == 22;
        res &= (arr[py[4]][px[4]] + arr[py[6]][px[6]] + arr[py[9]][px[9]] + arr[py[11]][px[11]] - 'A' * 4) == 22;

        res &= (arr[py[0]][px[0]] + arr[py[2]][px[2]] + arr[py[5]][px[5]] + arr[py[7]][px[7]] - 'A' * 4) == 22;
        res &= (arr[py[0]][px[0]] + arr[py[3]][px[3]] + arr[py[6]][px[6]] + arr[py[10]][px[10]] - 'A' * 4) == 22;
        res &= (arr[py[7]][px[7]] + arr[py[8]][px[8]] + arr[py[9]][px[9]] + arr[py[10]][px[10]] - 'A' * 4) == 22;

        if (res == true) {
            for (int i = 0; i < 5; ++i, cout<<endl) {
                for (int j = 0; j < 9; ++j) {
                    cout << arr[i][j];
                }
            }
        }

        return res;
    }
   
    
    if (arr[py[index]][px[index]] != 'x'){ 
        return get(index + 1);
    }
    else {
        for (int i = 'A'; i <= 'L'; ++i) {
            if (placed[i - 'A']) { 
                continue;
            }
            placed[i - 'A'] = true;
            arr[py[index]][px[index]] = i;

            bool res = get(index + 1);
            if (res == true) {
                return true;
            }
            placed[i - 'A'] = false;
            arr[py[index]][px[index]] = 'x';

        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 9; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] != '.' && arr[i][j] != 'x') {
                placed[arr[i][j] - 'A'] = true;
            }
        }
    
    get(0);
    
    return 0;
}