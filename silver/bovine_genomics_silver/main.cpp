#include <bits/stdc++.h>
using namespace std;

bool have_intersection(const unordered_set<string>& set1, const unordered_set<string>& set2)
{
    for (const auto& element : set1) {
        if (set2.count(element) > 0) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("cownomics.in");

    int n, m;
    fin >> n >> m;

    vector<string> spotty(n);
    vector<string> plain(n);
    for (int i = 0; i < n * 2; ++i) {
        string gene;
        fin >> gene;
        i < n ? spotty[i] = gene : plain[i - n] = gene;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                unordered_set<string> spottyTriplets;
                unordered_set<string> plainTriplets;
                for (int l = 0; l < n * 2; ++l) {
                    string gene = "";
                    gene += l < n ? spotty[l].at(i) : plain[l - n].at(i);
                    gene += l < n ? spotty[l].at(j) : plain[l - n].at(j);
                    gene += l < n ? spotty[l].at(k) : plain[l - n].at(k);
                    l < n ? spottyTriplets.insert(gene) : plainTriplets.insert(gene);
                }
                ans += 1 - have_intersection(spottyTriplets, plainTriplets);
            }
        }
    }

    ofstream fout("cownomics.out");
    fout << ans << "\n";

    return 0;
}