#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("guess.in");
    ofstream fout("guess.out");

    int n;
    fin >> n;

    vector<set<string>> traits(n);
    for (int i = 0; i < n; ++i) {
        string a;
        int k;
        fin >> a >> k;
        while (k--) {
            string c;
            fin >> c;
            traits[i].insert(c);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int temp = 0;
            const auto traitA = traits[i];
            const auto traitB = traits[j];
            for (const auto t : (traitA.size() < traitB.size() ? traitA : traitB)) {
                if (traitB.count(t) && traitA.count(t))
                    ++temp;
            }
            ans = max(ans, temp);
        }
    }

    fout << ans + 1 << endl;

    return 0;
}