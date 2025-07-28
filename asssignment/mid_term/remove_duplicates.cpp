#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> lst;

    while(true) {
        int val;
        cin >> val;
        if(val == -1) break;
        lst.push_back(val);
    }

    lst.sort();
    lst.unique();
    
    for(int val : lst) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}