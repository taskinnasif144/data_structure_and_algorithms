#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        auto end = unique(arr.begin(), arr.end());
        arr.erase(end, arr.end());

        for (int x : arr)
        {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}