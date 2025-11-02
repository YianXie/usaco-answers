#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("photo.in");
    ofstream fout("photo.out");

    fin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int b;
        fin >> b;
        numbers.push_back(b);
    }

    vector<int> ans;
    unordered_set<int> checked;
    checked.reserve(n);
    for (int i = 1; i <= n; i++) {
        checked.insert(i);
        ans.push_back(i);
        int prev = i;
        for (int j = 0; j < numbers.size() - 1; j++) {
            int diff = numbers[j] - prev;
            if (checked.count(diff) || diff > n || diff <= 0) {
                checked.clear();
                ans.clear();
                break;
            }
            prev = diff;
            checked.insert(diff);
            ans.push_back(diff);
        }
        if (checked.size() == n)
            break;
    }

    for (int i = 0; i < n; i++) {
        fout << ans[i];
        if (i != n - 1)
            fout << " ";
    }

    return 0;
}