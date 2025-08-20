#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap;
    int arrSize;
    cin >> arrSize;
    while (arrSize--)
    {
        int val;
        cin >> val;
        pq.push(val);
    }
    int quaries;
    cin >> quaries;
    while (quaries--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top() << endl;
        }
        else if (q == 2)
        {
            if (!pq.empty())
                pq.pop();
            if (pq.empty())
                cout << "Empty" << endl;
            else
                cout << pq.top() << endl;
        }
        else if (q == 0)
        {
            int val;
            cin >> val;
            pq.push(val);
            cout << pq.top() << endl;
        }
    }
    return 0;
}