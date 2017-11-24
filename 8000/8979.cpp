#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Medal {
    int gold, silver, bronze;

    bool operator<(Medal& other) {
        if (gold == other.gold) {
            if (silver == other.silver)
                return bronze > other.bronze;
            return silver > other.silver;
        }
        return gold > other.gold;
    }
};

vector<Medal> medals;

int main() {
    int n, k;
    cin >> n >> k;

    medals.resize(n);
    int gold, silver, bronze;
    for (int i = 0 ; i < n ;i++) {
        int t;
        cin >> t;
        cin >> medals[i].gold >> medals[i].silver >> medals[i].bronze;

        if (t == k){
            gold = medals[i].gold;
            silver = medals[i].silver;
            bronze = medals[i].bronze;
        }
    }

    sort(medals.begin(), medals.end());

    int rank = 0;
    for (int i = 0; i < n; i++) {
        if (medals[i].gold == gold && medals[i].silver == silver && medals[i].bronze == bronze) {
            rank = i + 1;
            break;
        }
    }

    cout << rank << endl;
    return 0;
}
