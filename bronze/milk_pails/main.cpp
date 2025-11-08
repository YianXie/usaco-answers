#include <bits/stdc++.h>
using namespace std;

int x, y, m;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("pails.in");
    ofstream fout("pails.out");

    fin >> x >> y >> m;

    for (int i = 0; i <= m / x; i++) {
        for (int j = 0; j <= m / y; j++) {
            int temp = x * i + y * j;
            if (temp <= m)
                ans = max(ans, temp);
        }
    }

    fout << ans;

    return 0;
}