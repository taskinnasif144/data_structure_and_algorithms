#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b)
{
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main()
{
    int t;
    cin >> t;
    vector<pair<string, int>> v;
    while (t--)
    {
        string name;
        int val;
        cin >> name >> val;
        v.push_back({name, val});
        
    }
    
    sort(v.begin(), v.end(), comp);
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    
    }
    return 0;
}