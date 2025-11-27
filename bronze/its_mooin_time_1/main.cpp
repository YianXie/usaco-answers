#include <bits/stdc++.h>
using namespace std;

int n, f;
string moos;
unordered_map<string, set<int>> validMoos;
set<string> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> f;
    cin >> moos;

    for (int i = 0; i < n - 2; ++i) {
        const string sub = moos.substr(i, 3);
        if (sub[1] == sub[2] && sub[0] != sub[1]) {
            validMoos[sub].insert(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        string copy = moos;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            copy[i] = ch;
            for (int j = -2; j <= 0; ++j) {
                const string sub = copy.substr(max(i + j, 0), 3);
                if (ans.count(sub) || validMoos[sub].size() < f - 1 || sub.size() != 3)
                    continue;
                if (sub[1] != sub[2] || sub[0] == sub[1])
                    continue;

                set<int> init = validMoos[sub];
                if (init.size() >= f) {
                    ans.insert(sub);
                    continue;
                }
                if (init.count(i - 2) || init.count(i - 1) || init.count(i) || init.count(i + 1) || init.count(i + 2))
                    continue;

                ans.insert(sub);
            }
        }
    }

    cout << ans.size() << endl;
    for (const string& s : ans) {
        cout << s << endl;
    }

    return 0;
}