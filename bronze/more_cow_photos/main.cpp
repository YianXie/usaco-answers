#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        set<int, greater<int>> cows;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            cows.insert(temp);
            freq[temp]++;
        }

        int ans = 1;
        bool firstTime = true;
        for (const int& i : cows) {
            if (firstTime) {
                firstTime = false;
                continue;
            }
            if (freq[i] >= 2)
                ans += 2;
        }
        cout << ans << endl;
    }

    return 0;
}