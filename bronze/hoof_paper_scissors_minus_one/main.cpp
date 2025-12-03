#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> signs(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < i; ++j) {
            if (s[j] == 'D')
                continue;
            if (s[j] == 'W')
                signs[i][j] = 1;
            else
                signs[j][i] = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        pair<int, int> input;
        cin >> input.first >> input.second;

        int valids = 0;
        for (const auto& v : signs) {
            if (v[input.first - 1] && v[input.second - 1]) {
                valids++;
            }
        }

        if (!valids) {
            cout << 0 << endl;
        } else {
            int ans = 0;
            for (int i = 0; i < valids; ++i) {
                ans += n * 2 - i * 2 - 1;
            }
            cout << ans << endl;
        }
    }

    return 0;
}