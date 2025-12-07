#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    int n;
    fin >> n;

    vector<int> original(n);
    for (int i = 0; i < n; ++i) {
        fin >> original[i];
    }

    vector<int> sorted = original;
    sort(sorted.begin(), sorted.end());

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        ans += sorted[i] != original[i];
    }

    fout << ans << "\n";
    return 0;
}