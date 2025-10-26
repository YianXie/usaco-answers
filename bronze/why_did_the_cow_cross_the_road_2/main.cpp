#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    string str;
    fin >> str;

    int ans = 0;
    map<char, set<char>> included;
    for (int i = 0; i < 26; ++i) {
        char c = static_cast<char>('A' + i);
        int start = distance(str.begin(), find(str.begin(), str.end(), c));
        int end = distance(str.begin(), find(str.begin() + start + 1, str.end(), c));

        multiset<char> occ;
        for (int j = start; j <= end; ++j) {
            occ.insert(str.at(j));
        }
        for (int j = 0; j < 26; ++j) {
            char tempC = static_cast<char>('A' + j);
            int count = occ.count(tempC);
            if (count == 1 && included[tempC].count(c) == 0) {
                included[c].insert(tempC);
                included[tempC].insert(c);
                ++ans;
            }
        }
    }

    fout << ans << endl;

    return 0;
}