#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream& os, const pii& pai) {
	os << pai.first << ' ' << pai.second;
	return os;
}

istream& operator>>(istream& is, pii& pai) {
	is >> pai.first >> pai.second;
	return is;
}

#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

#define INF (INT_MAX / 2)

#define MAX_N 100005

int n, k;
pii arr[MAX_N];
vector<int> result;

priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
stack<int> poppedK;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    if (n <= k) {
        for (int i = 0; i < n; ++i)
            pq.emplace(pii(arr[i].second, -i), i);
        while(pq.size()) {
            result.push_back(arr[pq.top().second].first);
            pq.pop();
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i)
            sum += (ll)result[i] * (i + 1);
        cout << sum << endl;
    }
    else {
        for (int i = 0; i < k; ++i)
            pq.emplace(pii(arr[i].second, -i), i);
        
        int time = 0;
        for (int i = k; i < n; ++i) {
            if(pq.size() < k) {
                pq.emplace(pii(time + arr[i].second, poppedK.top()), i);
                poppedK.pop();
            }
            else {
                time = pq.top().first.first;
                poppedK.push(pq.top().first.second);
                result.push_back(arr[pq.top().second].first);
                pq.pop();
                while(pq.size() && pq.top().first.first == time) {
                    poppedK.push(pq.top().first.second);
                    result.push_back(arr[pq.top().second].first);
                    pq.pop();
                }
                pq.emplace(pii(time + arr[i].second, poppedK.top()), i);
                poppedK.pop();
            }
        }
        while(pq.size()) {
            result.push_back(arr[pq.top().second].first);
            pq.pop();
        }

        ll sum = 0;
        for (int i = 0; i < n; ++i)
            sum += (ll)result[i] * (i + 1);
        cout << sum << endl;
    }
    
	return 0;
}
