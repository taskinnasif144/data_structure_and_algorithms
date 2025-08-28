#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;
    int adj[N][N];
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i == j)
                adj[i][j] = 1;
    while(E--) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(adj[u][v])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    return 0;
}