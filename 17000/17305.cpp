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

#define MAX_N 250005

int n, w;
vector<int> arr1;
vector<int> arr2;
ll psum[MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> w;
    for (int i = 0; i < n; ++i)  {
        pii temp;
        cin >> temp;
        if (temp.first == 3)
            arr1.emplace_back(temp.second);
        else
            arr2.emplace_back(temp.second);
    }
    sort(arr1.begin(), arr1.end(), greater<int>());
    sort(arr2.begin(), arr2.end(), greater<int>());

    for (int i = 1; i <= arr2.size(); ++i)   
        psum[i] = psum[i - 1] + arr2[i - 1];
    
    ll sum = 0;
    ll result = psum[min(w / 5, (int)arr2.size())];
    for (int i = 0; i < arr1.size(); ++i) {
        if ((i + 1) * 3 > w)
            break;
        sum += arr1[i];
        result = max(result, sum + psum[min((w - (i + 1) * 3) / 5 , (int)arr2.size())]);
    }
    cout << result << endl;
    
	return 0;
}
