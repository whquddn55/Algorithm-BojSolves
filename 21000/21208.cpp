#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 303030;
int N, K;
map<string, pair<int,int> > ma;
struct info{
    string s;
    int cnt, idx;

    bool operator<(const info& other) {
        if (cnt != other.cnt) return cnt > other.cnt;
        return idx > other.idx;
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    string s;
    getline(cin,s);
    for (int i = 0; i < N * 3; i++) {
        getline(cin, s);
        if (ma.find(s) == ma.end()) 
        {
            ma[s] = { 1, i };
        }
        else 
        {
            int cnt = ma[s].first;
            int idx = ma[s].second;
            ma[s] = { cnt + 1, i };
        }
    }
    vector<info> v;
    for (auto it = ma.begin(); it != ma.end(); it++)
    {
        v.push_back({ it->first, it->second.first, it->second.second });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < min((int)v.size(), K); i++)
    {
        cout << v[i].s << "\n";
    }
}
