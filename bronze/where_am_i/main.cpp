#include <bits/stdc++.h>
using namespace std;

int n;
string road;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    fin >> n;
    fin >> road;

    for (int i = 1; i <= n; ++i) {
        unordered_set<string> combinations;
        const int expected = n - i + 1;

        for (int j = 0; j < expected; ++j) {
            const string sub = road.substr(j, i);
            combinations.insert(sub);
        }

        if (combinations.size() == expected) {
            fout << i;
            break;
        }
    }

    return 0;
}