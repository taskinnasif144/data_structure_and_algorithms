#include <bits/stdc++.h>
using namespace std;

void func(int * &pointer)
{
    int y = 100;
    pointer = &y;
    cout << "In Func: " << pointer << endl;
}
int main()
{
    int x = 10;
    int *p = &x;
    func(p);
    cout << "In Main: " << p << endl;
    return 0;
}