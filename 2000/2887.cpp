#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 987654321
#define MAXSIZE 100000
using namespace std;

class NaiveDisjointSet {
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

vector<pair<int, int> > adj[MAXSIZE];

int kruskal(const int n){
    vector<pair<int, pair<int, int> > > edges;

    for(int i = 0; i < n; i++){
        int asize = adj[i].size();
        for(int j = 0; j < asize; j++) {
            int there = adj[i][j].first;
            int cost = adj[i][j].second;

            edges.push_back(make_pair(cost, make_pair(i, there)));
        }
    }
    sort(edges.begin(), edges.end());

    NaiveDisjointSet set(n);
    int esize = edges.size();
    int ret = 0;
    for(int i = 0; i < esize; i++){
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;

        if(set.find(u) == set.find(v))
            continue;
        
        set.merge(u, v);
        ret += cost;
    }
    return ret;
}


int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> posX;
    vector<pair<int, int>> posY;
    vector<pair<int, int>> posZ;
    for(int i = 0; i < n; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        posX.push_back(make_pair(x, i));
        posY.push_back(make_pair(y, i));
        posZ.push_back(make_pair(z, i));
    }

    sort(posX.begin(), posX.end());
    sort(posY.begin(), posY.end());
    sort(posZ.begin(), posZ.end());

    for(int i = 1; i < n; i++){
        adj[posX[i].second].push_back(make_pair(posX[i - 1].second, posX[i].first - posX[i - 1].first));
        adj[posX[i - 1].second].push_back(make_pair(posX[i].second, posX[i].first - posX[i - 1].first));
        adj[posY[i].second].push_back(make_pair(posY[i - 1].second, posY[i].first - posY[i - 1].first));
        adj[posY[i - 1].second].push_back(make_pair(posY[i].second, posY[i].first - posY[i - 1].first));
        adj[posZ[i].second].push_back(make_pair(posZ[i - 1].second, posZ[i].first - posZ[i - 1].first));
        adj[posZ[i - 1].second].push_back(make_pair(posZ[i].second, posZ[i].first - posZ[i - 1].first));
    }
    


    /*
    for(int i = 0; i < n; i++)
        printf("%d : %d\n", posX[i].second, posX[i].first);
        printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d : %d\n", posY[i].second, posY[i].first);
        printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d : %d\n", posZ[i].second, posZ[i].first);
        printf("\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++)
            printf("%d, %d\n", adj[i][j].first, adj[i][j].second);
        printf("\n");
    }*/

    printf("%d\n", kruskal(n));


	return 0;
}

