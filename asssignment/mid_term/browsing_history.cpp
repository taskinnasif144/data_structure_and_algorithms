#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> sites;
    while (true)
    {
        string val;
        cin >> val;
        if (val == "end")
            break;
        sites.push_back(val);
    }

    int q;
    cin >> q;
    list<string>::iterator it;
    while (q--)
    {
        string cmd;
        cin >> cmd;
        string site;
        if (cmd == "visit")
            cin >> site;

        if (cmd == "visit")
        {
            auto temp = find(sites.begin(), sites.end(), site);
            if (temp == sites.end())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                it = temp;
                cout << *it << endl;
            }
        }

        if (cmd == "prev")
        {
            if (it != sites.begin())
            {
                --it;
                cout << *it << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }

        if (cmd == "next")
        {
            if (it == sites.end())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                auto temp = it;
                ++temp;
                if (temp == sites.end())
                {
                    cout << "Not Available" << endl;
                }
                else
                {
                    ++it; 
                    cout << *it << endl;
                }
            }
        }
    }
    return 0;
}
