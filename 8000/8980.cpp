#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int> > boxes;

int main() {
    int n, c, m;
    cin >> n >> c >> m;

    boxes.resize(m);

    for (int i = 0 ; i < m; i++)
        cin >> boxes[i].first.second >> boxes[i].first.first >> boxes[i].second;

    sort(boxes.begin(), boxes.end());

    vector<int> truck(n + 1, 0);
    int arrived = 0;
    for (int i = 0; i < m; i++) {
        int plus = boxes[i].second;
        for (int j = boxes[i].first.second; j < boxes[i].first.first; j++)
            if ((boxes[i].second + truck[j] > c))
                plus = (plus < c - truck[j]) ? plus : (c - truck[j]);

        arrived += plus;
        for (int j = boxes[i].first.second; j < boxes[i].first.first; j++)
            truck[j] += plus;
    }

    cout << arrived << endl;


    return 0;
}

