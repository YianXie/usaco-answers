#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("balancing.in");

    int n, b;
    fin >> n >> b;

    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        fin >> x >> y;
        cows[i] = { x, y };
    }

    int ans = INT_MAX;
    for (const auto& x : cows) {
        for (const auto& y : cows) {
            vector<int> tempAns(4, 0);
            for (const auto& c : cows) {
                const int xCoord = x.first + 1;
                const int yCoord = y.second + 1;
                if (c.first > xCoord && c.second > yCoord)
                    ++tempAns[0];
                else if (c.first < xCoord && c.second > yCoord)
                    ++tempAns[1];
                else if (c.first < xCoord && c.second < yCoord)
                    ++tempAns[2];
                else
                    ++tempAns[3];
            }
            ans = min(ans, *max_element(tempAns.begin(), tempAns.end()));
        }
    }

    ofstream fout("balancing.out");
    fout << ans << endl;

    return 0;
}