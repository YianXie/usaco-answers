#include <bits/stdc++.h>
using namespace std;

int n, best, explodes;
vector<int> hales;
unordered_set<int> exploded;

void explode(int idx, int radius)
{
    explodes++;
    exploded.insert(idx);

    vector<int> willExplode;
    for (int i = 0; i < n; ++i) {
        if (abs(hales[i] - hales[idx]) <= radius && !exploded.count(i)) {
            exploded.insert(i);
            willExplode.push_back(i);
        }
    }
    for (const int& i : willExplode) {
        explode(i, radius + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("angry.in");
    ofstream fout("angry.out");

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        fin >> temp;
        hales.push_back(temp);
    }
    sort(hales.begin(), hales.end());

    for (int i = 0; i < n; ++i) {
        explode(i, 1);
        best = max(best, explodes);
        explodes = 0;
        exploded.clear();
    }

    fout << best << "\n";

    return 0;
}