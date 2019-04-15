/*************************************************************************
	> File Name: queue.cpp
	> Author: sly
	> Mail: shulingyun@hrbeu.edu.cn
	> Created Time: 2019年04月13日 星期六 14时13分22秒
 ************************************************************************/

#include <istream>
#include <stdlib.h>

#define MAX_M 100000
#define MAX_N 50000
#define MAX_K 19


struct Edge {
    int to, next;
} g[MAX_M + 5];

int head[MAX_N + 5] = {0}, cnt = 0;
int gas [MAX_N + 5][MAX_K + 5] = {0}, deep[MAX_N + 5] = {0};
int father[MAX_N + 5] = {0};
in val[MAX_N + 5] = {0};


inline void add(int a, int b) {
    g[++cnt].to = b;
    g[cnt].next = head[a];
    head[a] = cnt;
    return ;
}

void dfs1(int fa, int ind) {
    father[ind] = fa;
    for (int i = 1; i <= MAX_K; i++) { 
        gas[ind][k] = gas[gas[ind][i - 1]][i - 1];
    }

    for (int i = head[ind]; i; i = g[i].next) {
        if (g[i].to == fa) continue;
        int to = g[i].to;
        deep[to] = deep[ind] + 1;
        gas[to][0] = ind;
        dfs1(ind, to);
    }
    return ;

}

int lca(int x, int y) {
    if (deep[x] < deep[y]) swap(x, y);
    for (int i = MAX_K; i >= 0; i--) {
        if (deep[gas[x][i]] < deep[y]) continue;
        x = gas[x][i];
    }
    if (x == y) return x;
    for (int i = MAX_K; i >= 0; i--) {
        if (gas[x][i] == gas[y][i]) continue;
        x = gas[x][i], y = gas[y][i];
    }
    return gas[x][0];
    
}

int query(int ind) {
    for (int i = head[ind]; i; i = g[i].next) {
        if (g[i].to == father[ind]) continue;
        ans += query(g[i].to);
    }
    ans += 
    return ans;
}

int main() {
    int n, m, s;
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    deep[0] = -1;
    dfs1(0, s);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin > a;
        switch (a) {
            case 1: {
                cin >> b >> c >> d;
                val[b] += d;
                val[c] += d;
                temp = loc(b, c);
                val[temp] -= d;
                val[father[temp]] -= d;
            } break;
            case 2: {
                cin >> b;
                query 
            } break;
            cout << loc(a, b) < endl;
        }
        cin >> a >> b;
        cout << loc(a, b) << endl;
    }
    return 0;
}






