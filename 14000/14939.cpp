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

#define MAX_N 15
#define MOD 1000000007

bool arr[MAX_N][MAX_N];
int result = INF;

void put(int here) {
    if (here == 11) {
        int sum = 0;
        bool temp[MAX_N][MAX_N] = {0, };
        for (int i = 0; i <= 10; ++i)
            for (int j = 1; j <= 10; ++j)
                temp[i][j] = arr[i][j];
        for (int i = 0; i < 10; ++i)
            for (int j = 1; j <= 10; ++j) {
                if (arr[i][j]) {
                    arr[i][j] = !arr[i][j];
                    arr[i + 1][j] = !arr[i + 1][j];
                    arr[i + 1][j - 1] = !arr[i + 1][j - 1];
                    arr[i + 1][j + 1] = !arr[i + 1][j + 1];
                    arr[i + 2][j] = !arr[i + 2][j];
                    ++sum;
                }
            }
        for (int i = 0; i <= 10; ++i)
            for (int j = 1; j <= 10; ++j) {
                if (arr[i][j])
                    sum = INF;
                arr[i][j] = temp[i][j];
            }
        result = min(result, sum);
        return;
    }
    arr[0][here] = true;
    put(here + 1);
    arr[0][here] = false;
    put(here + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 1; i <= 10; ++i)
        for (int j = 1; j <= 10; ++j) {
            char t;
            cin >> t;
            if (t == 'O')
                arr[i][j] = true;
            else 
                arr[i][j] = false;
        }

    put(1);

    cout << result << endl;
    
	return 0;
}
