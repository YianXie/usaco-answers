#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("blist.in");
    fin >> n;

    vector<int> ans(1001, 0);
    for (int i = 0; i < n; i++) {
        int s, t, b;
        fin >> s >> t >> b;
        for (int j = s; j <= t; j++) {
            ans[j] += b;
        }
    }

    ofstream fout("blist.out");
    fout << *max_element(ans.begin(), ans.end()) << "\n";

    return 0;
}