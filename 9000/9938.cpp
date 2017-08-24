#include <cstdio>
#include <vector>

#define INF 987654321
#define MAXSIZE 300000
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

bool isIn[MAXSIZE + 1];

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    NaiveDisjointSet set(l + 1);
    
    for(int i = 1; i <= n; i++){
        int a,  b;
        scanf("%d %d", &a, &b);

        if(!isIn[a]){
            isIn[a] = true;
            set.merge(a, b);
            printf("LADICA\n");
        }
        else if(!isIn[b]){
            isIn[b] = true;
            set.merge(b, a);
            printf("LADICA\n");
        }
        else if(!isIn[set.find(a)]){
            isIn[set.find(a)] = true;
            set.merge(a, b);
            printf("LADICA\n");
        }
        else if(!isIn[set.find(b)]){
            isIn[set.find(b)] = true;
            set.merge(b, a);
            printf("LADICA\n");
        }
        else
            printf("SMECE\n");
    }

	return 0;
}

