#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E;
    vector<int> adj[N];

    while (E--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int node;
        cin >> node;

        sort(adj[node].begin(), adj[node].end(), greater<int>());

        if (adj[node].empty())
        {
            cout << -1;
        }
        else
        {
            for (int x : adj[node])
            {
                cout << x << " ";
            }
        }

        cout << endl;
    }
    return 0;
}