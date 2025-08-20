#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);

        string word;
        map<string, int> dict;
        pair<string, int> maxCount;
        while(ss >> word) {
            dict[word]++;
            if(dict[word] > maxCount.second){
                maxCount = {word, dict[word]};
            }
        }
        cout << maxCount.first << " " << maxCount.second << endl;
    }
    return 0;
}