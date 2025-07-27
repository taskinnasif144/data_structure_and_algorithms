#include <bits/stdc++.h>
using namespace std;
bool isSame(stack<int> A, queue<int> B)
{
    while (!A.empty() && !B.empty())
    {
        if (A.top() != B.front())
            return false;
        A.pop();
        B.pop();
    }

    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;
    int sizeN = N, sizeM = M;
    stack<int> stack;
    queue<int> queue;
    while (N--)
    {
        int val;
        cin >> val;
        stack.push(val);
    }
    while (M--)
    {
        int val;
        cin >> val;
        queue.push(val);
    }
    if (sizeN == sizeM)
    {
        if (isSame(stack, queue))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}