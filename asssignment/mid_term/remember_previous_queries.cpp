#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> lst;
    int q;
    cin >> q;
    while (q--)
    {
        int type, value;
        cin >> type >> value;
        if (type == 0)
        {
            lst.push_front(value);
        }

        if (type == 1)
        {
            lst.push_back(value);
        }

        if (type == 2)
        {
            if (value < static_cast<int>(lst.size()))
            {
                auto it = next(lst.begin(), value);
                lst.erase(it);
            }
        }
        cout << "L -> ";
        for (int val : lst)
        {
            cout << val << " ";
        }
        cout << endl;

        lst.reverse();
        cout << "R -> ";
        for (int val : lst)
        {
            cout << val << " ";
        }
        cout << endl;
        lst.reverse();
        
    }
    return 0;
}