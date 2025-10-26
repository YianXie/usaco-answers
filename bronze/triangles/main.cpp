#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int n;
    fin >> n;

    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        fin >> x >> y;
        coords[i] = { x, y };
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = coords[i].first;
        int y = coords[i].second;

        int maxY = 0;
        for (int j = 0; j < n; ++j) {
            if (coords[j].first == x && j != i)
                maxY = max(abs(coords[j].second - y), maxY);
        }

        int maxX = 0;
        for (int j = 0; j < n; ++j) {
            if (coords[j].second == y && j != i)
                maxX = max(abs(coords[j].first - x), maxX);
        }
        ans = max(ans, maxX * maxY);
    }

    fout << ans << endl;

    return 0;
}