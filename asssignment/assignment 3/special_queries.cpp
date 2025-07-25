#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> queue;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int num;
        string name;
        cin >> num;
        if (num == 0)
            cin >> name;

        if (num == 0)
        {
            queue.push(name);
            continue;
        }

        if (num == 1 && queue.empty())
        {
            cout << "Invalid" << endl;
            continue;
        }
        if (num == 1 && !queue.empty())
        {
            cout << queue.front() << endl;
            queue.pop();
        }
    }
    return 0;
}