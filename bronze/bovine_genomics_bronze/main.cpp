#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int n, m;
    fin >> n >> m;

    vector<string> genes(n * 2);
    for (int i = 0; i < n * 2; ++i) {
        string gene;
        fin >> gene;
        genes[i] = gene;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        set<char> contains;
        for (int j = 0; j < n; ++j) {
            contains.insert(genes[j].at(i));
        }

        bool noReapeat = true;
        for (char c : contains) {
            for (int j = n; j < n * 2; ++j) {
                if (genes[j].at(i) == c) {
                    noReapeat = false;
                    break;
                }
            }
        }
        ans += noReapeat;
    }

    fout << ans << endl;

    return 0;
}