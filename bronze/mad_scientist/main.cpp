#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    int n;
    string a, b;
    fin >> n;
    fin >> a >> b;

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (b[i - 1] != a[i - 1] && b[i] == a[i]) {
            ans++;
        }
    }

    fout << ans << "\n";
    return 0;
}