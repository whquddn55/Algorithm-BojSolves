#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX = 303030;
const ll INF = 9e15;
const ll BASE = 256;
const ll MOD[2] = { 1'000'000'007,998'244'353 };
ll psum[MX][2], n, power[MX][2], ans[MX], chk[MX];
ll getHash(int i, int j, ll B1, ll B2) {
    ll ret[2];
    for (int k = 0; k < 2; k++) {
        if (k == 0) {
            ret[k] = ((psum[j][k] - psum[i - 1][k] + MOD[k]) % MOD[k] * B1) % MOD[k];
            ret[k] = ret[k] * power[n - i][k] % MOD[k]; // 적절한 power를 곱해 문자열 등장 위치를 보정한다.
        }
        else {
            ret[k] = ((psum[j][k] - psum[i - 1][k] + MOD[k]) % MOD[k] * B2) % MOD[k];
            ret[k] = ret[k] * power[n - i][k] % MOD[k]; // 적절한 power를 곱해 문자열 등장 위치를 보정한다.
        }
    }
    return ret[0] * MOD[1] + ret[1]; // 두 모듈로에서 얻은 해시값을 조합.
}
string s;
vector<int> get_sa(string str)
{
    int N = str.size();
    vector<int> group(N);
    int d;

    auto cmp = [&](int i, int j)
    {
        if (group[i] != group[j])
            return group[i] < group[j];

        i += d;
        j += d;

        if (i < N && j < N)
            return group[i] < group[j];
        else
            return i > j;
    };

    vector<int> sa(N);
    for (int i = 0; i != N; ++i)
    {
        sa[i] = i;
        group[i] = str[i];
    }

    vector<int> temp(N);
    for (d = 1;; d <<= 1)
    {
        sort(sa.begin(), sa.end(), cmp);

        fill(temp.begin(), temp.end(), 0);

        for (int i = 1; i != N; ++i)
            temp[i] = temp[i - 1] + cmp(sa[i - 1], sa[i]);

        for (int i = 0; i != N; ++i)
            group[sa[i]] = temp[i];

        if (temp[N - 1] == N - 1)
            break;
    }

    return sa;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    n = s.size();
    if (s.size() == 1) {
        cout << s[0] << endl;
        return 0;
    }
    vector<int> sa = get_sa(s);

    power[0][0] = power[0][1] = 1;  
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            power[j][i] = (power[j - 1][i] * BASE) % MOD[i];
            psum[j][i] = (psum[j - 1][i] + s[j - 1] * power[j][i]) % MOD[i];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        ans[i] = -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int ls = sa[i] + 1;
        int rs = sa[i + 1] + 1;
        if (ls > rs) {
            swap(ls, rs);
        }
        int l = 0, r = n - rs;
        ll B1 = power[rs - ls][0];
        ll B2 = power[rs - ls][1];
        while (l <= r)
        {
            int mid = (l + r) / 2; 
            if (getHash(ls, ls + mid, 1, 1) == getHash(rs, rs + mid, 1, 1))
            {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (ls + l <= n) {
            ans[ls - 1] = max(ans[ls - 1], (ll)l);
        }
        else {
            chk[ls - 1] = 1;
        }
        if (rs + l <= n) {
            ans[rs - 1] = max(ans[rs - 1], (ll)l);
        }
        else {
            chk[rs - 1] = 1;
        }
     
    }
    pair<int, int> ret = { 555555,0 };
    for (int i = 0; i < n; i++)
    {
        if(chk[i] != 1)
        ret = min(ret, { ans[i],i });
    }
    for (int i = ret.second; i < min((ret.second + ret.first + 1), (int)n); i++) {
        cout << s[i];
    }
}
