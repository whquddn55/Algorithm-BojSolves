#include <bits/stdc++.h>
using namespace std;

int n;

void print(vector<bool>& visited,vector<int>& picked , int toPrint) {
    if (toPrint == n) {
        for (int element : picked)
            printf("%d ", element);
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == true)
            continue;

        visited[i] = true;
        picked.push_back(i);
        print(visited, picked, toPrint + 1);
        visited[i] = false;
        picked.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);

    vector<bool> visited(n + 1, false);
    vector<int> picked;

    print(visited, picked, 0);

    return 0;
}
