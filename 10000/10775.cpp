#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 100000
using namespace std;

class NaiveDisjointSet{
private:
    vector<int> parent;
public:
    NaiveDisjointSet(int n)
        :parent(n) {
            for(int i = 0; i < n; i++)
                parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v)
            return;

        parent[u] = v;
    }

    void print() {
        for(int i = 0; i < parent.size(); i++)
            printf("%d : %d\n" , i, find(i));
        printf("\n");
    }
};

bool arr[MAXSIZE + 1];

int main() {
    int g, p;
    scanf("%d %d", &g, &p);

    
    NaiveDisjointSet set(g + 1);
    int result = 0;
    for(int i = 0; i < p; i++){
        int plane;
        scanf("%d", &plane);
        int parent = set.find(plane);
        if(!parent)
            break;
        set.merge(parent, parent - 1);
        result++;
    }

    printf("%d\n", result);

	return 0;
}

