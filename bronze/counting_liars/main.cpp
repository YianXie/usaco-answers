#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<char, long long>> cows(N);
    set<int> vals;
    for (int i = 0; i < N; ++i) {
        char t;
        long long p;
        cin >> t >> p;
        cows[i] = { t, p };
        vals.insert(p);
    }

    int ans = N; // upper bound
    for (long long x : vals) {
        int liars = 0;
        for (auto temp : cows) {
            char t = temp.first;
            long long p = temp.second;
            if (t == 'G') {
                if (p > x)
                    ++liars; // needs x >= p to be true
            } else { // 'L'
                if (p < x)
                    ++liars; // needs x <= p to be true
            }
        }
        ans = min(ans, liars);
    }
    cout << ans << "\n";
    return 0;
}
