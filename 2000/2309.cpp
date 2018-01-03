#include <bits/stdc++.h>
using namespace std;

vector<int> picked;
vector<int> small;

void printPicked() {
    sort(picked.begin(), picked.end());
    for (int i = 0; i < 7; i++)
        cout << picked[i] << endl;
}

void pick(int toPick, int sum) {
    if (picked.size() == 7 && sum == 100) {
        printPicked();
        exit(0);
    }
    if (picked.size() > 7 || sum > 100 || toPick >= 9)
        return;

    pick(toPick + 1, sum);
    picked.push_back(small[toPick]);
    pick(toPick + 1, sum + small[toPick]);
    picked.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);

    small.resize(9);
    for (int i = 0; i < 9; i++)
        cin >> small[i];

    pick(0, 0);

    return 0;
}
