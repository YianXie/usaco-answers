#include <bits/stdc++.h>
using namespace std;

bool checkFor1(const vector<int>& seq, int l, int r)
{
    for (int i = l; i < r - 1; ++i)
        if (seq[i] != seq[i + 1])
            return false;
    return true;
}

bool checkFor2(const vector<int>& seq, int l, int r)
{
    if (checkFor1(seq, l, r))
        return true;

    vector<vector<int>> segments = { { seq[l] } };
    for (int i = l + 1; i < r; ++i) {
        if (seq[i] == segments[segments.size() - 1][0]) {
            segments[segments.size() - 1].push_back(seq[i]);
        } else {
            segments.push_back({ seq[i] });
        }
    }

    if (segments.size() % 2 == 0) {
        for (int i = 0; i < segments.size(); ++i)
            if (segments[i] != segments[i % 2])
                return false;
        return true;
    }
    return false;
}

bool checkFor3(const vector<int>& seq, int l, int r)
{
    int len = r - l;
    for (int blkLen = len; blkLen >= 1; blkLen--) {
        if (len % blkLen)
            continue;

        bool ok = true;
        for (int i = l; i < r - blkLen; i++)
            if (seq[i] != seq[i + blkLen]) {
                ok = false;
                break;
            }
        if (!ok)
            continue;

        for (int i = l; i <= l + blkLen; i++)
            if ((checkFor1(seq, l, i) && checkFor2(seq, i, l + blkLen)) || (checkFor2(seq, l, i) && checkFor1(seq, i, l + blkLen)))
                return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> seq(n);
        for (int i = 0; i < n; ++i) {
            cin >> seq[i];
        }

        switch (k) {
        case 1:
            cout << (checkFor1(seq, 0, n) ? "YES" : "NO") << endl;
            break;
        case 2:
            cout << (checkFor2(seq, 0, n) ? "YES" : "NO") << endl;
            break;
        case 3:
            cout << (checkFor3(seq, 0, n) ? "YES" : "NO") << endl;
            break;
        }
    }
}