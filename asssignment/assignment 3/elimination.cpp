#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        stack<char> stack;

        for (auto c : s)
        {
            if (stack.empty())
            {
                stack.push(c);
                continue;
            }

            if (stack.top() == '0' && c == '1')
            {
                stack.pop();
                continue;
            }
            // if (stack.top() == '1' && c == '0')
            // {
            //     stack.pop();
            //     continue;
            // }
            stack.push(c);
        }

        if (stack.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}