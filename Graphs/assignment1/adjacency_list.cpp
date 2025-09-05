#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edges;
    cin >> node >> edges;
    vector<int> adjList[node];


    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a); // for undirected matrix add this
    }

    for (int i = 0; i < node; i++)
    {   
        cout << i << " --> " ;
        for(int x : adjList[i]){
            cout << x << ", ";
        }
        cout << endl;
    }

    return 0;
}