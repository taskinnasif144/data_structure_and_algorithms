#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edges;
    cin >> node >> edges;
    vector<pair<int, int>> edgeList;


    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        edgeList.push_back({a, b});
    }

    for(pair<int, int> edge: edgeList) {
        cout << edge.first << " - " << edge.second << endl;
    }
    return 0;
}