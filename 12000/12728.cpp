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
#define MAX_N 51
#define MOD 1'000'000'007

struct Matrix {
    int arr[2][2];

    Matrix() {
        arr[0][0] = arr[0][1] = arr[1][0] =  arr[1][1] = 0;
    }

    Matrix(int a, int b, int c, int d)  {
        arr[0][0] = a; arr[0][1] = b; arr[1][0] = c; arr[1][1] = d;
    }

    void operator*=(const Matrix& a) {
        Matrix temp;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    temp.arr[i][j] += arr[i][k] * a.arr[k][j];

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                arr[i][j] = temp.arr[i][j] % 1000;
    }
};

Matrix mPow(Matrix& m, int t) {
    Matrix res(1, 0, 0, 1);
    while(t) {
        if (t % 2 == 1)
            res *= m;
        m *= m;
        t/= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int tc;
    cin >> tc;
    for (int ttcc = 1; ttcc <= tc; ++ttcc) {
        int n;
        cin >> n;

        Matrix m(6, -4, 1, 0);
        Matrix ansMatrix = mPow(m, n);

        int ans = (ansMatrix.arr[1][0] * 6 + ansMatrix.arr[1][1] * 2 - 1) % 1000;
        ans += 1000;
        ans %= 1000;


        cout << "Case #" << ttcc << ": "; 
        if (ans < 10) {
            cout << "00" << ans << endl;
        } else if (ans < 100) {
            cout << "0" << ans << endl;
        } else {
            cout << ans << endl;
        }
    }
    
    return 0;
}
