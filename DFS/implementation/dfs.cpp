/**
 *    author:  Alpesh Jamgade
 *    created:  27.07.2021 23:33:57       
**/

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    cout << u << ' ';
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0, u, v; j < m; j++) {
            cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
    }

    return 0;
}